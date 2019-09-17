
// MainFrm.h : CMainFrame 类的接口
//

#pragma once

#include "TrueColorToolBar.h"

#define FULLSCREEN WM_USER+10011
class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:
	BOOL	m_start;
	WINDOWPLACEMENT m_OldWndPlacement;	//用来保存原窗口位置 
	BOOL m_bFullScreen;					//全屏显示标志 
	CRect m_FullScreenRect;				//表示全屏显示时的窗口位置 
// 操作
public:
	void FullScreenShow(BOOL flag);
	static UINT OnRrefreshScreen(LPVOID lparam) ;//线程处理函数
// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar        m_wndStatusBar;
	CTrueColorToolBar    m_wndToolBar;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnToolStart();
	afx_msg void OnToolFullscreen();
	afx_msg void OnToolDisconnect();
	afx_msg void OnToolExit();
	afx_msg LRESULT OnFullScreen(WPARAM wp,LPARAM lp);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
};


