// PeerThread.cpp: implementation of the PeerThread.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PeerThread.h"
#include "globalhead.h"
#include "peersocket.h"
#include "CaptureScreen.h"

#include "command.h"
#include "screenctrl.h"

//////////////////////////////////////////////////////////////////////
CONNECTTHREADLIST	listConnectThread;	//客户连接线程列表
UNUSEDTHREADLIST	listUnusedThread;	//不用的线程句柄列表
CRITICAL_SECTION	csProtectList;		//只允许同时一个线程访问这些列表
///////////////////////////////
//接受远程连接的线程
UINT WINAPI AcceptThread(PVOID pParam)
{
	CONNECTTHREAD connectthread;
	HANDLE hNewThread;
	DWORD  dwNewThreadID;
	SOCKET s; 
	SOCKADDR_IN ClientAddr;
	SOCKADDR_IN ClientAddrIn;
	int iAddrLen = sizeof(ClientAddr);
	CONNECTSOCKET ConnectSocketInfo;

	if(!PeerCreateSocket(&s,PEER_STREAM))
	{
		return -1;
	}
	if(!PeerBindSocket(s,szHostAddr,nHostPort))
	{
		PeerCloseSocket(s);
		return -1;
	}
	if(!PeerListenSocket(s))
	{
		PeerCloseSocket(s);
		return -1;
	}

	for(;;)
	{
			SOCKET ClientSocket;
			if(	!PeerAcceptSocket( &ClientSocket, &ClientAddr, s ))
			{
				continue; 
			}
			else
			{
				memcpy(&ClientAddrIn,&ClientAddr,sizeof(SOCKADDR_IN));//地址
				strcpy(ConnectSocketInfo.IP,inet_ntoa(ClientAddrIn.sin_addr));//IP地址
				ConnectSocketInfo.socket=ClientSocket;//socket句柄
				//创建新的服务线程
				if((hNewThread=BeginPeerThread(ServerThread,&ConnectSocketInfo,&dwNewThreadID))==NULL)
					continue;
				else
				{
					connectthread.hThread=hNewThread;
					connectthread.threadID=dwNewThreadID;
					EnterCriticalSection(&csProtectList);
					listConnectThread.push_back(connectthread);//将服务器线程信息保存到链表中
					LeaveCriticalSection(&csProtectList);
				}
			}
		
	}
	PeerCloseSocket(s);
	return 0;
}
/////////////////////////////////
//服务线程
/////////////////////////////////
UINT WINAPI ServerThread(PVOID pParam)
{
	/////得到连接的socket//////
	CONNECTSOCKET SocketInfo;
	SocketInfo=*(CONNECTSOCKET*)pParam;
	SOCKET s;
	s=SocketInfo.socket;

	DWORD retLen; //返回数据长度
	COMMAND command;//命令头
	
	///////////////////////////////////

	memset((char*)&command,0,sizeof(COMMAND));
	if(!PeerRecvDataS(s,(char*)&command,sizeof(command),&retLen))
	{
		PeerCloseSocket(s);
		DeleteThread(CUR_THREADID);
		return 0;
	}
	switch(command.CommandID)
	{
		case PEER_KEYMOUSE:
			PeerScreenMouseKey(s);
			break;
		case PEER_SCREEN_GET:
			PeerScreenGet(s);
			CleanScreenInfo();
			break;

	}
	PeerShutDownSocket(s);
	PeerCloseSocket(s);
	DeleteThread(CUR_THREADID);
	return 0;
}

/////////////////////////////
//清理已经完成操作的线程的线程
UINT WINAPI CleanupThread(PVOID pParam)
{
	UNUSEDTHREADLIST::iterator it;
	for(;;)
	{
		if(WaitForSingleObject(hExitEvent, PEER_CLEANTHREADTIME)==WAIT_TIMEOUT)
		{
			EnterCriticalSection(&csProtectList);
			while(listUnusedThread.size())
			{	
				HANDLE h = listUnusedThread.front(); 
				DWORD n = WaitForSingleObject(h,PEER_KILLTHREADTIME);
				if(n==WAIT_TIMEOUT)
				{
					TerminateThread(h,0);
				}
				CloseHandle(h);
				listUnusedThread.pop_front();
			}
			LeaveCriticalSection(&csProtectList);
		}
		else
			return 0;
	}
	return 0;
}
///////////////////////////
///删除已经执行完成线程句柄
void DeleteThread(DWORD dwThreadID)
{
	CONNECTTHREADLIST::iterator it;
	it=find_if(listConnectThread.begin(),listConnectThread.end(),bind2nd(IDCompare(),dwThreadID));
	if(it!=listConnectThread.end())
	{
		EnterCriticalSection(&csProtectList);
		listUnusedThread.push_back((*it).hThread);
		listConnectThread.erase(it);
		LeaveCriticalSection(&csProtectList);
	}
}
////////////////////////////////////////////////////////////

