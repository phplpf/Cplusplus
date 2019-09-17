#include <afxwin.h>
#include <afxext.h>
#include "resource.h"

// 5 文档类(支持动态创建)
class CMyDoc:public CDocument
{
	DECLARE_DYNCREATE(CMyDoc)
public:
	CString m_strData;
};
IMPLEMENT_DYNCREATE(CMyDoc,CDocument)

// 4 视图类(支持动态创建)
class CMyView:public CEditView
{
	DECLARE_DYNCREATE(CMyView)
	DECLARE_MESSAGE_MAP( )
protected:
	afx_msg void OnEnChange();
public:
	virtual void OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint );
};
IMPLEMENT_DYNCREATE(CMyView,CEditView)
BEGIN_MESSAGE_MAP(CMyView,CEditView)
	ON_CONTROL_REFLECT(EN_CHANGE,OnEnChange)
END_MESSAGE_MAP( )
void CMyView::OnEnChange()
{
	// 1 获取相关文档
	CMyDoc* pDoc=(CMyDoc*)GetDocument();
	// 2 将活动视图的数据保存到文档
	GetWindowText(pDoc->m_strData);
	// 3 文档通知其它视图数据更新了
	pDoc->UpdateAllViews(this);
}
void CMyView::OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint )
{
	// 4 获取相关文档
	CMyDoc* pDoc=(CMyDoc*)GetDocument();
	// 5 获取文档数据放到视图窗口中显式
	SetWindowText(pDoc->m_strData);

}
// 3 多文档的子框架窗口类(支持动态创建)
class CChildFrame:public CMDIChildWnd
{
	DECLARE_DYNCREATE(CChildFrame)
DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnNewWnd();
};
IMPLEMENT_DYNCREATE(CChildFrame,CMDIChildWnd)
BEGIN_MESSAGE_MAP(CChildFrame,CMDIChildWnd)
	ON_COMMAND(ID_NEW_WND,OnNewWnd)
END_MESSAGE_MAP()
void CChildFrame::OnNewWnd()
{
	// 1 获取活动文档
	CDocument* pDoc=GetActiveDocument();
	// 2 根据文档获取文档模板
	CDocTemplate* pTemplate=pDoc->GetDocTemplate();
	// 3 使用文档模板创建新的子框架
	CFrameWnd* pChildFrame= pTemplate->CreateNewFrame(pDoc,NULL);
	// 4 初始化更新子框架
	pChildFrame->InitialUpdateFrame(pDoc,TRUE); 
}


// 1 多文档的主框架窗口类
class CMainFrame:public CMDIFrameWnd
{

};
// 2 应用程序类
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
	afx_msg void OnNew();
DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CMyWinApp,CWinApp)
	ON_COMMAND(ID_NEW,OnNew)
END_MESSAGE_MAP()

CMyWinApp theApp;
void CMyWinApp::OnNew()
{
	OnFileNew();
}
BOOL CMyWinApp::InitInstance()
{
	CMainFrame* pFrame=new CMainFrame;
	pFrame->LoadFrame(IDR_MAIN);
	m_pMainWnd=pFrame;

	CMultiDocTemplate* pTemplate=new CMultiDocTemplate(
		IDR_CHILD,RUNTIME_CLASS(CMyDoc),
		RUNTIME_CLASS(CChildFrame),RUNTIME_CLASS(CMyView));
	AddDocTemplate(pTemplate);
	OnFileNew();
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}