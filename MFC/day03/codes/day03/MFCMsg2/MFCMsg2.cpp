#include <afxwin.h>
#define WM_MY_MSG WM_USER+100
// 1 框架窗口类
class CMyFrameWnd:public CFrameWnd
{
	DECLARE_MESSAGE_MAP( )
public:
	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
	afx_msg void OnTest();
	afx_msg void OnTestRange(UINT nID);
	afx_msg void OnEnChange();
	afx_msg LRESULT OnMyMsg(WPARAM wParam,LPARAM lParam );
};
BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	// 窗口消息
	ON_WM_CREATE()
	// 命令消息
	ON_COMMAND(1000,OnTest)
	ON_COMMAND_RANGE(1006,1008,OnTestRange)
	// 通知消息
	ON_EN_CHANGE(1010,OnEnChange)
	// 用户自定义消息
	ON_MESSAGE(WM_MY_MSG,OnMyMsg)

END_MESSAGE_MAP( )
LRESULT CMyFrameWnd::OnMyMsg(WPARAM wParam,LPARAM lParam )
{
	CString strData;
	strData.Format("%d",wParam+lParam);
	AfxMessageBox(strData);
	return 0;
}
void CMyFrameWnd::OnEnChange()
{
	CWnd* pWnd=GetDlgItem(1010);
	CString strData;
	pWnd->GetWindowText(strData);
	AfxMessageBox(strData);
}
void CMyFrameWnd::OnTestRange(UINT nID)
{
	/*
	CString strInfo;
	strInfo.Format("nID:%d",nID);
	AfxMessageBox(strInfo);
	*/
	// 在消息框中显示按钮的文本
}
void CMyFrameWnd::OnTest()
{
	//AfxMessageBox("CMyFrameWnd::OnTest");
	this->SendMessage(WM_MY_MSG,110,250);
}

int CMyFrameWnd::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
	//AfxMessageBox("CMyFrameWnd::OnCreate");
	::CreateWindow("BUTTON","测试",WS_CHILD|WS_VISIBLE,100,100,100,40,
		m_hWnd,(HMENU)1000,AfxGetInstanceHandle(),NULL);

	::CreateWindow("BUTTON","测试6",WS_CHILD|WS_VISIBLE,100,200,100,40,
		m_hWnd,(HMENU)1006,AfxGetInstanceHandle(),NULL);
	::CreateWindow("BUTTON","测试7",WS_CHILD|WS_VISIBLE,100,300,100,40,
		m_hWnd,(HMENU)1007,AfxGetInstanceHandle(),NULL);
	::CreateWindow("BUTTON","测试8",WS_CHILD|WS_VISIBLE,100,400,100,40,
		m_hWnd,(HMENU)1008,AfxGetInstanceHandle(),NULL);

	::CreateWindow("EDIT","",WS_CHILD|WS_VISIBLE|WS_BORDER,300,100,200,40,
		m_hWnd,(HMENU)1010,AfxGetInstanceHandle(),NULL);
	return 0;
}

// 2 应用程序类
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame=new CMyFrameWnd;
	pFrame->Create(NULL,"MFCMsg");
	m_pMainWnd=pFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}