#pragma once

///////////抓屏的全局变量//////////////
extern LPSTR lpBmpData;	//位图数据指针
extern int   CaptureThreadCount ;//抓屏线程数
extern DWORD dwBmpSize;	//位图数据大小
extern DWORD dwBmpInfoSize;	//位图信息
extern CRITICAL_SECTION csCaptureScreen;//用户捕获屏幕数据的临界区变量
extern int	 iBmpCX;//位图宽度
extern int   iBmpCY;//位图高度
///////////////////////////////////////
void CleanScreenInfo(void);
bool GetScreenData(int nBits);