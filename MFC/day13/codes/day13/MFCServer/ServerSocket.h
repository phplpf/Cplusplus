#pragma once

// CServerSocket 命令目标

class CServerSocket : public CSocket
{
public:
	CServerSocket();
	virtual ~CServerSocket();
    // 1 初始化服务器
	BOOL InitServer(UINT nPort);
	// 2 接收文件(放到事件处理函数中)
	virtual void OnAccept(int nErrorCode);
	// 3 接收数据
	BOOL RecvData(CSocket& client,BYTE* pData,long nLen);
	
};


