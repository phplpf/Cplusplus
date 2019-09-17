
// ControlsDlg.h : 头文件
//

#pragma once


// CControlsDlg 对话框
class CControlsDlg : public CDialogEx
{
// 构造
public:
	CControlsDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CONTROLS_DIALOG };

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
	int m_nEat;
	int m_nGame;
	int m_nSleep;
	afx_msg void OnBnClickedButton1();
	int m_nCity;
	int m_nMajor;
	CListBox m_wndList;
	afx_msg void OnBnClickedGet1();
	CString m_strIdol;
	CString m_strType;
	afx_msg void OnBnClickedGet2();
};
