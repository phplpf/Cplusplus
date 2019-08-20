#include <windows.h>
// 2. 窗口处理函数 ( 自定义，处理消息 )
LRESULT CALLBACK WndProc( HWND hWnd, UINT msgID,
	WPARAM wParam, LPARAM lParam )
{
	// 7. 消息处理
	return DefWindowProc( hWnd,msgID, wParam, lParam);
	           // 对各种消息做默认处理
}
// 1. 定义WinMain函数
int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPrevIns,
	LPSTR lpCmdLine,int nCmdShow)
{
	// 3. 注册窗口类
	WNDCLASS wndCls = {0};
	wndCls.cbClsExtra = 0;			        // 窗口类附加数据缓冲区
	wndCls.cbWndExtra = 0;                // 窗口附加数据缓冲区
	wndCls.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // 背景色
	wndCls.hCursor = NULL;			        // 光标 NULL表示使用系统默认值
	wndCls.hIcon = NULL;				    // 图标 NULL表示使用系统默认值
	wndCls.hInstance = hInstance;      // WinMain的第一个参数
	wndCls.lpfnWndProc = WndProc; // 窗口处理函数的函数指针或函数名
	wndCls.lpszClassName = "Main";  // 窗口类名称
	wndCls.lpszMenuName = NULL;   // 菜单  NULL表示没有菜单
	wndCls.style = CS_HREDRAW | CS_VREDRAW; // 窗口类风格
	RegisterClass(&wndCls);    // 将以上赋值写入操作系统
	// 4. 创建窗口
	HWND hWnd = CreateWindow("Main","Window",WS_OVERLAPPEDWINDOW,
		100,100,700,500,NULL,NULL,hInstance,NULL);
	// 5. 显示窗口
	ShowWindow( hWnd, SW_SHOW);
	// 6. 消息循环
	MSG nMsg = {0};
	while(GetMessage(&nMsg,NULL,0,0))
	{
		TranslateMessage(&nMsg);
		DispatchMessage(&nMsg);
	}
	return 0;
}