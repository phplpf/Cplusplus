#define IDC_BTN_PUSHBUTTON				40001
#define IDC_BTN_DEFPUSHBUTTON			40002
#define IDC_BTN_GROUPBOX					40003
#define IDC_BTN_CHECKBOX						40004
#define IDC_BTN_AUTORADIOBUTTON1 40005
#define IDC_BTN_AUTORADIOBUTTON2 40006
#define IDC_BTN_AUTORADIOBUTTON3 40007
#define IDC_BTN_AUTORADIOBUTTON4 40008
#define IDC_EDIT_SINGLELINE					40009
#define IDC_EDIT_MULTILINE						40010
#define IDC_EDIT_PASSWORD					40011
#define IDC_EDIT_READONLY					40012
#include <windows.h>
HINSTANCE g_hInstance = 0;
int x = 10, y = 10;
void OnCreate( HWND hWnd )
{
	CreateWindowEx(0,"BUTTON","Push Button",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_NOTIFY,x,y,150,24,hWnd,
		(HMENU)IDC_BTN_PUSHBUTTON,g_hInstance,NULL);
	CreateWindowEx(0,"BUTTON","Def Push Button",
		WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | BS_NOTIFY,
		x,y+=30,150,24,hWnd, (HMENU)IDC_BTN_DEFPUSHBUTTON,g_hInstance,NULL);
	
	CreateWindowEx(0,"BUTTON","GroupBox",
		WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
		x,y+=30,150,64,hWnd,(HMENU)IDC_BTN_GROUPBOX,g_hInstance,NULL);

	CreateWindowEx(0,"BUTTON","Check Box",
		WS_CHILD | WS_VISIBLE | BS_CHECKBOX,
		x,y+=70,150,24,hWnd,(HMENU)IDC_BTN_CHECKBOX,g_hInstance,NULL);

	CreateWindowEx(0,"BUTTON","Radio Button1",
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
		x,y+=30,150,24,hWnd,(HMENU)IDC_BTN_AUTORADIOBUTTON1,g_hInstance,NULL);
	CreateWindowEx(0,"BUTTON","Radio Button2",
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		x,y+=30,150,24,hWnd,(HMENU)IDC_BTN_AUTORADIOBUTTON2,g_hInstance,NULL);
	CreateWindowEx(0,"BUTTON","Radio Button3",
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP,
		x,y+=30,150,24,hWnd,(HMENU)IDC_BTN_AUTORADIOBUTTON3,g_hInstance,NULL);
	CreateWindowEx(0,"BUTTON","Radio Button4",
		WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
		x,y+=30,150,24,hWnd,(HMENU)IDC_BTN_AUTORADIOBUTTON4,g_hInstance,NULL);

    CreateWindowEx(0,"EDIT","",
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
		x,y+=30,150,24,hWnd,(HMENU)IDC_EDIT_SINGLELINE,g_hInstance,NULL);
	CreateWindowEx(0,"EDIT","",
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY,
		x,y+=30,150,24,hWnd,(HMENU)IDC_EDIT_READONLY,g_hInstance,NULL);
	CreateWindowEx(0,"EDIT","",
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,
		x,y+=30,150,64,hWnd,(HMENU)IDC_EDIT_MULTILINE,g_hInstance,NULL);
	CreateWindowEx(0,"EDIT","",
		WS_CHILD | WS_VISIBLE | WS_BORDER | ES_PASSWORD | ES_CENTER,
		x,y+=70,150,24,hWnd,(HMENU)IDC_EDIT_MULTILINE,g_hInstance,NULL);
}
void OnCommand( HWND hWnd, WPARAM wParam ,LPARAM lParam)
{
	switch( LOWORD( wParam )){ // 控件ID
	case IDC_EDIT_SINGLELINE:
		switch(HIWORD(wParam)){
		case EN_CHANGE:
			char szText[256] = {0};
//			GetWindowText((HWND)lParam, szText, 256 );
			SendMessage((HWND)lParam,WM_GETTEXT,256,(LPARAM)szText);
			SetWindowText(GetDlgItem(hWnd,IDC_EDIT_READONLY),szText);
//			MessageBox( hWnd, szText, "WinControl",MB_OK );
			break;
		}
		break;
	case IDC_BTN_CHECKBOX:
		switch(HIWORD(wParam)){
		case BN_CLICKED:
			switch(SendMessage((HWND)lParam,BM_GETCHECK,0,0)){
			case BST_CHECKED:
				SendMessage((HWND)lParam,BM_SETCHECK,BST_UNCHECKED,0);
				break;
			case BST_UNCHECKED:
				SendMessage((HWND)lParam,BM_SETCHECK,BST_CHECKED,0);
				break;
			}
			break;
		}
		break;
	case IDC_BTN_PUSHBUTTON:
	case IDC_BTN_DEFPUSHBUTTON:
		switch( HIWORD( wParam )) {// 通知码
		case BN_CLICKED:  {// 单击
/*			   char szText[256] = {0};
			   GetWindowText( (HWND)lParam, szText, 256);
			   MessageBox( hWnd, szText,"WinControl",MB_OK);*/
			}
			break;
		case BN_DBLCLK:{
			   char szText[256] = {0};
			   GetWindowText( (HWND)lParam, szText, 256);
			   MessageBox( hWnd, szText,"WinControl",MB_OK);
			}
			break;
		}
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
		OnCommand( hWnd, wParam, lParam);
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