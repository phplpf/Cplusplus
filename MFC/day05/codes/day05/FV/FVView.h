
// FVView.h : CFVView 类的接口
//

#pragma once

#include "resource.h"


class CFVView : public CFormView
{
protected: // 仅从序列化创建
	CFVView();
	DECLARE_DYNCREATE(CFVView)

public:
	enum{ IDD = IDD_FV_FORM };

// 特性
public:
	CFVDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CFVView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // FVView.cpp 中的调试版本
inline CFVDoc* CFVView::GetDocument() const
   { return reinterpret_cast<CFVDoc*>(m_pDocument); }
#endif

