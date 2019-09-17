#pragma once
#include "AdoDatabase.h"
class CAdoRecordset
{
public:
	CAdoRecordset(void);
	~CAdoRecordset(void);
	// 1 打开记录集
	BOOL OpenSql(CString strSql,CAdoDatabase* m_db);
	// 2 获取字段的数量
	long GetFieldCount();
	// 3 根据字段的索引值，获取字段的名称
	void GetFieldName(long nIndex,CString& strName);
	// 4 获取字段的值
	void GetFieldValue(long nIndex,CString& strValue);
	// 5 记录集的指针操作
	void MoveFirst();
	void MoveNext();
	void MovePrevious();
	void MoveLast();
	BOOL IsBOF();
	BOOL IsEOF();
public:
	_RecordsetPtr m_pSet;
};

