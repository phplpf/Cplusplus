#include <windows.h>
#include <stdio.h>
HINSTANCE g_hInstance = 0;
HANDLE g_hOutput = 0;
void OnTimer( HWND hWnd, WPARAM wParam )
{
	char szText[256] = {0};
	sprintf( szText, " 窗口处理函数处理了定时器: %d\n", wParam);
	WriteConsole( g_hOutput, szText, strlen( szText ), NULL, NULL );
}
// 定时器处理函数
VOID CALLBACK TimerProc(  HWND hwnd, UINT uMsg, 
	      UINT_PTR idEvent, DWORD dwTime){
	char szText[256] = {0};
	sprintf(szText,"定时器处理函数处理了定时器: %d\n", idEvent );
	WriteConsole( g_hOutput, szText, strlen(szText), NULL, NULL );
}

// 2. 窗口处理函数
LRESULT CALLBACK WndProc(HWND hWnd,UINT msgID,
	WPARAM wParam, LPARAM lParam)
{
	switch(msgID)
	{
	case WM_LBUTTONDOWN:
		KillTimer( hWnd, 1001 );
		KillTimer( hWnd, 1002 );
		break;
	case WM_TIMER:
		OnTimer( hWnd, wParam );
		break;
	case WM_CREATE:
		SetTimer( hWnd, 1001, 1000, NULL );
		SetTimer( hWnd, 1002, 2000, TimerProc );
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
		AllocConsole();
		g_hOutput = GetStdHandle( STD_OUTPUT_HANDLE );
		g_hInstance = hInstance;
		Register( "Main", WndProc);
		HWND hWnd = CreateMain( "Main", "Window" );
		Display( hWnd );
		Message();
		return 0;
}