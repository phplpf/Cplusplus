
// ListCtrlDlg.h : ͷ�ļ�
//

#pragma once


// CListCtrlDlg �Ի���
class CListCtrlDlg : public CDialogEx
{
// ����
public:
	CListCtrlDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CImageList m_ilNormal;//ͼ���б�
	CImageList m_ilSmall;//Сͼ���б�
// �Ի�������
	enum { IDD = IDD_LISTCTRL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void InitListCtrl(void);
	CListCtrl m_wndList;
	void ShowData(CString strPath);
};