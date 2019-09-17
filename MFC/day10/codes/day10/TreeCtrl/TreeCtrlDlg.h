
// TreeCtrlDlg.h : 头文件
//

#pragma once


// CTreeCtrlDlg 对话框
class CTreeCtrlDlg : public CDialogEx
{
// 构造
public:
	CTreeCtrlDlg(CWnd* pParent = NULL);	// 标准构造函数
	CImageList m_ilNormal;
// 对话框数据
	enum { IDD = IDD_TREECTRL_DIALOG };

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
	CTreeCtrl m_wndTree;
	afx_msg void OnBnClickedButton1();
	CString m_strName;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
};
