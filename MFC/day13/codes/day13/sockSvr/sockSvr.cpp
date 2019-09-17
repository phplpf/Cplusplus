#include <stdio.h>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

void TCPServer()
{
	// 1 创建
	SOCKET hSockSvr=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (hSockSvr==INVALID_SOCKET)return;
	// 2 绑定
	SOCKADDR_IN addrSvr={0};
	addrSvr.sin_family=AF_INET;
	addrSvr.sin_port=htons(5678);
	addrSvr.sin_addr.S_un.S_addr=INADDR_ANY;
	bind(hSockSvr,(SOCKADDR*)&addrSvr,sizeof(addrSvr));
	// 3 监听
	listen(hSockSvr,5);
	// 4 接收客户端连接
	SOCKADDR_IN addrClient={0};
	int nLen= sizeof(addrClient);
	printf("等待客户端连接...\n");
	SOCKET hSockClient = accept(hSockSvr,(SOCKADDR*)&addrClient,&nLen);
	printf("已经与客户端建立连接。\n");
	// 5 通信
	// 5.1 服务器端首先接收数据
	char szBuff[256]={0};
	int nRecv = recv(hSockClient,szBuff,256,0);
	char * IP= inet_ntoa(addrClient.sin_addr);
	printf("%s:%s,%d\n",IP,szBuff,nRecv);
	// 5.2 然后，再把数据原样发送回客户端
	send(hSockClient,szBuff,strlen(szBuff),0);
	// 6 关闭
	closesocket(hSockClient);
	closesocket(hSockSvr);
	getchar();
}
void UDPServer()
{
	// 1 创建
	SOCKET hSockSvr=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if (hSockSvr == INVALID_SOCKET)return;
	// 2 绑定
	SOCKADDR_IN addrSvr={0};
	addrSvr.sin_family = AF_INET;
	addrSvr.sin_port = htons(5678);
	addrSvr.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(hSockSvr,(SOCKADDR*)&addrSvr,sizeof(addrSvr));
	// 3 通信
	// 3.1 接收数据
	char szBuff[256]={0};
	SOCKADDR_IN addrClient={0};
	int nLen=sizeof(addrClient);
	int nRecv = recvfrom(hSockSvr,szBuff,256,0,(SOCKADDR*)&addrClient,&nLen);
	char *IP=inet_ntoa(addrClient.sin_addr);
	printf("%s,%s,%d\n",IP,szBuff,nRecv);
	// 3.2 将数据原样发送回客户端
	sendto(hSockSvr,szBuff,strlen(szBuff),0,(SOCKADDR*)&addrClient,nLen);
	// 4 关闭
	closesocket(hSockSvr);
	getchar();
		

}
int main()
{
	// 1 初始化socket库
	WSAData ws={0};
	WSAStartup(MAKEWORD(2,2),&ws);
	// 2 通信
	//TCPServer();
	UDPServer();
	// 3 卸载
	WSACleanup();
	return 0;
}