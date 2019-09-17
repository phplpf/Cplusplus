#include <afxwin.h>

class CMyFrameWnd:public CFrameWnd
{
//public:
//	virtual LRESULT WindowProc( UINT message, WPARAM wParam, LPARAM lParam );
protected:
	afx_msg LRESULT OnCreate(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT OnPaint(WPARAM wParam,LPARAM lParam);
//DECLARE_MESSAGE_MAP()
protected: 
	static const AFX_MSGMAP* PASCAL GetThisMessageMap(); 
	virtual const AFX_MSGMAP* GetMessageMap() const; 
};
/*
BEGIN_MESSAGE_MAP(CMyFrameWnd,CFrameWnd)
	ON_MESSAGE(WM_CREATE,OnCreate)
	ON_MESSAGE(WM_PAINT,OnPaint)
END_MESSAGE_MAP( )
*/
PTM_WARNING_DISABLE 
const AFX_MSGMAP* CMyFrameWnd::GetMessageMap() const 
{ 
	return GetThisMessageMap(); 
} 
const AFX_MSGMAP* PASCAL CMyFrameWnd::GetThisMessageMap() 
{ 
	// 1 给类取别名
	typedef CMyFrameWnd ThisClass;						   
	typedef CFrameWnd TheBaseClass;
	// 2 
	static const AFX_MSGMAP_ENTRY _messageEntries[] =  
	{
		
		{ WM_CREATE, 0, 0, 0, AfxSig_lwl, 
		(AFX_PMSG)(AFX_PMSGW) 
		(static_cast< LRESULT (AFX_MSG_CALL CWnd::*)(WPARAM, LPARAM) > 
		(OnCreate)) },
		{ WM_PAINT, 0, 0, 0, AfxSig_lwl, 
		(AFX_PMSG)(AFX_PMSGW) 
		(static_cast< LRESULT (AFX_MSG_CALL CWnd::*)(WPARAM, LPARAM) > 
		(OnPaint)) },
		
		{0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0 } //不是有效元素，表示结束。
	}; 
	// 3 类似于单向链表的节点定义
	static const AFX_MSGMAP messageMap = 
	{ 
		&TheBaseClass::GetThisMessageMap, //函数指针指向父类的GetThisMessageMap函数
	    &_messageEntries[0] //保存数组地址
	}; 
	// 4 
	return &messageMap; 
}								  
PTM_WARNING_RESTORE

LRESULT CMyFrameWnd::OnCreate(WPARAM wParam,LPARAM lParam)
{
	AfxMessageBox("CMyFrameWnd::OnCreate");
	return 0;
}
LRESULT CMyFrameWnd::OnPaint(WPARAM wParam,LPARAM lParam)
{
	PAINTSTRUCT ps={0};
	CDC* pDC=BeginPaint(&ps);
	pDC->TextOut(100,100,"Hello World");
	EndPaint(&ps);
	return 0;
}
class CMyWinApp:public CWinApp
{
public: 
	virtual BOOL InitInstance();
};
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance()
{
	CMyFrameWnd* pFrame=new CMyFrameWnd;
	pFrame->Create(NULL,"MFCMsg");
	m_pMainWnd=pFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}