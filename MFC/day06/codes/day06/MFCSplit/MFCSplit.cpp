#include <afxwin.h>
#include "resource.h"
#include <afxext.h>
#include <afxhtml.h>

// 视图类(支持动态创建)
class CMyView:public CView
{
public:
	virtual void OnDraw(CDC* pDC);
	afx_msg void OnTest();
DECLARE_DYNCREATE(CMyView)
DECLARE_MESSAGE_MAP( )
};
IMPLEMENT_DYNCREATE(CMyView,CView)
BEGIN_MESSAGE_MAP(CMyView,CView)
	ON_COMMAND(ID_TEST,OnTest)
END_MESSAGE_MAP( )
void CMyView::OnTest()
{
	AfxMessageBox("CMyView::OnTest");
}
void CMyView::OnDraw(CDC* pDC)
{
	pDC->TextOut(10,10,"Hello World");
}


class CMyFrameWnd:public CFrameWnd
{
public:
	virtual BOOL OnCreateClient( LPCREATESTRUCT lpcs, CCreateContext* pContext );
	CSplitterWnd m_wndSplit;//切分窗口对象

};
BOOL CMyFrameWnd::OnCreateClient( LPCREATESTRUCT lpcs, CCreateContext* pContext )
{
	/*
	// 静态切分
	// 1 创建静态切分窗口
	m_wndSplit.CreateStatic(this,1,2);
	// 2 创建视图
	m_wndSplit.CreateView(0,0,RUNTIME_CLASS(CMyView),CSize(200,200),pContext);
	m_wndSplit.CreateView(0,1,RUNTIME_CLASS(CHtmlView),CSize(200,200),pContext);
	// 3 根据视图位置获取视图
	CHtmlView* pHtml=(CHtmlView*)m_wndSplit.GetPane(0,1);
    // 4 导航
	pHtml->Navigate("d:/");
	// 5 设置活动视图
	m_wndSplit.SetActivePane(0,0);
	
	// 作业
	// 1 获取框架窗口的客户区大小
	CRect rt;
	GetClientRect(&rt);
	// 2 创建静态切分
	m_wndSplit.CreateStatic(this,3,3);
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			m_wndSplit.CreateView(i,j,RUNTIME_CLASS(CMyView),
				CSize(rt.Width()/3,rt.Height()/3),pContext);
		}
	}
	*/
	// 动态切分
	CCreateContext cxt;
	cxt.m_pNewViewClass = RUNTIME_CLASS(CEditView);
	m_wndSplit.Create(this,2,2,CSize(1,1),&cxt);


	return TRUE;
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