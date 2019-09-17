#pragma once

#define PEER_STREAM SOCK_STREAM
#define PEER_DGRAM  SOCK_DGRAM
#define PEER_RAW	SOCK_RAW

bool PeerCreateSocket(SOCKET *pNewSocket,int iSockType);
bool PeerBindSocket(SOCKET BindSocket,char *szHostAddr,int iHostPort);
bool PeerListenSocket(SOCKET ListenSocket);
bool PeerAcceptSocket( SOCKET *pTravelSocket, SOCKADDR_IN *psockAddr, SOCKET ListenSock );
bool PeerShutDownSocket(SOCKET nowSocket);
bool PeerCloseSocket(SOCKET nowSocket);
bool PeerSendData(SOCKET socket,char *data,DWORD len,DWORD *retlen);
bool PeerRecvData(SOCKET socket,char *data,DWORD len,DWORD *retlen);
bool PeerSendDataS(SOCKET socket,char *data,DWORD len,DWORD *retlen);
bool PeerRecvDataS(SOCKET socket,char *data,DWORD len,DWORD *retlen);