// ClientSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCClient.h"
#include "ClientSocket.h"


// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket 成员函数
// 1 初始化客户端(连接服务器)
BOOL CClientSocket::InitClient(char* IP,UINT nPort)
{
	if (!Create())
	{
		return FALSE;
	}
	return Connect(IP,nPort);
}

typedef struct _tagHeader{
	char szName[256];//文件名称
	long nLen;//文件长度
}HEADER,*LPHEADER;

// 2 发送文件
BOOL CClientSocket::SendFile(CString strPath)
{
    // 1 读取文件
	CFile file;
	file.Open(strPath,CFile::modeRead);
	CString strName=file.GetFileName();
	long nLen=file.GetLength();
	// 2 发送文件信息
	HEADER header={0};
	header.nLen = nLen;
	strcpy(header.szName,strName);
	SendData((BYTE*)&header,sizeof(header));
	// 3 发送文件数据
	BYTE* pData=(BYTE*)malloc(nLen);
	file.Read(pData,nLen);
	SendData(pData,nLen);
	file.Close();
	free(pData);
	// 4 关闭socket
	Close();
	return TRUE;
}
// 3 发送数据
BOOL CClientSocket::SendData(BYTE* pData,long nLen)
{
	BYTE* pTmpData = pData;
	long nLeft = nLen;
	while(nLeft>0)
	{
		int nSend=Send(pTmpData,nLeft);
		if (nSend == SOCKET_ERROR)
		{
			return FALSE;
		}
		nLeft -= nSend;
		pTmpData+=nSend;
	}
	return TRUE;
}