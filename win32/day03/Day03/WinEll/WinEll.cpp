#define ELL_D 60
#include <windows.h>
HINSTANCE g_hInstance = 0;
int g_xPos = 100, g_yPos = 100;
BOOL LEFT_RIGHT = FALSE;
BOOL TOP_BOTTOM = FALSE;
void OnPaint( HWND hWnd )
{
	PAINTSTRUCT ps = {0};
	HDC hdc = BeginPaint( hWnd, &ps );
	Ellipse( hdc, g_xPos, g_yPos, g_xPos + ELL_D, g_yPos + ELL_D );
	EndPaint( hWnd, &ps );
}
void OnTimer( HWND hWnd, WPARAM wParam)
{
	RECT rcClient = {0};
	GetClientRect( hWnd, &rcClient);
	if( g_xPos <= rcClient.left )
		LEFT_RIGHT = TRUE;
	if( g_yPos <= rcClient.top)
		TOP_BOTTOM = TRUE;
	if( g_xPos >= rcClient.right - ELL_D )
		LEFT_RIGHT = FALSE;
	if ( g_yPos >= rcClient.bottom - ELL_D )
		TOP_BOTTOM = FALSE;
	if( LEFT_RIGHT)
		g_xPos++;
	else
		g_xPos--;
	if( TOP_BOTTOM )
		g_yPos++;
	else
		g_yPos--;
	InvalidateRect( hWnd, NULL, FALSE );
} 
// 2. 窗口处理函数
LRESULT CALLBACK WndProc(HWND hWnd,UINT msgID,
	WPARAM wParam, LPARAM lParam)
{
	switch(msgID)
	{
	case WM_TIMER:
		OnTimer( hWnd, wParam );
		break;
	case WM_CREATE:
		SetTimer( hWnd, 1001, 20, NULL );
		break;
	case WM_PAINT:
		OnPaint( hWnd );
		break;
	case WM_DESTROY:
		PostQuitMessage( 0 );   // GetMessage返回0 
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
	wndCls.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
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