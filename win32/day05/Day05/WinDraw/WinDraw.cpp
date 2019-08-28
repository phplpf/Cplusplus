#include <windows.h>
#include "resource.h"
HINSTANCE g_hInstance = 0;
void DrawLine( HDC hdc ){
	MoveToEx( hdc, 100, 100, NULL );
	LineTo( hdc, 300, 300 );
	LineTo( hdc, 100, 300 );
	LineTo ( hdc, 100, 100 );
}
void DrawRect( HDC hdc )
{
	Rectangle( hdc,100, 100, 300, 300 );
	RoundRect( hdc, 300, 100, 600,300, 50, 50 );
}
void DrawEll( HDC hdc )
{
	Ellipse( hdc, 100, 100, 300, 300 );
	Ellipse( hdc, 300, 100, 600, 300 );
}
void DrawArc( HDC hdc ){
	Rectangle( hdc, 100, 100, 300, 300 );
	Arc( hdc, 100, 100, 300, 300, 200, 50, 50, 200 );
}
void DrawGrph( HDC hdc ){
	// 创建画笔和画刷
	HPEN  hPenDash = CreatePen( PS_DASH, 1, RGB( 60, 70, 200 ));
	HPEN hPenSolid = CreatePen( PS_SOLID, 5, RGB( 128, 0, 128 ));
	HBRUSH hBrush = CreateSolidBrush( RGB( 200, 190, 230 ));
	// 将画笔和画刷应用到DC中
	HGDIOBJ hOldPen = SelectObject( hdc, hPenDash );
	HGDIOBJ hOldBrush = SelectObject( hdc, hBrush );
	// 绘图
	Rectangle( hdc, 200, 100, 500, 300 );
	Ellipse( hdc, 200, 100, 500, 300 );
	MoveToEx( hdc, 350, 50, NULL );
	LineTo( hdc, 350, 200 );
	LineTo( hdc, 150, 200 );
	// 换成第二个画笔
	SelectObject( hdc, hPenSolid);
	Arc( hdc, 200, 100, 500, 300, 350, 50, 150, 200 );
	// 从DC中取出绘图对象
	SelectObject( hdc, hOldBrush );
	SelectObject( hdc, hOldPen );
	// 释放绘图对象
	DeleteObject( hPenDash );
	DeleteObject( hPenSolid );
	DeleteObject( hBrush );
}
void OnPaint( HWND hWnd ){
	PAINTSTRUCT ps = {0};
	HDC hdc = BeginPaint( hWnd, &ps );

	// 绘制位图
	// 1. 添加位图资源 ( 不需要写代码 )
	// 2. 加载位图
	HBITMAP hBmp =  LoadBitmap( g_hInstance, ( LPCSTR )IDB_BITMAP2 );
	// 3. 创建一个和当前DC匹配的内存DC
	//  同时在内存中构建一个虚拟区域，内存DC对应这块虚拟区域
	/*
	   创建一个内存DC的内核结构，同时申请一块内存，内存DC维护这块内存
	   申请的内存空间的大小和当前DC维护的显存大小相同
	   当前DC维护的显存空间的大小由窗口大小决定
	*/
	HDC hMemDC = CreateCompatibleDC( hdc );
	// 4. 将位图放入内存DC中，内存DC立即将位图的图像在虚拟区域中绘制
	/*  将位图数据存入内存DC维护的那块内存中 */
	HGDIOBJ hOldBmp =  SelectObject( hMemDC, hBmp );
	// 5. 绘图 ( 成像 )
	/*
	   将内存DC维护的那块内存中的数据，
	   以拷贝内存的方式一次性放入当前DC维护的显存中
	*/
	BITMAP bmpInfo = {0};
	GetObject( hBmp, sizeof(bmpInfo), &bmpInfo );

	BitBlt( hdc, 100, 100, bmpInfo.bmWidth, bmpInfo.bmHeight, hMemDC, 0, 0, SRCCOPY );

	StretchBlt( hdc, 100, 200, bmpInfo.bmWidth*2, bmpInfo.bmHeight*2, hMemDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, NOTSRCCOPY );

	// 6. 从内存DC中取出位图
	SelectObject( hMemDC, hOldBmp );
	// 7. 释放位图
	DeleteObject( hBmp );
	// 8. 释放DC
	DeleteDC( hMemDC );

//	DrawGrph( hdc );

/*
	// 1. 创建画笔
	HPEN hPen = CreatePen( PS_DASH, 1, RGB( 240,0,0) );
	// 2. 将画笔应用到DC中
	HGDIOBJ hOldPen =  SelectObject( hdc, hPen );

	// 创建画刷
//	HBRUSH hBrush = CreateSolidBrush( RGB( 200, 220, 220 ));
//	HBRUSH hBrush = CreateHatchBrush( HS_DIAGCROSS, RGB( 200, 220, 220 ));
	HGDIOBJ hBrush = GetStockObject( NULL_BRUSH );
	// 将画刷应用到DC中
	HGDIOBJ hOldBrush =  SelectObject( hdc, hBrush );
	// 3. 绘图
//	DrawLine( hdc );   // 绘制直线
//	DrawRect( hdc );  // 绘制矩形
	DrawEll( hdc );      // 绘制椭圆
//	DrawArc( hdc );
	// 从DC中取出画刷
	SelectObject( hdc, hOldBrush );
	// 释放画刷
//	DeleteObject( hBrush );

	// 4. 从DC中取出画笔
	SelectObject( hdc, hOldPen );
	// 5. 释放画笔
	DeleteObject( hPen );
*/

	EndPaint( hWnd, &ps );
}
// 2. 窗口处理函数
LRESULT CALLBACK WndProc(HWND hWnd,UINT msgID,
	WPARAM wParam, LPARAM lParam)
{
	switch(msgID)
	{
	case WM_PAINT:
		OnPaint( hWnd );
		break;
	case WM_DESTROY:
		PostQuitMessage( 0 );   // GetMessage返回0 ?
		break;
	}
	return DefWindowProc( hWnd, msgID, wParam, lParam);
}
// 3. 注册窗口类
void Register( LPSTR  lpClassName, WNDPROC wndProc )
{
	WNDCLASS wndCls = {0};
	wndCls.cbClsExtra = 0;
	wndCls.cbWndExtra = 0;
	wndCls.hbrBackground = CreateSolidBrush( RGB(220, 200, 220) );
	wndCls.hCursor = NULL;
	wndCls.hIcon = NULL;
	wndCls.hInstance = g_hInstance;
	wndCls.lpfnWndProc = wndProc;
	wndCls.lpszClassName = lpClassName;
	wndCls.lpszMenuName = NULL;
	wndCls.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndCls);
}
// 4. 创建窗口
HWND CreateMain( LPSTR lpClassName, LPSTR lpWndName){
	HWND hWnd = CreateWindowEx( 0, lpClassName, lpWndName,
		WS_OVERLAPPEDWINDOW, 100, 100, 700, 500,
		NULL, NULL, g_hInstance, NULL );
	return hWnd;
}
// 5. 显示窗口
void Display( HWND hWnd ){
	ShowWindow( hWnd, SW_SHOW );
	UpdateWindow( hWnd );
}
// 6. 消息循环
void Message(){
	MSG nMsg = {0};
	while( GetMessage( &nMsg, NULL, 0, 0 ) ){
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );
	}
}
// 1. 定义WinMain函数
int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPrevIns,
	LPSTR lpCmdLine,int nCmdShow){
		g_hInstance = hInstance;
		Register( "Main", WndProc);
		HWND hWnd = CreateMain( "Main", "Window" );
		Display( hWnd );
		Message();
		return 0;
}