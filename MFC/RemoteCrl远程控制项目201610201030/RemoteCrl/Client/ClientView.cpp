
// ClientView.cpp : CClientView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Client.h"
#endif

#include "ClientDoc.h"
#include "ClientView.h"
#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CClientView

IMPLEMENT_DYNCREATE(CClientView, CView)

BEGIN_MESSAGE_MAP(CClientView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_MESSAGE(REFRESHSRC, ReFreshScr)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MBUTTONDBLCLK()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CClientView 构造/析构

CClientView::CClientView()
{
	// TODO: 在此处添加构造代码
	ifstart=false;
	src=0;
	des=0;
}

CClientView::~CClientView()
{
	if(ifstart)
	{
	if(src)
		delete []src;
	if(des)
		delete []des;
	closesocket(s);
	WSACloseEvent(hEvent);
	closesocket(s1);
	WSACloseEvent(hEvent1);
	}
}

BOOL CClientView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CClientView 绘制

void CClientView::OnDraw(CDC* pDC)
{
	CClientDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if(!ifstart)
		return;	
	CRect rect;
	GetClientRect(&rect);
	//	pDC=GetDC();
	HDC hdc=pDC->GetSafeHdc();
	
	StretchDIBits(hdc,
		// destination rectangle
		0, 0, rect.Width(), rect.Height(),
		// source rectangle
		0, 0, screen.BmpCX, screen.BmpCY,
		src+screen.BmpInfoSize,
		(BITMAPINFO*)src,
		DIB_RGB_COLORS,
		SRCCOPY);
	// TODO: 在此处为本机数据添加绘制代码
}


// CClientView 打印

BOOL CClientView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CClientView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CClientView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CClientView 诊断

#ifdef _DEBUG
void CClientView::AssertValid() const
{
	CView::AssertValid();
}

void CClientView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CClientDoc* CClientView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClientDoc)));
	return (CClientDoc*)m_pDocument;
}
#endif //_DEBUG


// CClientView 消息处理程序


void CClientView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    if(nChar==VK_ESCAPE)
	{
		if(ifstart)		//KillTimer(1);
			hThreadScreen->SuspendThread();
		CMainFrame *pMain=(CMainFrame*)AfxGetApp()->GetMainWnd();
		::SendMessage(pMain->GetSafeHwnd(),FULLSCREEN,0,0);

		if(ifstart)		//SetTimer(1,10,NULL);
			hThreadScreen->ResumeThread();
		return;
	}
	keymouse.style=PEER_KEY_DOWN;
	keymouse.nkey=nChar;
	PeerSendDataS(s,(char*)&keymouse,sizeof(keymouse),&retLen,
					  hEvent);
}


void CClientView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if(!ifstart)
		return;
	keymouse.style=PEER_KEY_UP;
	keymouse.nkey=nChar;
	PeerSendDataS(s,(char*)&keymouse,sizeof(keymouse),&retLen,
					  hEvent);
}
LRESULT CClientView::ReFreshScr(WPARAM wp, LPARAM lp)
{	
	if(ifstart==0)
		screen.BmpSize=10000;
	else
		screen.BmpSize=0;

	if(!PeerSendDataS(s1,(char*)&screen,sizeof(screen),&retLen1,
					  hEvent1))
	{
		return -1;
	}
	if(!PeerRecvDataS(s1,(char*)&screen,sizeof(screen),&retLen1,
				  hEvent1))
	{
		return -1;
	}
	if(!PeerRecvDataS(s1,(char*)src,screen.BmpSize,&retLen1,
					  hEvent1))
	{
		return -1;
	}
/*	if(!(nTime++%10))
	{
		nTime = 0;
		CPoint point;
		GetCursorPos(&point);
		
		keymouse.style=PEER_CFM_OK;
		float fx,fy;
		CRect rect;
		GetClientRect(&rect);
		fx=(float)point.x/rect.Width();
		fy=(float)point.y/rect.Height();
		keymouse.x=65535*fx;
		keymouse.y=65535*fy;	
		if(!PeerSendDataS(s,(char*)&keymouse,sizeof(keymouse),&retLen, hEvent))
			return;		
	}*/
	Invalidate();
	return 0;
}

BOOL CClientView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(ifstart)
		return false;
	else
		return CView::OnEraseBkgnd(pDC);
}


void CClientView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    if(!ifstart)
		return;
	keymouse.style=PEER_MOUSE_LDBCLICK;
	float fx,fy;
	CRect rect;
	GetClientRect(&rect);
	fx=(float)point.x/rect.Width();
	fy=(float)point.y/rect.Height();
	keymouse.x=65535*fx;
	keymouse.y=65535*fy;	
	PeerSendDataS(s,(char*)&keymouse,sizeof(keymouse),&retLen,
					  hEvent);
}


