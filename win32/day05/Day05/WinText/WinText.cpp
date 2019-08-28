#include <windows.h>
HINSTANCE g_hInstance = 0;
void OnPaint( HWND hWnd )
{
	PAINTSTRUCT ps = {0};
	HDC hdc = BeginPaint( hWnd, &ps );

	SetTextColor( hdc, RGB( 255, 0, 0 ) );      // 设置文本颜色
	SetBkColor( hdc, RGB( 220, 200, 220 ) ); // 设置背景颜色
	SetBkMode( hdc, TRANSPARENT );        // 设置背景模式( 不透明/透明) 

	// 创建字体
	HFONT hFont = CreateFont(30,0,100,0,900,0,1,1,GB2312_CHARSET,0,0,0,0,"LiSu");
	// 将字体应用到DC中
	HGDIOBJ hOldFont = SelectObject( hdc, hFont );
	char szText[] = "珠市口大街";
	// 绘制字符串
	TextOut( hdc, 100, 100, szText, strlen(szText) );
	RECT rc = {0};	
	rc.left = 100;
	rc.top = 150;
	rc.right = 200;
	rc.bottom = 200;
//	Rectangle( hdc, 100,150,200,200);
	DrawText( hdc, szText, strlen(szText), &rc,
		DT_CENTER | DT_TOP | DT_SINGLELINE | DT_HIDEPREFIX | DT_NOCLIP);
	// 从DC中取出字体
	SelectObject( hdc, hOldFont );
	// 销毁字体
	DeleteObject( hFont );
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
	wndCls.hbrBackground = CreateSolidBrush( RGB( 200, 220, 220 ) );
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