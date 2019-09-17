
// MFCDrawView.cpp : CMFCDrawView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCDraw.h"
#endif

#include "MFCDrawDoc.h"
#include "MFCDrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDrawView

IMPLEMENT_DYNCREATE(CMFCDrawView, CView)

BEGIN_MESSAGE_MAP(CMFCDrawView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DC, &CMFCDrawView::OnDc)
	ON_COMMAND(ID_DC_CLIENT, &CMFCDrawView::OnDcClient)
	ON_WM_PAINT()
	ON_COMMAND(ID_GDI_PEN, &CMFCDrawView::OnGdiPen)
	ON_COMMAND(ID_GDI_BRUSH, &CMFCDrawView::OnGdiBrush)
	ON_COMMAND(ID_GDI_FONT, &CMFCDrawView::OnGdiFont)
	ON_COMMAND(ID_GDI_BMP, &CMFCDrawView::OnGdiBmp)
	ON_COMMAND(ID_GDI_RGN, &CMFCDrawView::OnGdiRgn)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CMFCDrawView 构造/析构

CMFCDrawView::CMFCDrawView()
{
	// TODO: 在此处添加构造代码

}

CMFCDrawView::~CMFCDrawView()
{
}

BOOL CMFCDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCDrawView 绘制

void CMFCDrawView::OnDraw(CDC* /*pDC*/)
{
	CMFCDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCDrawView 打印

BOOL CMFCDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCDrawView 诊断

#ifdef _DEBUG
void CMFCDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDrawDoc* CMFCDrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDrawDoc)));
	return (CMFCDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCDrawView 消息处理程序


void CMFCDrawView::OnDc()
{
	// CDC类的使用
	// 1 创建DC
	CDC dc;
	dc.CreateDC("DISPLAY",NULL,NULL,NULL);
	// 2 使用DC。。。
	dc.TextOut(0,0,"Hello CDC");
	// 3 删除DC
	dc.DeleteDC();
}


void CMFCDrawView::OnDcClient()
{
	// CClientDC的使用
	CClientDC dc(this);
	dc.TextOut(0,0,"Hello CClientDC");

}


void CMFCDrawView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	dc.TextOut(0,100,"Hello CPaintDC");
	//OnGdiBmp();
}


void CMFCDrawView::OnGdiPen()
{
	// 画笔
	CPen pen(PS_DASHDOT ,0,RGB(255,0,0));
	CClientDC dc(this);
	CPen *pOldPen = dc.SelectObject(&pen);
	dc.Rectangle(100,100,300,300);
	dc.SelectObject(pOldPen);
	pen.DeleteObject();

}


void CMFCDrawView::OnGdiBrush()
{
	// 画刷 (颜色、阴影、位图)
	//CBrush brush(HS_CROSS ,RGB(0,0,255));
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
    CBrush brush(&bmp);
	CClientDC dc(this);
	CBrush* pOldBrush= dc.SelectObject(&brush);
	dc.Rectangle(100,100,500,500);
	dc.SelectObject(pOldBrush);
	brush.DeleteObject();
}
void CMFCDrawView::OnGdiFont()
{
	// 字体(CFont font;font.CreatePointFont(,""))
	CFont font;
	font.CreatePointFont(1000,"黑体");
	CClientDC dc(this);
	CFont* pOldFoint = dc.SelectObject(&font);
	dc.TextOut(100,100,"Hello CFont");
	dc.SelectObject(pOldFoint);
	font.DeleteObject();
}


void CMFCDrawView::OnGdiBmp()
{
	// 位图
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP2);
	CClientDC dc(this);
	CDC dcBmp;
	dcBmp.CreateCompatibleDC(&dc);
	dcBmp.SelectObject(&bmp);
	//dc.BitBlt(0,0,216,144,&dcBmp,0,0,SRCCOPY);
	CRect rt;
	GetClientRect(&rt);
	dc.StretchBlt(0,0,rt.Width(),rt.Height(),&dcBmp,0,0,216,144,SRCCOPY);
	dcBmp.DeleteDC();
	bmp.DeleteObject();
}


void CMFCDrawView::OnGdiRgn()
{
	// 区域(几何运算)
	// 1 创建区域
	CRgn rgn1,rgn2;
	rgn1.CreateEllipticRgn(100,100,300,300);
	rgn2.CreateEllipticRgn(200,100,400,300);
	// 2 几何运算
	rgn1.CombineRgn(&rgn1,&rgn2,RGN_AND);
	// 3 填充区域
	CClientDC dc(this);
	CBrush brush(RGB(0,0,255));
	dc.FillRgn(&rgn1,&brush);
}


BOOL CMFCDrawView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//return FALSE;
	return CView::OnEraseBkgnd(pDC);
}
