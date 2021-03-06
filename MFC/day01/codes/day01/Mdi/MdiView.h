
// MdiView.h : CMdiView 类的接口
//

#pragma once


class CMdiView : public CEditView
{
protected: // 仅从序列化创建
	CMdiView();
	DECLARE_DYNCREATE(CMdiView)

// 特性
public:
	CMdiDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMdiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MdiView.cpp 中的调试版本
inline CMdiDoc* CMdiView::GetDocument() const
   { return reinterpret_cast<CMdiDoc*>(m_pDocument); }
#endif

