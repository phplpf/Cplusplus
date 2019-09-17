#include <afxwin.h>
#include "resource.h"

// 视图类
class CMyView:public CView
{
public:
	virtual void OnDraw(CDC* pDC);
	afx_msg void OnTest();
	afx_msg void OnPaint();
DECLARE_MESSAGE_MAP( )
};
BEGIN_MESSAGE_MAP(CMyView,CView)
	ON_COMMAND(ID_TEST,OnTest)
	//ON_WM_PAINT( )
END_MESSAGE_MAP( )

void CMyView::OnTest()
{
	AfxMessageBox("CMyView::OnTest");
}

void CMyView::OnDraw(CDC* pDC)
{
	pDC->TextOut(10,10,"Hello OnDraw");
}
void CMyView::OnPaint()
{
	PAINTSTRUCT ps={0};
	CDC* pDC = BeginPaint(&ps);
	pDC->TextOut(10,100,"Hello OnPaint");
	EndPaint(&ps);

}
class CMyFrameWnd:public CFrameWnd
{
DECLARE_MESSAGE_MAP()
public:
	CMyFrameWnd()
	{
		m_pwndView=NULL;
	}
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize( UINT nType, int cx, int cy );
    // CMyView m_wndView;//视图对象
	CMyView* m_pwndView;//视图对象指针
};
BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_WM_CREATE( )
	//ON_WM_SIZE( )
END_MESSAGE_MAP( )
void CMyFrameWnd::OnSize( UINT nType, int cx, int cy )
{
	if (m_pwndView!=NULL)
	{
		m_pwndView->MoveWindow(0,0,cx,cy);
	}
}
int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	// 视图
	// 1 创建视图对象
	m_pwndView =new CMyView;
	// 2 创建视图窗口
	m_pwndView->Create(NULL,"mfcview",WS_VISIBLE|WS_CHILD|WS_BORDER,
		CRect(0,0,200,200),this,AFX_IDW_PANE_FIRST);
	// 3 设置活动视图
	//SetActiveView(m_pwndView);
	m_pViewActive = m_pwndView;  
	return 0;
}
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame=new CMyFrameWnd;
	pFrame->LoadFrame(IDR_MENU1);
	m_pMainWnd=pFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}