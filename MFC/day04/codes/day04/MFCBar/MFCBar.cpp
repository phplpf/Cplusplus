#include <afxwin.h>
#include "resource.h"
#include <afxext.h>//扩展窗口的头文件

//定义状态指示器数组
UINT gIndicators[]=
{
	0,
	IDS_TIME,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_OVR
};
// 1 框架窗口类
class CMyFrameWnd:public CFrameWnd
{
DECLARE_MESSAGE_MAP()
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer( UINT nIDEvent );
	afx_msg void OnMouseMove( UINT nFlags, CPoint point );
	afx_msg void OnNew();
	afx_msg void OnExit();
	afx_msg void OnTool();
	CToolBar m_wndToolbar;//工具栏对象
	CStatusBar m_wndStatus;//状态栏对象
};
BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_WM_CREATE( )
	ON_COMMAND(ID_NEW,OnNew)
	ON_COMMAND(ID_EXIT,OnExit)
	ON_COMMAND(ID_TOOL,OnTool)
	ON_WM_TIMER()
	ON_WM_MOUSEMOVE( )
END_MESSAGE_MAP( )
void CMyFrameWnd::OnMouseMove( UINT nFlags, CPoint point )
{
	// 1 将二维的点坐标格式化为字符串类型
	CString strPt;
	strPt.Format("X=%d,Y=%d 像素",point.x,point.y);
	// 2 将字符串表示的位置放到状态栏中显式
	m_wndStatus.SetPaneText(0,strPt);
}
void CMyFrameWnd::OnTimer( UINT nIDEvent )
{
	// 1 获取当前系统时间
	CTime t= CTime::GetCurrentTime();
	// 2 将时间对象转换为字符串类型
	CString strTime = t.Format("%Y-%m-%d %H:%M:%S");
	// 3 将字符串表示的时间放到状态栏中显式
	m_wndStatus.SetPaneText(1,strTime);
}
void CMyFrameWnd::OnTool()
{
	if (m_wndToolbar.IsVisible())
	{
		ShowControlBar(&m_wndToolbar,FALSE,FALSE);
	}
	else
	{
		ShowControlBar(&m_wndToolbar,TRUE,FALSE);
	}
}
void CMyFrameWnd::OnNew()
{
	AfxMessageBox("OnNew");
}
void CMyFrameWnd::OnExit()
{
	PostQuitMessage(0);
}
int CMyFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	// 工具栏
	// 1 创建工具栏窗口
	m_wndToolbar.Create(this,WS_VISIBLE|WS_CHILD|CBRS_GRIPPER|CBRS_TOOLTIPS|CBRS_FLYBY);
	// 2 加载工具栏资源
	m_wndToolbar.LoadToolBar(IDR_TOOLBAR1);
	// 3 停靠工具栏
	// 3.1 设置工具栏允许停靠
	m_wndToolbar.EnableDocking(CBRS_ALIGN_ANY );
	// 3.2 设置框架窗口允许被停靠
	EnableDocking(CBRS_ALIGN_ANY );
	// 3.3 停靠工具栏
	DockControlBar(&m_wndToolbar,AFX_IDW_DOCKBAR_TOP);

	// 4 设置工具栏窗口标题
	m_wndToolbar.SetWindowText("标准工具栏");

	// 状态栏
	// 1 创建状态栏窗口
	m_wndStatus.Create(this);
	// 2 设置状态栏指示器
	m_wndStatus.SetIndicators(gIndicators,sizeof(gIndicators)/sizeof(UINT));

	// 设置定时器
	SetTimer(1,1000,NULL);
	return 0;
}

// 2 应用程序类
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame=new CMyFrameWnd;
	pFrame->LoadFrame(IDR_MENU1);
	m_pMainWnd=pFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}