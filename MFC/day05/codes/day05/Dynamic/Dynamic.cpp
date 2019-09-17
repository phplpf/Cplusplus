#include <afxwin.h>
#include <stdio.h>

// 定义支持运行时类信息的类
class CAnimal:public CObject
{
	DECLARE_DYNAMIC(CAnimal)
};
IMPLEMENT_DYNAMIC(CAnimal,CObject)

class CDog:public CAnimal
{
	//DECLARE_DYNAMIC(CDog)
public: 
	static const CRuntimeClass classCDog; 
	virtual CRuntimeClass* GetRuntimeClass() const; 
};
//IMPLEMENT_DYNAMIC(CDog,CAnimal)
//IMPLEMENT_RUNTIMECLASS(CDog, CAnimal, 0xFFFF, NULL, NULL)
AFX_COMDAT const CRuntimeClass CDog::classCDog = 
{ 
	"CDog", //类名
	sizeof(class CDog), //大小
	0xFFFF, //版本
	NULL, 
	 ((CRuntimeClass*)(&CAnimal::classCAnimal)),//下一个节点的地址（节点在父类）
	//RUNTIME_CLASS(CAnimal), 
	NULL, 
	NULL 
}; 
CRuntimeClass* CDog::GetRuntimeClass() const 
{ 
	//return RUNTIME_CLASS(CDog);
	return ((CRuntimeClass*)(&CDog::classCDog));
}


int main()
{
	// 1 获取并打印对象的类信息
	CDog dog;
	CRuntimeClass* pClass=dog.GetRuntimeClass();
	printf("类的名称：%s,类的大小：%d,类的版本:%d\n",
		pClass->m_lpszClassName,pClass->m_nObjectSize,pClass->m_wSchema);
	// 2 判断对象是否属于某个类
	if (dog.IsKindOf(RUNTIME_CLASS(CWnd)))
	{
		printf("dog is a CWnd\n");
	} 
	else
	{
		printf("dog is not a CWnd\n");
	}
	return 0;
}