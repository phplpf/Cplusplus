// DlgLogin.cpp : 实现文件
//

#include "stdafx.h"
#include "Login.h"
#include "DlgLogin.h"
#include "afxdialogex.h"


// CDlgLogin 对话框

IMPLEMENT_DYNAMIC(CDlgLogin, CDialogEx)

CDlgLogin::CDlgLogin(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgLogin::IDD, pParent)
{

	m_strName = _T("");
	m_strPwd = _T("");
}

CDlgLogin::~CDlgLogin()
{
}

void CDlgLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_PWD, m_strPwd);
}


BEGIN_MESSAGE_MAP(CDlgLogin, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlgLogin::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgLogin 消息处理程序


void CDlgLogin::OnBnClickedOk()
{
	//name:csd1905 pwd:best
	UpdateData(TRUE);
	if (m_strName=="csd1905"&&m_strPwd=="best")
	{
		CDialogEx::OnOK();
	}
	else
	{
	   AfxMessageBox("用户名或密码错误，请重新输入！");
	}
	
	
}
