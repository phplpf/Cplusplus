#pragma once
class CAdoDatabase
{
public:
	CAdoDatabase(void);
	~CAdoDatabase(void);
	BOOL OpenAccess(CString strPath);
	void Close();
	// 执行Sql语句的功能
	void ExecuteSQL(CString strSql);

public:
	_ConnectionPtr m_pConn;
};

