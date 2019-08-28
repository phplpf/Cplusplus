// 定义消息
#define  WM_MYMESSAGE  WM_USER + 1001
#include <windows.h>
#include <stdio.h>
HINSTANCE g_hInstance = 0;
void OnCreate( HWND hWnd ){
	// 发送自定义消息  自定义消息的发送可以在任意位置( 窗口创建成功之后)
	// 既可以使用SendMessage，也可以使用PostMessage
//	SendMessage( hWnd, WM_MYMESSAGE, 100, 200 );
	PostMessage( hWnd, WM_MYMESSAGE, 100, 200 );
}
// 处理自定义消息
void OnMyMessage( HWND hWnd, WPARAM wParam, LPARAM lParam){
	char szText[256] = { 0 };
	sprintf( szText," 自定义消息被处理: wParam:%d, lParam:%d \n",wParam,lParam);
	MessageBox( hWnd,szText,"Infor",MB_OK);
}
// 2. 窗口处理函数
LRESULT CALLBACK WndProc(HWND hWnd,UINT msgID,
	WPARAM wParam, LPARAM lParam){
	switch(msgID){
	case WM_MYMESSAGE:
		OnMyMessage( hWnd, wParam, lParam);
		break;
	case WM_CREATE:
		OnCreate( hWnd );
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
		g_hInstance = hInstance;
		Register( "Main", WndProc);
		HWND hWnd = CreateMain( "Main", "Window" );
		Display( hWnd );
		Message();
		return 0;
}