void CClientView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if(!ifstart)
		return;
	keymouse.style=PEER_MOUSE_LEFTDOWN;
	float fx,fy;
	CRect rect;
	GetClientRect(&rect);
	fx=(float)point.x/rect.Width();
	fy=(float)point.y/rect.Height();
	keymouse.x=65535*fx;
	keymouse.y=65535*fy;	
	PeerSendDataS(s,(char*)&keymouse,sizeof(keymouse),&retLen,
					  hEvent);
}


void CClientView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    if(!ifstart)
		return;
	keymouse.style=PEER_MOUSE_LEFTUP;
	float fx,fy;
	CRect rect;
	GetClientRect(&rect);
	fx=(float)point.x/rect.Width();
	fy=(float)point.y/rect.Height();
	keymouse.x=65535*fx;
	keymouse.y=65535*fy;	
	PeerSendDataS(s,(char*)&keymouse,sizeof(keymouse),&retLen,
					  hEvent);
}


void CClientView::OnMButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if(!ifstart)
		return;
	keymouse.ctrl=PEER_MOUSE_MDBCLICK;
	float fx,fy;
	CRect rect;
	GetClientRect(&rect);
	fx=(float)point.x/rect.Width();
	fy=(float)point.y/rect.Height();
	keymouse.x=65535*fx;
	keymouse.y=65535*fy;	
	PeerSendDataS(s,(char*)&keymouse,sizeof(keymouse),&retLen,
					  hEvent);
}


void CClientView::OnMButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    if(!ifstart)
		return;
	keymouse.ctrl=PEER_MOUSE_MIDDLEDOWN;
	float fx,fy;
	CRect rect;
	GetClientRect(&rect);
	fx=(float)point.x/rect.Width();
	fy=(float)point.y/rect.Height();
	keymouse.x=65535*fx;
	keymouse.y=65535*fy;	
	PeerSendDataS(s,(char*)&keymouse,sizeof(keymouse),&retLen,
					  hEvent);
}


void CClientView::OnMButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(!ifstart)
		return;
	keymouse.ctrl=PEER_MOUSE_MIDDLEUP;
	float fx,fy;
	CRect rect;
	GetClientRect(&rect);
	fx=(float)point.x/rect.Width();
	fy=(float)point.y/rect.Height();
	keymouse.x=65535*fx;
	keymouse.y=65535*fy;	
	PeerSendDataS(s,(char*)&keymouse,sizeof(keymouse),&retLen,
					  hEvent);
}


void CClientView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    if(!ifstart)
		return;
	keymouse.style=PEER_MOUSE_RDBCLICK;
	float fx,fy;
	CRect rect;
	GetClientRect(&rect);
	fx=(float)point.x/rect.Width();
	fy=(float)point.y/rect.Height();
	keymouse.x=65535*fx;
	keymouse.y=65535*fy;	
	PeerSendDataS(s,(char*)&keymouse,sizeof(keymouse),&retLen,
					  hEvent);	
}


void CClientView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    if(!ifstart)
		return;
	keymouse.style=PEER_MOUSE_RIGHTDOWN;
	float fx,fy;
	CRect rect;
	GetClientRect(&rect);
	fx=(float)point.x/rect.Width();
	fy=(float)point.y/rect.Height();
	keymouse.x=65535*fx;
	keymouse.y=65535*fy;	
	PeerSendDataS(s,(char*)&keymouse,sizeof(keymouse),&retLen,
					  hEvent);
}


void CClientView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if(!ifstart)
		return;
	keymouse.style=PEER_MOUSE_RIGHTUP;
	float fx,fy;
	CRect rect;
	GetClientRect(&rect);
	fx=(float)point.x/rect.Width();
	fy=(float)point.y/rect.Height();
	keymouse.x=65535*fx;
	keymouse.y=65535*fy;	
	PeerSendDataS(s,(char*)&keymouse,sizeof(keymouse),&retLen,
					  hEvent);
}


void CClientView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if(!ifstart)
		return;
	keymouse.style=PEER_MOUSE_MOVE;
	float fx,fy;
	CRect rect;
	GetClientRect(&rect);
	fx=(float)point.x/rect.Width();
	fy=(float)point.y/rect.Height();
	keymouse.x=65535*fx;
	keymouse.y=65535*fy;	
	PeerSendDataS(s,(char*)&keymouse,sizeof(keymouse),&retLen,
					  hEvent);
}
