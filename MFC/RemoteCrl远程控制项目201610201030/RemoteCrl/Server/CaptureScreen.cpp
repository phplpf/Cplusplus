// CaptureScreen.cpp: implementation of the CaptureScreen.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CaptureScreen.h"

//////////////////////////////////////////////////////////////////////
LPSTR lpBmpData=NULL;
DWORD dwBmpSize=0;
DWORD dwBmpInfoSize=0;
int   CaptureThreadCount=0;//抓屏线程数，目前没有使用
CRITICAL_SECTION csCaptureScreen;
int	  iBmpCX;
int   iBmpCY;
////////////////////////////////////////
//进行扫尾工作,释放内存，在服务线程函数ServerThread中使用
void CleanScreenInfo(void)
{
	if(lpBmpData)
	{
		GlobalUnlock(lpBmpData);
		lpBmpData=(char*)GlobalFree(lpBmpData);
	}
	dwBmpSize=0;
	dwBmpInfoSize=0;
}

//捕捉屏幕数据
bool GetScreenData(int nBits)
{
	//位图位数不能为大于2^24的值,主要考虑到传输特性
	if (nBits>24)
		return false;
	HDC		hScrDC, hMemDC;			// 屏幕和内存设备描述表
	HBITMAP		hBitmap, hOldBitmap;		// 位图句柄
	int		xScrn, yScrn;			// 屏幕分辨率 

	HDC		hDC;				//设备描述表
	WORD		wBitCount;			//位图中每个像素所占字节数

	//定义调色板大小， 位图中像素字节大小 ，位图文件大小 ， 写入文件字节数
	DWORD		dwPaletteSize=0, dwBmBitsSize=0;//,dwBmpInfoSize=0;
	BITMAP		Bitmap;			//位图属性结构
	BITMAPINFOHEADER	bi;		//位图信息头结构 
	LPBITMAPINFOHEADER	lpbi;		//指向位图信息头结构

	//定义文件，分配内存句柄，调色板句柄  
	HANDLE			hDib;
	HPALETTE		hPal,hOldPal=NULL;

	//为屏幕创建设备描述表
	hScrDC = CreateDC("DISPLAY", NULL, NULL, NULL);
	// 获得屏幕分辨率
	xScrn = GetDeviceCaps(hScrDC, HORZRES);
	yScrn = GetDeviceCaps(hScrDC, VERTRES);
	//为屏幕设备描述表创建兼容的内存设备描述表
	hMemDC = CreateCompatibleDC(hScrDC);
	// 创建一个与屏幕设备描述表兼容的位图
	hBitmap = CreateCompatibleBitmap (hScrDC,xScrn,yScrn);
	// 把新位图选到内存设备描述表中
	hOldBitmap = (HBITMAP) SelectObject(hMemDC, hBitmap);
	// 把屏幕设备描述表拷贝到内存设备描述表中
	BitBlt(hMemDC, 0, 0, xScrn, yScrn, 
			hScrDC, 0, 0, SRCCOPY);
	//得到屏幕位图的句柄
	hBitmap = (HBITMAP) SelectObject(hMemDC, hOldBitmap);


	//计算位图每个像素所占字节数
	if (nBits <= 1)
		wBitCount = 1;
	else if (nBits <= 4)
		wBitCount = 4;
	else if (nBits <= 8)
		wBitCount = 8;
	else if (nBits <= 16)
		wBitCount = 16;
	else if (nBits <= 24)
		wBitCount = 24;
	//计算调色板大小
	if (wBitCount <24)
		dwPaletteSize = (1 << wBitCount) * sizeof(RGBQUAD);

	//设置位图信息头结构
	GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&Bitmap);
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = Bitmap.bmWidth;
	bi.biHeight = Bitmap.bmHeight;
	bi.biPlanes = 1;
	bi.biBitCount = wBitCount;
	bi.biCompression = BI_RGB;
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;
	dwBmBitsSize = ((Bitmap.bmWidth * wBitCount+31)& ~31)/8 *Bitmap.bmHeight;
	dwBmpInfoSize = dwPaletteSize + sizeof(BITMAPINFOHEADER);
	//临时位图数据大小变量
	DWORD dwNewBmpSize;
	dwNewBmpSize = dwBmBitsSize + dwBmpInfoSize;
	iBmpCX=Bitmap.bmWidth;
	iBmpCY=Bitmap.bmHeight;
	//为位图内容分配内存
	if(dwNewBmpSize!=dwBmpSize)//位图相关信息没有变化
	{
		if(!lpBmpData)
		{
			hDib  = GlobalAlloc(GHND,dwNewBmpSize);
			if(!hDib)
			{
				DeleteObject(hBitmap);
				DeleteDC(hScrDC);
				DeleteDC(hMemDC);
				dwBmpSize=0;
				dwBmpInfoSize=0;
				return false;
			}
		}
		else
		{
			GlobalUnlock(lpBmpData);
			lpBmpData=(char*)GlobalFree(lpBmpData);
			hDib  = GlobalAlloc(GHND,dwNewBmpSize);
			if(!hDib)
			{
				DeleteObject(hBitmap);
				DeleteDC(hScrDC);
				DeleteDC(hMemDC);
				dwBmpSize=0;
				dwBmpInfoSize=0;
				return false;
			}
		}
		lpbi = (LPBITMAPINFOHEADER)GlobalLock(hDib);
		*lpbi = bi;
	}
	else//位图相关信息没有变化
	{
		lpbi = (LPBITMAPINFOHEADER)lpBmpData;
		*lpbi = bi;
	}

	// 处理调色板   
	hPal = (HPALETTE) GetStockObject(DEFAULT_PALETTE);
	if (hPal)
	{
		hDC = GetDC (NULL);
		hOldPal = SelectPalette(hDC, hPal, FALSE);
		RealizePalette(hDC);
	}
	// 获取该调色板下新的像素值
	GetDIBits(
			hDC,
			hBitmap,
			0, 
			(UINT) Bitmap.bmHeight,
			(LPSTR)lpbi + sizeof(BITMAPINFOHEADER) + dwPaletteSize,
			(BITMAPINFO *)lpbi,
			DIB_RGB_COLORS
		  );
	//恢复调色板
	if (hOldPal)
	{
		SelectPalette(hScrDC, hOldPal, TRUE);
		RealizePalette(hScrDC);
		ReleaseDC(NULL, hDC);
	}

	lpBmpData = (char *)lpbi;
	dwBmpSize = dwNewBmpSize;
	//清除
	DeleteObject (hBitmap);
	DeleteDC(hScrDC);
	DeleteDC(hMemDC);
	return TRUE;

