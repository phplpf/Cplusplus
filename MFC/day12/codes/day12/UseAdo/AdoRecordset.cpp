#include "StdAfx.h"
#include "AdoRecordset.h"


CAdoRecordset::CAdoRecordset(void)
{
}


CAdoRecordset::~CAdoRecordset(void)
{
}
BOOL CAdoRecordset::OpenSql(CString strSql,CAdoDatabase* m_db)
{
	// 1 创建记录集对象
	HRESULT nRet = m_pSet.CreateInstance(__uuidof(Recordset));
	if (FAILED(nRet))
	{
		return FALSE;
	}
	// 2 调用Open函数
	nRet = m_pSet->Open(_variant_t(strSql),
		(IDispatch*)m_db->m_pConn,
		adOpenKeyset,adLockOptimistic,adCmdText);
	if (FAILED(nRet))
	{
		return FALSE;
	}
	return TRUE;
}
// 2 获取字段的数量
long CAdoRecordset::GetFieldCount()
{
	return m_pSet->Fields->GetCount();
}
// 3 根据字段的索引值，获取字段的名称
void CAdoRecordset::GetFieldName(long nIndex,CString& strName)
{
	strName = (char*)m_pSet->Fields->GetItem(nIndex)->GetName();
}
// 4 获取字段的值
void CAdoRecordset::GetFieldValue(long nIndex,CString& strValue)
{
	_variant_t varValue= m_pSet->Fields->GetItem(nIndex)->GetValue();
	if (varValue.vt == VT_NULL)
	{
		strValue="";
	} 
	else
	{
		strValue = (char*)(_bstr_t)varValue;
	}
}
// 5 记录集的指针操作
void CAdoRecordset::MoveFirst()
{
	m_pSet->MoveFirst();
}
void CAdoRecordset::MoveNext()
{
	m_pSet->MoveNext();
}
void CAdoRecordset::MovePrevious()
{
	m_pSet->MovePrevious();
}
void CAdoRecordset::MoveLast()
{
	m_pSet->MoveLast();
}
BOOL CAdoRecordset::IsBOF()
{
	return m_pSet->BOF;
}
BOOL CAdoRecordset::IsEOF()
{
	return m_pSet->adoEOF;
}

