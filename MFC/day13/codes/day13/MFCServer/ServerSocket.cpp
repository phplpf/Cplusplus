// ServerSocket.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCServer.h"
#include "ServerSocket.h"


// CServerSocket

CServerSocket::CServerSocket()
{
}

CServerSocket::~CServerSocket()
{
}


// 1 初始化服务器(创建、绑定和监听)
BOOL CServerSocket::InitServer(UINT nPort)
{
	// 1 2 创建、绑定
	if (!Create(nPort))
	{
		return FALSE;
	}
	// 3 监听
	return Listen();
}
// CServerSocket 成员函数

typedef struct _tagHeader{
	char szName[256];//文件名称
	long nLen;//文件长度
}HEADER,*LPHEADER;
BOOL CServerSocket::RecvData(CSocket& client,BYTE* pData,long nLen)
{
	long nLeft = nLen;//剩余的还没有接收的数据的长度
	BYTE* pTmpData=pData;//临时的指针
	while ( nLeft > 0 )
	{
		int nRecv = client.Receive(pTmpData,nLeft);
		if (nRecv==SOCKET_ERROR)
		{
			return FALSE;
		}
		nLeft = nLeft-nRecv;
		pTmpData = pTmpData+nRecv;
	}
	return TRUE;
	
}
void CServerSocket::OnAccept(int nErrorCode)

{
	// 4 接收客户端连接
	CSocket client;
	Accept(client);
	// 5 通信(接收文件)
	// 5.1 先接收文件信息(文件长度和文件的名称)
	HEADER header={0};
	RecvData(client,(BYTE*)&header,sizeof(header));
	// 5.2 然后，再接收文件内容
	BYTE* pData=(BYTE*)malloc(header.nLen);
	RecvData(client,pData,header.nLen);
	// 5.3 最后，将文件保存到服务器
	CFile file;
	CString strPath="d:/";
	strPath+=header.szName;
	file.Open(strPath,CFile::modeCreate|CFile::modeWrite);
	file.Write(pData,header.nLen);
	file.Close();
	free(pData);
	// 6 关闭套接字
	client.Close();
	CSocket::OnAccept(nErrorCode);
}
