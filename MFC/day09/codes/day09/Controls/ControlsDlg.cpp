
// ControlsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Controls.h"
#include "ControlsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CControlsDlg 对话框




CControlsDlg::CControlsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CControlsDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nEat = 0;
	m_nGame = 0;
	m_nSleep = 0;
	m_nCity = 0;
	m_nMajor = 0;
	m_strIdol = _T("");
	m_strType = _T("");
}

void CControlsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_EAT, m_nEat);
	DDX_Check(pDX, IDC_GAME, m_nGame);
	DDX_Check(pDX, IDC_SLEEP, m_nSleep);
	DDX_Radio(pDX, IDC_RADIO1, m_nCity);
	DDX_Radio(pDX, IDC_RADIO4, m_nMajor);
	DDX_Control(pDX, IDC_LIST1, m_wndList);
	DDX_CBString(pDX, IDC_IDOl, m_strIdol);
	DDX_LBString(pDX, IDC_LIST1, m_strType);
}

BEGIN_MESSAGE_MAP(CControlsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CControlsDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_GET1, &CControlsDlg::OnBnClickedGet1)
	ON_BN_CLICKED(IDC_GET2, &CControlsDlg::OnBnClickedGet2)
END_MESSAGE_MAP()


// CControlsDlg 消息处理程序

BOOL CControlsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_nGame = 1;//复选

	m_nMajor=2;//单选
	m_nCity=0;//单选

	UpdateData(FALSE);

	m_wndList.AddString("C/C++");
	m_wndList.AddString("Python");
	m_wndList.AddString("系统运维");
	m_wndList.AddString("Java");
	m_wndList.AddString("UI");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CControlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CControlsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CControlsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CControlsDlg::OnBnClickedButton1()
{
	CString strHobby="爱好：";
	UpdateData(TRUE);
	if (m_nEat == 1)
	{
		strHobby+="吃饭；";
	}
	if (m_nSleep == 1)
	{
		strHobby+="睡觉；";
	}
	if (m_nGame == 1)
	{
		strHobby+="打游戏；";
	}
	AfxMessageBox(strHobby);
	
	//单选按钮的数据
	CString strCity="所在城市：";
	switch(m_nCity){
	case 0:
		strCity+="北京";
		break;
	case 1:
		strCity+="上海";
		break;
	case 2:
		strCity+="广州";
		break;
	}
	AfxMessageBox(strCity);
}


void CControlsDlg::OnBnClickedGet1()
{
	UpdateData(TRUE);
	AfxMessageBox(m_strIdol);
}
#include <vector>
void CControlsDlg::OnBnClickedGet2()
{
	/*
	UpdateData(TRUE);
	AfxMessageBox(m_strType);
	*/
	//std::vector<int > ints;
	CString strInfo;
	// 获取选择项的数量
	int selCount=m_wndList.GetSelCount();
	int *pInt=new int[selCount];
	// 获取多个选项的索引值，保存到数组中
	
	m_wndList.GetSelItems(selCount,pInt);
	CString strText;
	for (int i=0;i<selCount;i++)
	{
		// 根据每一个选项的索引值，获取选项的文本
		m_wndList.GetText( pInt[i],strText);
		strInfo+=strText;
	}
	delete[] pInt;
	AfxMessageBox(strInfo);
	
	
}
