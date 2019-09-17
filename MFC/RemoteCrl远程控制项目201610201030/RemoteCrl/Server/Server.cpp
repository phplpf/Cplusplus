// Server.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "Server.h"
#include "globalhead.h"
#include "CaptureScreen.h"
#include "PeerSocket.h"
#include "PeerThread.h"
#include "command.h"
#define MAX_LOADSTRING 100

// 全局变量:
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);


HWND	  hMainWnd;//主框架窗口句柄
int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	
	//	1 创建互斥体,保证只有一个实例		
	if ((hOnlyInstance=CreateMutex(NULL,false,"JFY's PeerYou"))==NULL)
		return -1;
	else if (GetLastError()==ERROR_ALREADY_EXISTS)
		return -1;


	//	2 创建用于退出程序的事件句柄
	if ((hExitEvent=WSACreateEvent())==WSA_INVALID_EVENT){
		CloseHandle(hOnlyInstance);
		return -1;
	}
	//	3 初始化socket库
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2,2),&wsaData)!=0) {
		//	无可用WinSock DLL. 
		CloseHandle(hOnlyInstance);
		CloseHandle(hExitEvent);
		return -1;
	}
	
	
	
	
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: 在此放置代码。
	MSG msg;
	HACCEL hAccelTable;

	// 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_SERVER, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SERVER));


	InitializeCriticalSection(&csCaptureScreen);
	// 主消息循环:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	CloseHandle(hOnlyInstance);
	WSACloseEvent(hExitEvent);
	DeleteCriticalSection(&csCaptureScreen);
	WSACleanup();
	return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
//
//  注释:
//
//    仅当希望
//    此代码与添加到 Windows 95 中的“RegisterClassEx”
//    函数之前的 Win32 系统兼容时，才需要此函数及其用法。调用此函数十分重要，
//    这样应用程序就可以获得关联的
//    “格式正确的”小图标。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SERVER));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_SERVER);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // 将实例句柄存储在全局变量中

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
       CloseHandle(hOnlyInstance);
	   WSACloseEvent(hExitEvent);
	   WSACleanup();
	   return FALSE;
   }
   hMainWnd=hWnd;
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_CREATE:
		//得到主机名称
		int nComputerNameLen;
		nComputerNameLen=MAX_COMPUTERNAME_LENGTH + 1;
		if(SOCKET_ERROR==gethostname(szHostName,nComputerNameLen))
			return -1;
	
		//得到主机IP地址
		HOSTENT *hentThisHost;
		hentThisHost=NULL;
		if(!(hentThisHost=gethostbyname(szHostName)))
			return -1;
		in_addr inaddrThisHost;
		memcpy(&inaddrThisHost.S_un.S_addr,hentThisHost->h_addr,hentThisHost->h_length);
		strcpy(szHostAddr,inet_ntoa(inaddrThisHost));

		
		//初始化关键代码段(保护线程列表)
		InitializeCriticalSection(&csProtectList);
		//启动监听线程
		hAcceptThread=BeginPeerThread(AcceptThread,NULL,&uAcceptThreadID);
		if(!hAcceptThread)
		{
			return FALSE;
		}
		//启动清理线程动态跟踪系统
		hCleanupThread =BeginPeerThread(CleanupThread,NULL,&uCleanupThreadID);
		if(!hCleanupThread)
		{
			return FALSE;
		}
		
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		RECT rect;
		GetClientRect(hMainWnd,&rect);
		DrawText(hdc,szHostName,strlen(szHostName),&rect,DT_CENTER);
		DrawText(hdc,szHostAddr,strlen(szHostAddr),&rect,DT_SINGLELINE|DT_VCENTER|DT_CENTER);
		EndPaint(hWnd, &ps);
		break;
	case WM_CLOSE:
		
		HANDLE hEvent[2];
	    //等待两个主要线程是否已经退出
		hEvent[0]=hAcceptThread;
		hEvent[1]=hCleanupThread;
		//关闭线程句柄
		CloseHandle(hAcceptThread);
		CloseHandle(hCleanupThread);
		//所有服务线程都已经退出
		while(listConnectThread.size())
		{
			Sleep(100);
		}
		//删除临界区(保护线程列表)
		DeleteCriticalSection(&csProtectList);
		
		//发送关闭窗口消息
		SendMessage(hMainWnd,WM_DESTROY,0,0);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
