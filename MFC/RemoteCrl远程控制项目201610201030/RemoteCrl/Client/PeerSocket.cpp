// PeerSocket.cpp: implementation of the PeerSocket.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PeerSocket.h"

//////////////////////////////////////////////////////////////////////
bool PeerCreateSocket(SOCKET *pNewSocket,int iSockType)
{
	SOCKET socket;
	return ((socket=WSASocket(AF_INET,iSockType,0,NULL,0,WSA_FLAG_OVERLAPPED))==INVALID_SOCKET)?
		false:*pNewSocket=socket,true;
}

bool PeerBindSocket(SOCKET BindSocket,char *szHostAddr,int iHostPort)
{
	struct sockaddr_in inAddr;
	inAddr.sin_addr.S_un.S_addr=inet_addr(szHostAddr);
	inAddr.sin_family=AF_INET;
	inAddr.sin_port=htons(iHostPort);
	return (bind(BindSocket,(PSOCKADDR)&inAddr,sizeof(inAddr))==SOCKET_ERROR)?
		false:true;
}
bool PeerConnectSocket(SOCKET BindSocket,char *szHostAddr,int iHostPort)
{
	struct sockaddr_in inAddr;
	inAddr.sin_addr.S_un.S_addr=inet_addr(szHostAddr);
	inAddr.sin_family=AF_INET;
	inAddr.sin_port=htons(iHostPort);
	return (connect(BindSocket,(PSOCKADDR)&inAddr,sizeof(inAddr))==SOCKET_ERROR)?
		false:true;
}
bool PeerListenSocket(SOCKET ListenSocket)
{
	return (listen(ListenSocket, 5))?
		false:true;
}

bool PeerShutDownSocket(SOCKET nowSocket)
{
	return shutdown(nowSocket,SD_BOTH)?false:true;
}

bool PeerCloseSocket(SOCKET nowSocket)
{
	return (closesocket(nowSocket)==SOCKET_ERROR)?
		false:true;
}
//重叠模式发送数据
bool PeerSendData(SOCKET socket,char *data,DWORD len,DWORD *retlen,WSAEVENT hSendEvent,DWORD time)
{
	WSABUF DataBuf;
	WSAEVENT hEvents[2];
	WSAOVERLAPPED SendOverLapp;
	DWORD flag;

	hEvents[0]=hExitEvent;
	hEvents[1]=hSendEvent;
	DataBuf.buf=data;
	DataBuf.len=len;
	memset(&SendOverLapp,0,sizeof(WSAOVERLAPPED));
	SendOverLapp.hEvent=hSendEvent;
	flag=0;
	/////////////////////////////////////
	int ret;
	if((ret=WSASend(socket,&DataBuf,1,retlen,flag,&SendOverLapp,NULL))==0)
		return true;
	else if((ret==SOCKET_ERROR)&&(WSAGetLastError()==WSA_IO_PENDING))
	{
		DWORD EventCaused=WSAWaitForMultipleEvents(2,hEvents,FALSE,time,FALSE);
		WSAResetEvent(hSendEvent);
		if(EventCaused == WSA_WAIT_FAILED || EventCaused == WAIT_OBJECT_0)
		{
			return false;
		}
		flag=0;
		return (WSAGetOverlappedResult(socket,&SendOverLapp,retlen,false,&flag))?
			true:false;
	}
	else
		return false;
}
//重叠模式接受数据
bool PeerRecvData(SOCKET socket,char *data,DWORD len,DWORD *retlen,WSAEVENT hRecvEvent,DWORD time)
{
	WSABUF DataBuf;
	WSAEVENT hEvents[2];
	WSAOVERLAPPED RecvOverLapp;
	DWORD flag;

	hEvents[0]=hExitEvent;
	hEvents[1]=hRecvEvent;
	DataBuf.buf=data;
	DataBuf.len=len;
	memset(&RecvOverLapp,0,sizeof(WSAOVERLAPPED));
	RecvOverLapp.hEvent=hRecvEvent;
	flag=0;
	/////////////////////////////////////
	int ret;
	if((ret=WSARecv(socket,&DataBuf,1,retlen,&flag,&RecvOverLapp,NULL))==0)
		return true;
	else if((ret==SOCKET_ERROR)&&(WSAGetLastError()==WSA_IO_PENDING))
	{
		DWORD EventCaused=WSAWaitForMultipleEvents(2,hEvents,FALSE,time,FALSE);
		WSAResetEvent(hRecvEvent);
		if(EventCaused == WSA_WAIT_FAILED || EventCaused == WAIT_OBJECT_0)
		{
			return false;
		}
		flag=0;
		return (WSAGetOverlappedResult(socket,&RecvOverLapp,retlen,false,&flag))?
			true:false;
	}
	else
		return false;
}
bool PeerSendDataS(SOCKET socket,char *data,DWORD len,DWORD *retlen,WSAEVENT hSendEvent,DWORD time)
{
	DWORD left,idx,thisret;
	left=len;
	idx=0;
	int oflag=0;
	while(left>0)
	{
		if(!PeerSendData(socket,&data[idx],left,&thisret,hSendEvent,time))
		{
			*retlen=0;
			return false;
		}
		left-=thisret;
		idx+=thisret;
		if(thisret==0)
		{
			oflag++;
			if(oflag>5)
				break;
		}
	}
	*retlen=idx;
	return (idx==len)?true:false;

}
bool PeerRecvDataS(SOCKET socket,char *data,DWORD len,DWORD *retlen,WSAEVENT hRecvEvent,DWORD time)
{
	DWORD left,idx,thisret;
	left=len;
	idx=0;
	int oflag=0;
	while(left>0)
	{
		if(!PeerRecvData(socket,&data[idx],left,&thisret,hRecvEvent,time))
		{
			*retlen=0;
			return false;
		}
		left-=thisret;
		idx+=thisret;
		if(thisret==0)
		{
			oflag++;
			if(oflag>5)
				break;
		}
	}
	*retlen=idx;
	return (idx==len)?true:false;
}