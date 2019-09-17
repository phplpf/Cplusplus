#include <afxwin.h>
#include "resource.h"

// 1 框架窗口类
class CMyFrameWnd:public CFrameWnd
{
	DECLARE_MESSAGE_MAP( )
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnNew();
	afx_msg void OnExit();
	afx_msg void OnAbout();
	afx_msg void OnAboutUpdateCmdUI(CCmdUI*pCmdUI);
	afx_msg void OnContextMenu( CWnd* pWnd, CPoint pos );
	CMenu m_Menu;//菜单对象
};
BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_NEW,OnNew)
	ON_COMMAND(ID_EXIT,OnExit)
	ON_COMMAND(ID_ABOUT,OnAbout)
	ON_UPDATE_COMMAND_UI(ID_ABOUT,OnAboutUpdateCmdUI)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP( )
void CMyFrameWnd::OnContextMenu( CWnd* pWnd, CPoint pos )
{
	// 1 加载菜单资源
	CMenu menu;
	menu.LoadMenu(IDR_MENU2);
	// 2 获取某个菜单项下的子菜单
	CMenu * pPopMenu = menu.GetSubMenu(1);
	// 3 显示菜单
	pPopMenu->TrackPopupMenu(TPM_LEFTALIGN,pos.x,pos.y,this );

}
void CMyFrameWnd::OnAboutUpdateCmdUI(CCmdUI*pCmdUI)
{
	//pCmdUI->SetCheck(1);//设置菜单的复选状态
	//pCmdUI->SetRadio(TRUE);//设置菜单的单选状态
   pCmdUI->SetText("关于软件版权");

}
void CMyFrameWnd::OnAbout()
{
	AfxMessageBox("CMyFrameWnd类实现的OnAbout");
}
void CMyFrameWnd::OnExit()
{
	PostQuitMessage(0);
}
void CMyFrameWnd::OnNew()
{
	AfxMessageBox("CMyFrameWnd::OnNew");
}
int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	// 添加菜单
	// 1 加载菜单资源
	m_Menu.LoadMenu(IDR_MENU1);
	// 2 将菜单设置到窗口
	SetMenu(&m_Menu);
	return 0;
}

// 2 应用程序类
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
	afx_msg void OnAbout();
	DECLARE_MESSAGE_MAP()
};
BEGIN_MESSAGE_MAP(CMyWinApp,CWinApp)
	ON_COMMAND(ID_ABOUT,OnAbout)
END_MESSAGE_MAP()

CMyWinApp theApp;
void CMyWinApp::OnAbout()
{
	AfxMessageBox("CMyWinApp类实现的关于对话框");
}
BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame=new CMyFrameWnd;
	pFrame->Create(NULL,"MFCMenu");
	m_pMainWnd=pFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}