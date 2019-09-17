
// TabCtrlDlg.h : 头文件
//

#pragma once

#include "Dlg1.h"
#include "Dlg2.h"

// CTabCtrlDlg 对话框
class CTabCtrlDlg : public CDialogEx
{
// 构造
public:
	CTabCtrlDlg(CWnd* pParent = NULL);	// 标准构造函数
	CDlg1 m_dlg1;
	CDlg2 m_dlg2;
// 对话框数据
	enum { IDD = IDD_TABCTRL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_wndTab;
	void InitTabCtrl(void);
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
