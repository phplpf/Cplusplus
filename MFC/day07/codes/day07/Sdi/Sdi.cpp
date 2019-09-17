#include <afxwin.h>
#include "resource.h"
#include <afxext.h>//CEditView

class CMyDoc:public CDocument
{
	DECLARE_DYNCREATE(CMyDoc)
};
IMPLEMENT_DYNCREATE(CMyDoc,CDocument)
class CMyView:public CEditView
{
	DECLARE_DYNCREATE(CMyView)
};
IMPLEMENT_DYNCREATE(CMyView,CEditView)
class CMyFrameWnd:public CFrameWnd
{
	DECLARE_DYNCREATE(CMyFrameWnd)
};
IMPLEMENT_DYNCREATE(CMyFrameWnd,CFrameWnd)
class CMyWinApp:public CWinApp
{
public:
	virtual BOOL InitInstance();
};
CMyWinApp theApp;
BOOL CMyWinApp::InitInstance()
{
	
	CSingleDocTemplate* pTemplate=new CSingleDocTemplate(
		IDR_MENU1,RUNTIME_CLASS(CMyDoc),
		RUNTIME_CLASS(CMyFrameWnd),RUNTIME_CLASS(CMyView));
	AddDocTemplate(pTemplate);
	OnFileNew();
	/*
	int a = 0;
	ASSERT(a==0);
	//以下代码可能要求a的值为0
	*/

	return TRUE;
}