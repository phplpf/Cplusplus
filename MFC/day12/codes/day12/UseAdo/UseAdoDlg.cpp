
// UseAdoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "UseAdo.h"
#include "UseAdoDlg.h"
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


// CUseAdoDlg 对话框




CUseAdoDlg::CUseAdoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUseAdoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strName = _T("");
	m_nAge = 0;
	m_strAddress = _T("");
	m_strClass = _T("");
	m_strId =  _T("");
}

void CUseAdoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_wndList);
	DDX_Control(pDX, IDC_CLASS, m_wndClass);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_AGE, m_nAge);
	DDX_Text(pDX, IDC_ADDRESS, m_strAddress);
	DDX_CBString(pDX, IDC_CLASS, m_strClass);
}

BEGIN_MESSAGE_MAP(CUseAdoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_QUERY, &CUseAdoDlg::OnBnClickedQuery)
	ON_BN_CLICKED(IDC_ADD, &CUseAdoDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DEL, &CUseAdoDlg::OnBnClickedDel)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, &CUseAdoDlg::OnNMDblclkList)
	ON_BN_CLICKED(IDC_MODIFY, &CUseAdoDlg::OnBnClickedModify)
END_MESSAGE_MAP()


// CUseAdoDlg 消息处理程序

BOOL CUseAdoDlg::OnInitDialog()
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

	// 1 连接数据库
	if (!m_db.OpenAccess("E:/c++1905/stuDB.accdb"))
	{
		AfxMessageBox("数据库连接失败");
		PostQuitMessage(0);
	}
	// 2 初始化班级控件
	InitClassCtrl();
	// 3 列表控件扩展风格(选中整行)
	m_wndList.SetExtendedStyle(m_wndList.GetExtendedStyle()|LVS_EX_FULLROWSELECT);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CUseAdoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUseAdoDlg::OnPaint()
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
HCURSOR CUseAdoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CUseAdoDlg::OnBnClickedQuery()
{
	// 清空控件的行和列
	while(m_wndList.DeleteColumn(0));
	m_wndList.DeleteAllItems();
	
	CAdoRecordset set;
	// 打开记录集
	CString strSql="select s.id as 学员编号,sname as 姓名,age as 年龄,address as 地址,cname as 班级名称 from student s,class c where s.cid = c.id";

	set.OpenSql(strSql,&m_db);
	long nCount=set.GetFieldCount();
	CString strName;
	for (int i=0;i<nCount;i++)
	{
		set.GetFieldName(i,strName);
		m_wndList.InsertColumn(i,strName,LVCFMT_LEFT,80);
	}
	//读取字段的值放到列表控件中显式(10分钟)
	CString strValue;
	long nItem=0;
	while (!set.IsEOF())
	{
		for (long i=0;i<nCount;i++)
		{
			set.GetFieldValue(i,strValue);
			if (i==0)
			{
				m_wndList.InsertItem(nItem,strValue);
			} 
			else
			{
				m_wndList.SetItemText(nItem,i,strValue);
			}
		}
		nItem++;
		set.MoveNext();
	}


}


void CUseAdoDlg::InitClassCtrl(void)
{
	CAdoRecordset set;
	set.OpenSql("select id,cname from class",&m_db);
	CString strName;
	CString strId;
	while(!set.IsEOF())
	{
		set.GetFieldValue(0,strId);
		set.GetFieldValue(1,strName);
		long nIndex = m_wndClass.AddString(strName);
		m_wndClass.SetItemData(nIndex,atoi(strId));
		set.MoveNext();
	}
}


void CUseAdoDlg::OnBnClickedAdd()
{
	InsertOrUpdate();
}


void CUseAdoDlg::OnBnClickedDel()
{
	// 删除操作
	POSITION pos =m_wndList.GetFirstSelectedItemPosition();
	if (pos == NULL)return;
	while (pos)
	{
		int nItem =m_wndList.GetNextSelectedItem(pos);
		CString strId=m_wndList.GetItemText(nItem,0);
		CString strSql;
		strSql.Format("delete from student where id=%s",strId);
		m_db.ExecuteSQL(strSql);
	}
	// 重新查询
	OnBnClickedQuery();


}


void CUseAdoDlg::OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	long nItem=pNMItemActivate->iItem;
	if (nItem==-1)return;
	m_strId = m_wndList.GetItemText(nItem,0);//学员编号
	m_strName = m_wndList.GetItemText(nItem,1);//姓名
	m_nAge =atoi(m_wndList.GetItemText(nItem,2)) ;//年龄
	m_strAddress = m_wndList.GetItemText(nItem,3);//地址
	m_strClass = m_wndList.GetItemText(nItem,4);//所在班级
	UpdateData(FALSE);

	*pResult = 0;
}


void CUseAdoDlg::OnBnClickedModify()
{
	InsertOrUpdate(FALSE);
}


void CUseAdoDlg::InsertOrUpdate(BOOL IsInsert)
{
	UpdateData(TRUE);

	int nIndex=m_wndClass.GetCurSel();
	if (nIndex == -1)
	{
		AfxMessageBox("请选择所在班级！");
		return;
	}
	DWORD cid=m_wndClass.GetItemData(nIndex);

	CString strSql;
	if (IsInsert)
	{
		strSql.Format("insert into student(sname,age,address,cid) values('%s',%d,'%s',%d)",
			m_strName,m_nAge,m_strAddress,cid);
	} 
	else
	{
		strSql.Format("update student set sname='%s',age=%d,address='%s',cid=%d where id=%s",
			m_strName,m_nAge,m_strAddress,cid,m_strId);
	}
	m_db.ExecuteSQL(strSql);
	// 重新查询
	OnBnClickedQuery();
}
