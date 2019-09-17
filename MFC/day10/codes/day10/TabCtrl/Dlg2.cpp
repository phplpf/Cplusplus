// Dlg2.cpp : 实现文件
//

#include "stdafx.h"
#include "TabCtrl.h"
#include "Dlg2.h"
#include "afxdialogex.h"


// CDlg2 对话框

IMPLEMENT_DYNAMIC(CDlg2, CDialogEx)

CDlg2::CDlg2(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlg2::IDD, pParent)
{

}

CDlg2::~CDlg2()
{
}

void CDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg2, CDialogEx)
END_MESSAGE_MAP()


// CDlg2 消息处理程序