/*	BITMAPINFOHEADER	bi;		//位图信息头结构
	HBITMAP hBitmap;
	
	LPBITMAPINFOHEADER	lpbi = NULL;		//指向位图信息头结构 
	HDC		hScrDC, hMemDC;			// 屏幕和内存设备描述表
	HBITMAP		 hOldBitmap;		// 位图句柄
	int		xScrn, yScrn;			// 屏幕分辨率 
	BITMAP		Bitmap;			//位图属性结构
	
	//为屏幕创建设备描述表
	hScrDC = CreateDC("DISPLAY", NULL, NULL, NULL);
	
	// 获得屏幕分辨率
	xScrn = GetDeviceCaps(hScrDC, HORZRES);
	yScrn = GetDeviceCaps(hScrDC, VERTRES);
	
	//为屏幕设备描述表创建兼容的内存设备描述表
	hMemDC = CreateCompatibleDC(hScrDC);
	// 创建一个与屏幕设备描述表兼容的位图
	hBitmap = ::CreateCompatibleBitmap (hScrDC,xScrn,yScrn);

	
	
	// 把新位图选到内存设备描述表中
	hOldBitmap = (HBITMAP) SelectObject(hMemDC, hBitmap);
	// 把屏幕设备描述表拷贝到内存设备描述表中
	BitBlt(hMemDC, 0, 0, xScrn, yScrn, hScrDC, 0, 0, SRCCOPY);
	
	//得到屏幕位图的句柄
	hBitmap = (HBITMAP) SelectObject(hMemDC, hOldBitmap);
	
	//设置位图信息头结构
	GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&Bitmap);
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = Bitmap.bmWidth;
	bi.biHeight = Bitmap.bmHeight;
	bi.biPlanes = 1;//目标设备的级别必须为1?????????????????????????
	bi.biBitCount = 24;//每个点的颜色值用多少位保存
	bi.biCompression = BI_RGB; //压缩方式 0不压缩 1-RLE8压缩 2-RLE4压缩 3-每个像素点的值按掩码决定
	bi.biSizeImage = Bitmap.bmWidth*Bitmap.bmHeight*24;//((Bitmap.bmWidth * 24+31)& ~31)/8 *Bitmap.bmHeight;
	bi.biXPelsPerMeter = 0; //水平分辨率
	bi.biYPelsPerMeter = 0; //垂直分辨率
	bi.biClrUsed = 0;//位图实际使用的颜色表中的颜色数
	bi.biClrImportant = 0;//所有颜色都重要

	//临时位图数据大小变量
	DWORD dwNewBmpSize;
	dwNewBmpSize = bi.biSizeImage/8 + 40;

	iBmpCX=Bitmap.bmWidth;
	iBmpCY=Bitmap.bmHeight;

	lpbi = (LPBITMAPINFOHEADER)malloc( bi.biSizeImage/8+40 );
	memset( lpbi, 0, bi.biSizeImage/8+40 );
	
	*lpbi = bi;
	
	
	GetDIBits(hMemDC, hBitmap, 0, (UINT) Bitmap.bmHeight, (LPSTR)lpbi+sizeof(BITMAPINFOHEADER),
		(BITMAPINFO *)lpbi, DIB_RGB_COLORS);
	   
	lpBmpData =(char*)lpbi;
	dwBmpSize = dwNewBmpSize;
	//清除
	DeleteObject (hBitmap);
	DeleteDC(hMemDC);

	return TRUE;*/
}