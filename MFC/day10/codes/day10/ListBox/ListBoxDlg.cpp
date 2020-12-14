
// ListBoxDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ListBox.h"
#include "ListBoxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CListBoxDlg �Ի���




CListBoxDlg::CListBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CListBoxDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_wndList1);
	DDX_Control(pDX, IDC_LIST2, m_wndList2);
}

BEGIN_MESSAGE_MAP(CListBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CListBoxDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CListBoxDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CListBoxDlg ��Ϣ��������

BOOL CListBoxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ����Ӷ���ĳ�ʼ������
	m_wndList1.AddString("����");
	m_wndList1.AddString("�Ϻ�");
	m_wndList1.AddString("���");
	m_wndList1.AddString("����");


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CListBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CListBoxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CListBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CListBoxDlg::OnBnClickedButton1()
{
	// �������ƶ�һ��
	// 1 ��ȡ�û���ǰ��ѡ����
	int nIndex=m_wndList1.GetCurSel();
	if (nIndex==-1)
	{
		AfxMessageBox("��ѡ��Ҫ�ƶ���ѡ�");
		return;
	}
	// 2 ��������ֵ��ȡ�ı�
	CString strCity;
	m_wndList1.GetText(nIndex,strCity);
	// 3 ���ı����ӵ��ұߵ��б��ؼ�
	m_wndList2.AddString(strCity);
	// 4 ɾ����ߵ�ѡ��
	m_wndList1.DeleteString(nIndex);
}


void CListBoxDlg::OnBnClickedButton2()
{
	// 1 ��ȡѡ�������
	int nCount=m_wndList1.GetCount();
	CString strCity;
	for (int i=0;i<nCount;i++)
	{
		m_wndList1.GetText(i,strCity);
		m_wndList2.AddString(strCity);
	}
	//2 ����б��ؼ�1
	m_wndList1.ResetContent();
}