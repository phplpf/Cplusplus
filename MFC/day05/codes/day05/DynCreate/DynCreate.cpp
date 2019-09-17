#include <afxwin.h>
#include <stdio.h>


// CreateInstance函数创建哪个类的对象？？？RUNTIME_CLASS(类名)
// 创建对象的函数
CObject* CreateInstance(CRuntimeClass* pClass)
{
	return pClass->CreateObject();
}

class CAnimal:public CObject
{
	DECLARE_DYNCREATE(CAnimal)
};
IMPLEMENT_DYNCREATE(CAnimal,CObject)

class CDog:public CAnimal
{
	//DECLARE_DYNCREATE(CDog)
	//DECLARE_DYNAMIC(CDog) 
public: 
	static const CRuntimeClass classCDog; 
	virtual CRuntimeClass* GetRuntimeClass() const; 
	static CObject* PASCAL CreateObject();
};
//IMPLEMENT_DYNCREATE(CDog,CAnimal)
CObject* PASCAL CDog::CreateObject() 
{ 
	return new CDog; 
} 
AFX_COMDAT const CRuntimeClass CDog::classCDog = 
{ 
	"CDog", //类名
	sizeof(class CDog), //大小
	0xFFFF, //版本
	CDog::CreateObject, 
	((CRuntimeClass*)(&CAnimal::classCAnimal)),
	NULL, 
	NULL 
}; 
CRuntimeClass* CDog::GetRuntimeClass() const 
{ 
	return ((CRuntimeClass*)(&CDog::classCDog));
}
int main()
{
	
	CObject* pObj=NULL;
	pObj=CreateInstance(RUNTIME_CLASS(CDog));
	if (pObj!=NULL)
	{
		printf("对象地址：%p\n",pObj);
		printf("类名：%s\n",pObj->GetRuntimeClass()->m_lpszClassName);
		delete pObj;
		pObj = NULL;

	}
	return 0;
}