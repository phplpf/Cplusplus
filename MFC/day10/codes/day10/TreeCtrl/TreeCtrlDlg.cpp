
// TreeCtrlDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TreeCtrl.h"
#include "TreeCtrlDlg.h"
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


// CTreeCtrlDlg 对话框




CTreeCtrlDlg::CTreeCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTreeCtrlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strName = _T("");
}

void CTreeCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_wndTree);
	DDX_Text(pDX, IDC_NAME, m_strName);
}

BEGIN_MESSAGE_MAP(CTreeCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTreeCtrlDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CTreeCtrlDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CTreeCtrlDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CTreeCtrlDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CTreeCtrlDlg 消息处理程序

BOOL CTreeCtrlDlg::OnInitDialog()
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

	// 1 设置树控件的图标列表
	m_ilNormal.Create(IDB_NORMAL,16,1,RGB(255,255,255));
	m_wndTree.SetImageList(&m_ilNormal,TVSIL_NORMAL);
	
	// 2 设置节点高度
	m_wndTree.SetItemHeight(25);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTreeCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTreeCtrlDlg::OnPaint()
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
HCURSOR CTreeCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTreeCtrlDlg::OnBnClickedButton1()
{
	// 1 插入根节点
	UpdateData(TRUE);
	m_wndTree.InsertItem(m_strName,0,1);
}


void CTreeCtrlDlg::OnBnClickedButton3()
{
	// 2 插入子节点
	
	UpdateData(TRUE);
	// 1 获取当前选中节点
	HTREEITEM hItem=m_wndTree.GetSelectedItem();
	if (hItem==NULL)return;
	// 2 插入子节点
	m_wndTree.InsertItem(m_strName,0,1,hItem);
	// 3 展开选中节点
	m_wndTree.Expand(hItem,TVE_EXPAND);

}


void CTreeCtrlDlg::OnBnClickedButton2()
{
	// 删除节点
	// 1 获取要删除的节点
	HTREEITEM hItem = m_wndTree.GetSelectedItem();
	if (hItem==NULL)return;
	// 2 判断当前节点下是否有子节点
	if(m_wndTree.ItemHasChildren(hItem))
	{
		AfxMessageBox("请先删除子节点，在删除该节点！");
		return;
	}
	// 3   删除节点
	m_wndTree.DeleteItem(hItem);
}


void CTreeCtrlDlg::OnBnClickedButton4()
{
	// 更新节点
	// 1 获取用户输入
	UpdateData(TRUE);
	// 2 获取当前选中节点
	HTREEITEM hItem=m_wndTree.GetSelectedItem();
	if (hItem==NULL)return;
	// 3 更新节点文本
	m_wndTree.SetItemText(hItem,m_strName);
}
