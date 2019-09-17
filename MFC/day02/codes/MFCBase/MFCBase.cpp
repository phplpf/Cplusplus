/*
#include <Windows.h>//win32 
#include <afx.h>//MFC
*/
#include <afxwin.h> // Win32+MFC
 
// 2 窗口类
class CMyFrameWnd:public CFrameWnd
{

};

// 1 应用程序
class CMyWinApp:public CWinApp
{
public:
	// 初始化函数
	virtual BOOL InitInstance();
	virtual int ExitInstance( );
	virtual int Run( );

};
int CMyWinApp::ExitInstance()
{
	AfxMessageBox("用户资源的释放，库的卸载");
	return CWinApp::ExitInstance();
}
int CMyWinApp::Run()
{
	AfxMessageBox("进入消息循环");
	return CWinApp::Run();
}

CMyWinApp theApp;//全局应用程序对象
BOOL CMyWinApp::InitInstance()
{
	// 用户的流程从此开始编写（基本的窗口程序）
	CMyFrameWnd* pFrame=new CMyFrameWnd;
	pFrame->Create(NULL,"MFCBase");
	m_pMainWnd = pFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}
