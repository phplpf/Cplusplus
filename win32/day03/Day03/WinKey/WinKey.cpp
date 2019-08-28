#include <windows.h>
#include <stdio.h>
HINSTANCE g_hInstance = 0;
HANDLE g_hOutput = 0; 
int g_xPos = 100,g_yPos = 100;
void OnPaint( HWND hWnd){
	PAINTSTRUCT ps = {0};
	HDC hdc = BeginPaint( hWnd, &ps );
	TextOut( hdc,  g_xPos, g_yPos, "Hello", 5 );
	EndPaint( hWnd, &ps );
}
void OnKeyDown( HWND hWnd,WPARAM wParam)
{
	switch ( wParam ){
	case VK_LEFT :    g_xPos--;   break;
	case VK_UP:        g_yPos--;   break;
	case VK_RIGHT:  g_xPos++; break;
	case VK_DOWN: g_yPos++; break;
	}
	InvalidateRect( hWnd, NULL, TRUE );
	char szText[256] = {0};
	sprintf( szText, "WM_KEYDOWN: %08X\n", wParam);
	WriteConsole( g_hOutput, szText, strlen(szText), NULL, NULL);
}
void OnKeyUp( HWND hWnd, WPARAM wParam )
{
	char szText[256] = {0};
	sprintf( szText,"WM_KEYUP: %08X\n",wParam );
	WriteConsole( g_hOutput, szText, strlen( szText ),NULL, NULL );
}
void OnChar( HWND hWnd,  WPARAM wParam )
{
	char szText[256] = {0};
	sprintf( szText, "WM_CHAR: %08X\n", wParam );
	WriteConsole( g_hOutput, szText, strlen( szText ), NULL, NULL );
}
// 2. 窗口处理函数
LRESULT CALLBACK WndProc(HWND hWnd,UINT msgID,
	WPARAM wParam, LPARAM lParam)
{
	switch(msgID)
	{
	case WM_CHAR:
		OnChar( hWnd, wParam );
		break;
	case WM_PAINT:
		OnPaint( hWnd);
		break;
	case WM_KEYUP:
		OnKeyUp( hWnd, wParam );
		break;
	case WM_KEYDOWN:
		OnKeyDown( hWnd, wParam );
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