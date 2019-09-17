
// CommonCtrlDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CommonCtrl.h"
#include "CommonCtrlDlg.h"
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


// CCommonCtrlDlg 对话框




CCommonCtrlDlg::CCommonCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCommonCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCommonCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, m_wndSpin);
	DDX_Control(pDX, IDC_PROGRESS1, m_wndProgress);
	DDX_Control(pDX, IDC_SLIDER1, m_wndSlider);
}

BEGIN_MESSAGE_MAP(CCommonCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MOVE, &CCommonCtrlDlg::OnBnClickedMove)
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CCommonCtrlDlg 消息处理程序

BOOL CCommonCtrlDlg::OnInitDialog()
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
	// 1 设置范围
	m_wndSpin.SetRange(0,1000);
	m_wndProgress.SetRange(0,1000);
	m_wndSlider.SetRange(0,1000);
	// 2 设置增量
	UDACCEL accel[2]={0};
	accel[0].nSec =1;
	accel[0].nInc  =5;
	accel[1].nSec =2;
	accel[1].nInc  =100;
	m_wndSpin.SetAccel(2,accel);
	// 设置步长
	m_wndProgress.SetStep(100);
	// 设置刻度
	m_wndSlider.SetTicFreq(100);
	m_wndSlider.SetPageSize(200);
	m_wndSlider.SetLineSize(100);
	// 3 设置当前值(位置)
	m_wndSpin.SetPos(100);
	m_wndProgress.SetPos(m_wndSpin.GetPos());
	m_wndSlider.SetPos(m_wndSpin.GetPos());

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCommonCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCommonCtrlDlg::OnPaint()
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
HCURSOR CCommonCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCommonCtrlDlg::OnBnClickedMove()
{
	// 1 进度条前进一个步长
	m_wndProgress.StepIt();
	// 2 获取进度条的位置
	int nPos = m_wndProgress.GetPos();
	// 3 设置到其它两个控件
	m_wndSlider.SetPos(nPos);
	m_wndSpin.SetPos(nPos);

}


void CCommonCtrlDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if((CSpinButtonCtrl*)pScrollBar == &m_wndSpin)
	{
		int nPos = m_wndSpin.GetPos();
		m_wndSlider.SetPos(nPos);
		m_wndProgress.SetPos(nPos);

	}
	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CCommonCtrlDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
