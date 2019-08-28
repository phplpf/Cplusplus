#include <windows.h>
#include <stdio.h>
HINSTANCE g_hInstance = 0;
HANDLE g_hOutput = 0;  // 接收标准输出句柄
HWND g_hEdit = 0;   // 编辑框窗口句柄
/*void OnCreate( HWND hWnd, LPARAM lParam)
{
	CREATESTRUCT* pcs = (CREATESTRUCT*)lParam;
	char* pszText =(char*) pcs->lpCreateParams;
	MessageBox( hWnd, pszText, "Infor", MB_OK );
}*/
void OnCreate( HWND hWnd)
{
	g_hEdit = CreateWindowEx( 0, "EDIT", "Hello", WS_CHILD | WS_VISIBLE | WS_BORDER,
		0,0,200,200, hWnd, NULL, g_hInstance, NULL);
}
void OnSize( HWND hWnd, LPARAM lParam)
{
	WORD nWidth = LOWORD( lParam );
	WORD nHeight = HIWORD( lParam );

	MoveWindow( g_hEdit, 0, 0, nWidth, nHeight, TRUE );

	char szText[256] = {0};
	sprintf( szText, "WM_SIZE --- 宽：%d,高:%d\n", nWidth, nHeight );
	WriteConsole( g_hOutput, szText, strlen(szText), NULL, NULL );
}
// 2. 窗口处理函数
LRESULT CALLBACK WndProc(HWND hWnd,UINT msgID,
	WPARAM wParam, LPARAM lParam)
{
	switch(msgID)
	{
	case WM_SIZE:
		OnSize( hWnd, lParam );
		break;
	case WM_CREATE:
//		OnCreate( hWnd, lParam );
		OnCreate( hWnd );
		break;
	case WM_SYSCOMMAND:
//		return 0;
//		MessageBox( hWnd, "WM_SYSCOMMAND", "Infor", 
//			MB_OK | MB_ICONINFORMATION );
		if( wParam == SC_CLOSE){
			int nRet = MessageBox( hWnd, "是否退出?", "Infor",
				        MB_YESNO | MB_ICONINFORMATION);
			if( nRet == IDYES ){
				// 什么也不写
			}else{
				return 0;
			}
		}
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
	char * pszText = "Hello Data";
	HWND hWnd = CreateWindowEx( 0, lpClassName, lpWndName,
		WS_OVERLAPPEDWINDOW, 200, 200, 500, 400,
		NULL, NULL, g_hInstance, pszText );
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
/*	while( GetMessage( &nMsg, NULL, 0, 0 ) ){
		TranslateMessage( &nMsg );
		DispatchMessage( &nMsg );
	}*/

	while(1){
		if(PeekMessage(&nMsg, NULL, 0, 0, PM_NOREMOVE ))
		{
			// 有消息
			if( GetMessage( &nMsg, NULL, 0, 0)) // 不是 WM_QUIT
			{
				 TranslateMessage( &nMsg );
				 DispatchMessage( &nMsg );
			}else{ // WM_QUIT
				return;
			}
		}else{ // 没有消息
			// 空闲处理
			WriteConsole( g_hOutput, "OnIdle", 6, NULL,NULL);
		}
	}

}
// 1. 定义WinMain函数
int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPrevIns,
	LPSTR lpCmdLine,int nCmdShow){
		AllocConsole();  // 增加一个DOS窗口
		g_hOutput = GetStdHandle( STD_OUTPUT_HANDLE );
		g_hInstance = hInstance;
		Register( "Main", WndProc);
		HWND hWnd = CreateMain( "Main", "Window" );
		Display( hWnd );
		Message();
		return 0;
}