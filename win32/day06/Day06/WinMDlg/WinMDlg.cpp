#include <windows.h>
#include "resource.h"
HINSTANCE g_hInstance = 0;
// 1. 定义对话框处理函数
INT CALLBACK DlgProc( HWND hWndDlg, UINT msgID, 
	     WPARAM wParam, LPARAM lParam )
{
	switch( msgID)
	{
	case WM_INITDIALOG:
		MessageBox(hWndDlg,"WM_INITDIALOG","Infor",MB_OK);
		break;
	case WM_CREATE:   // 对话框在创建成功显示之前没有WM_CREATE消息产生
		MessageBox( hWndDlg, "WM_CREATE","Infor",MB_OK);
		break;
	case WM_SYSCOMMAND:
		if( wParam == SC_CLOSE )
			EndDialog( hWndDlg, 1001 );  // 3. 关闭模式对话框
//			DestroyWindow( hWndDlg );
		break;
	}
	return FALSE;  // 将消息交给真正的对话框处理函数的后续代码处理
}
// 2. 创建模式对话框
void OnModal( HWND hWnd )
{
	INT nRet = DialogBox( g_hInstance, (LPCSTR)IDD_DIALOG1, hWnd, DlgProc );
    if( nRet == 1001 )
		MessageBox( hWnd, "成功!", "Infor", MB_OK );
}
void OnCommand( HWND hWnd, WPARAM wParam )
{
	switch( LOWORD(wParam) )
	{
	case ID_MODAL:
		OnModal(hWnd);  
		break;
	}
}
// 2. 窗口处理函数
LRESULT CALLBACK WndProc(HWND hWnd,UINT msgID,
	WPARAM wParam, LPARAM lParam)
{
	switch(msgID)
	{
	case WM_COMMAND:
		OnCommand( hWnd, wParam );
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
	wndCls.lpszMenuName = (LPCSTR) IDR_MENU1;
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