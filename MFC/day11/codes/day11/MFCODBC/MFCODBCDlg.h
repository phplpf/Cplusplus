
// MFCODBCDlg.h : 头文件
//

#pragma once

#include <afxdb.h>

// CMFCODBCDlg 对话框
class CMFCODBCDlg : public CDialogEx
{
// 构造
public:
	CMFCODBCDlg(CWnd* pParent = NULL);	// 标准构造函数
	CDatabase m_db;//数据库连接对象
// 对话框数据
	enum { IDD = IDD_MFCODBC_DIALOG };

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
	afx_msg void OnClose();
	afx_msg void OnBnClickedQuery();
	CListCtrl m_wndList;
	void InitClassCtrl(void);
	CComboBox m_wndClass;
	afx_msg void OnBnClickedAdd();
	CString m_strName;
	int m_nAge;
	CString m_strAddress;
	CString m_strId;//学员编号

	afx_msg void OnBnClickedDel();
	afx_msg void OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_strClass;
	afx_msg void OnBnClickedModify();
};
