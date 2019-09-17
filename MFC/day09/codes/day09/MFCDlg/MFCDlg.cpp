#include <afxwin.h>
#include "resource.h"

// 2 对话框类
class CMyDlg:public CDialog
{
public:
	CMyDlg():CDialog(IDD_DIALOG1){}
	virtual void OnOK();
	virtual void OnCancel();
	virtual void PostNcDestroy();
};
void CMyDlg::OnOK()
{
	DestroyWindow();
}
void CMyDlg::OnCancel()
{
	DestroyWindow();
}
void CMyDlg::PostNcDestroy()
{
	delete this;
}
// 1 应用程序类
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance()
{
	/*
	// 1 模式对话框
	CMyDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	*/
    //  非模式对话框 (CMyFrameWnd类  CMyDlg类)
	CMyDlg *pDlg = new CMyDlg;
	pDlg->Create(IDD_DIALOG1);
	m_pMainWnd = pDlg;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}