
// MFCODBCDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCODBC.h"
#include "MFCODBCDlg.h"
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


// CMFCODBCDlg 对话框




CMFCODBCDlg::CMFCODBCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCODBCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strName = _T("");
	m_nAge = 0;
	m_strAddress = _T("");
	m_strId= _T("");
	m_strClass = _T("");
}

void CMFCODBCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_wndList);
	DDX_Control(pDX, IDC_CLASS, m_wndClass);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_AGE, m_nAge);
	DDX_Text(pDX, IDC_ADDRESS, m_strAddress);
	DDX_CBString(pDX, IDC_CLASS, m_strClass);
}

BEGIN_MESSAGE_MAP(CMFCODBCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_QUERY, &CMFCODBCDlg::OnBnClickedQuery)
	ON_BN_CLICKED(IDC_ADD, &CMFCODBCDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DEL, &CMFCODBCDlg::OnBnClickedDel)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST, &CMFCODBCDlg::OnNMDblclkList)
	ON_BN_CLICKED(IDC_MODIFY, &CMFCODBCDlg::OnBnClickedModify)
END_MESSAGE_MAP()


// CMFCODBCDlg 消息处理程序

BOOL CMFCODBCDlg::OnInitDialog()
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
	// 1 连接数据库
	if (!m_db.Open("testDB"))
	{
		AfxMessageBox("连接数据库失败！");
		return TRUE;
	}
	// 2 初始化班级控件
	InitClassCtrl();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCODBCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCODBCDlg::OnPaint()
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
HCURSOR CMFCODBCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCODBCDlg::OnClose()
{
	// 关闭数据库 
	m_db.Close();
	CDialogEx::OnClose();
}


void CMFCODBCDlg::OnBnClickedQuery()
{
	CRecordset set(&m_db);
	// 1打开记录集
	CString strSql="select s.id as 学员编号,sname as 姓名,age as 年龄,address as 地址,cname as 所在班级 from student s,class c where s.cid=c.id";
	set.Open(CRecordset::forwardOnly,strSql);
	// 添加列之前，先清空控件的原有的列
	while(m_wndList.DeleteColumn(0));
	// 2 获取字段的数量
	long nCount=set.GetODBCFieldCount();
	CODBCFieldInfo info;//保存每个字段的信息(其中包括了字段的名称)
	for (int i=0;i<nCount;i++)
	{
		set.GetODBCFieldInfo(i,info);
		m_wndList.InsertColumn(i,info.m_strName,LVCFMT_LEFT,80);
	}
	// 添加数据之前，需要清空原有数据
	m_wndList.DeleteAllItems();
	CString strValue;
	long nItem=0;
	while(!set.IsEOF())
	{
		for (int i=0;i<nCount;i++)
		{
			set.GetFieldValue(i,strValue);
			if (i == 0)
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


void CMFCODBCDlg::InitClassCtrl(void)
{
	CRecordset set(&m_db);
	set.Open(CRecordset::forwardOnly,"select id,cname from class");
	CString strId;
	CString strName;
	while(!set.IsEOF())
	{
		set.GetFieldValue((short)0,strId);
		set.GetFieldValue(1,strName);
		long nIndex=m_wndClass.AddString(strName);
		m_wndClass.SetItemData(nIndex,atoi(strId));
		set.MoveNext();
	}
}


void CMFCODBCDlg::OnBnClickedAdd()
{
	UpdateData(TRUE);

	int nIndex=m_wndClass.GetCurSel();
	if (nIndex == -1)
	{
		AfxMessageBox("请选择所在班级！");
		return;
	}
	DWORD cid=m_wndClass.GetItemData(nIndex);
	// 向数据库中插入一条记录
	CString strSql;
	//拼接Sql语句(将用户在控件中输入的值组合到Sql语句中)
   strSql.Format("insert into student(sname,age,address,cid) values('%s',%d,'%s',%d)",
	   m_strName,m_nAge,m_strAddress,cid);
   	m_db.ExecuteSQL(strSql);
	// 重新查询
	OnBnClickedQuery();
}


void CMFCODBCDlg::OnBnClickedDel()
{
	POSITION pos = m_wndList.GetFirstSelectedItemPosition();
	if (pos == NULL)return;
	while (pos)
	{
		int nItem = m_wndList.GetNextSelectedItem(pos);
		CString strId=m_wndList.GetItemText(nItem,0);
		CString strSql;
		strSql.Format("delete from student where id=%s",strId);
		m_db.ExecuteSQL(strSql);
	}
	// 重新查询
	OnBnClickedQuery();


}


void CMFCODBCDlg::OnNMDblclkList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	int nItem=pNMItemActivate->iItem;
	if (nItem == -1)return;
	m_strId =m_wndList.GetItemText(nItem,0);//编号
	m_strName = m_wndList.GetItemText(nItem,1);//姓名
	m_nAge = atoi(m_wndList.GetItemText(nItem,2));//年龄
	m_strAddress = m_wndList.GetItemText(nItem,3);//地址
	m_strClass =m_wndList.GetItemText(nItem,4);//班级名称

	UpdateData(FALSE);

	*pResult = 0;
}


void CMFCODBCDlg::OnBnClickedModify()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int nIndex=m_wndClass.GetCurSel();
	if (nIndex == -1)
	{
		AfxMessageBox("请选择所在班级！");
		return;
	}
	DWORD cid=m_wndClass.GetItemData(nIndex);
	CString strSql;
	strSql.Format("update student set sname='%s',age=%d,address='%s',cid=%d where id=%s",
		m_strName,m_nAge,m_strAddress,cid,m_strId);
	m_db.ExecuteSQL(strSql);
	// 重新查询
	OnBnClickedQuery();
}
