#include <afxwin.h>
#include "resource.h"

// 2 �Ի�����
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
// 1 Ӧ�ó�����
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance()
{
	/*
	// 1 ģʽ�Ի���
	CMyDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	*/
    //  ��ģʽ�Ի��� (CMyFrameWnd��  CMyDlg��)
	CMyDlg *pDlg = new CMyDlg;
	pDlg->Create(IDD_DIALOG1);
	m_pMainWnd = pDlg;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}