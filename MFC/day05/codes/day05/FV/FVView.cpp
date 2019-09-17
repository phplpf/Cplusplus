
// FVView.cpp : CFVView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "FV.h"
#endif

#include "FVDoc.h"
#include "FVView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFVView

IMPLEMENT_DYNCREATE(CFVView, CFormView)

BEGIN_MESSAGE_MAP(CFVView, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CFVView 构造/析构

CFVView::CFVView()
	: CFormView(CFVView::IDD)
{
	// TODO: 在此处添加构造代码

}

CFVView::~CFVView()
{
}

void CFVView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CFVView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void CFVView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();

}

void CFVView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFVView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFVView 诊断

#ifdef _DEBUG
void CFVView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFVView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFVDoc* CFVView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFVDoc)));
	return (CFVDoc*)m_pDocument;
}
#endif //_DEBUG


// CFVView 消息处理程序
