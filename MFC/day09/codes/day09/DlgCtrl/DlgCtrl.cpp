#include <afxwin.h>
#include "resource.h"

class CMyDlg:public CDialog
{
public:
	CMyDlg():CDialog(IDD_DIALOG1){}
	virtual BOOL OnInitDialog( ); 
	virtual void DoDataExchange( CDataExchange* pDX );
	virtual void OnOK();
	CButton m_wndOK;//控件类型的变量
	CString m_strEdit;//值类型的变量
};
void CMyDlg::DoDataExchange( CDataExchange* pDX )
{
	CDialog::DoDataExchange(pDX);
	//完成控件与变量的绑定
	DDX_Control(pDX,IDOK,m_wndOK);
	DDX_Text(pDX,IDC_EDIT1,m_strEdit);
}
BOOL CMyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// 控件的初始化
    // 1 获取取消按钮对象
	CWnd* pWnd = GetDlgItem(IDCANCEL);
	// 2 设置取消按钮的文本
	pWnd->SetWindowText("取消操作");

	m_wndOK.SetWindowText("确定操作");
	m_wndOK.MoveWindow(0,0,100,100);

	m_strEdit = "Hello World";
	//变量=>控件(FALSE)
	UpdateData(FALSE);
	return TRUE;
}
void CMyDlg::OnOK()
{
	UpdateData(TRUE);
	AfxMessageBox(m_strEdit);
}



class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance()
{
	CMyDlg dlg;
	m_pMainWnd=&dlg;
	dlg.DoModal();
	return TRUE;
}