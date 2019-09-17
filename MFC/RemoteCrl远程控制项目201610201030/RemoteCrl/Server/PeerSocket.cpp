// PeerSocket.cpp: implementation of the PeerSocket.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GlobalHead.h"
#include "PeerSocket.h"

//////////////////////////////////////////////////////////////////////
bool PeerCreateSocket(SOCKET *pNewSocket,int iSockType)
{
	SOCKET newSock;
	return ((newSock = socket( AF_INET, iSockType, IPPROTO_TCP)) == INVALID_SOCKET)?
		false:*pNewSocket=newSock,true;

}
bool PeerBindSocket(SOCKET BindSocket,char *szHostAddr,int iHostPort)
{
	SOCKADDR_IN sockAddr = { 0 };
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_port = htons(iHostPort);
	sockAddr.sin_addr.S_un.S_addr = inet_addr(szHostAddr);
	return ::bind( BindSocket, (SOCKADDR*)&sockAddr, sizeof(sockAddr) ) == SOCKET_ERROR ? false : true;
}
bool PeerListenSocket(SOCKET ListenSock)
{
	return listen(ListenSock, 5)?false:true;
}
bool PeerAcceptSocket( SOCKET *pTravelSocket, SOCKADDR_IN *psockAddr, SOCKET ListenSock )
{
	
	int nLen = sizeof(SOCKADDR_IN);
	SOCKET travelSock = accept( ListenSock, (SOCKADDR*)psockAddr, &nLen );
	return travelSock==INVALID_SOCKET?false:*pTravelSocket=travelSock,true;
}
bool PeerShutDownSocket(SOCKET nowSocket)
{
	return shutdown(nowSocket,SD_BOTH)?false:true;
}
bool PeerCloseSocket(SOCKET nowSocket)
{
	return (closesocket(nowSocket)==SOCKET_ERROR)?false:true;
}
bool PeerSendData(SOCKET socket,char *data,DWORD len,DWORD *retlen)
{
	*retlen = send( socket, data, len, 0 );
	return *retlen!=len?false:true;
}
bool PeerRecvData(SOCKET socket,char *data,DWORD len,DWORD *retlen)
{
	*retlen = recv( socket, data, len, 0 );
	return *retlen!=len?false:true;
}
bool PeerSendDataS(SOCKET socket,char *data,DWORD len,DWORD *retlen)
{
	DWORD left,idx,thisret;
	left=len;
	idx=0;
	int oflag=0;
	while(left>0)
	{
		if(!PeerSendData(socket,&data[idx],left,&thisret))
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
bool PeerRecvDataS(SOCKET socket,char *data,DWORD len,DWORD *retlen)
{
	DWORD left,idx,thisret;
	left=len;
	idx=0;
	int oflag=0;
	while(left>0)
	{
		if(!PeerRecvData(socket,&data[idx],left,&thisret))
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