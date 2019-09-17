#include <stdio.h>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

void TCPClient()
{
	// 1 创建
	SOCKET hSockClient=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (hSockClient==INVALID_SOCKET)return;
    // 2 连接
	SOCKADDR_IN addrSvr={0};
	addrSvr.sin_family=AF_INET;
	addrSvr.sin_port=htons(5678);
	addrSvr.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
    connect(hSockClient,(SOCKADDR*)&addrSvr,sizeof(addrSvr));
	// 3 通信
	// 3.1 首先发送数据
	char *szSend="hello world";
	send(hSockClient,szSend,strlen(szSend),0);
	// 3.2 然后接收数据
	char szBuff[256]={0};
	int nRecv = recv(hSockClient,szBuff,256,0);
	printf("%s,%d\n",szBuff,nRecv);
	// 4 关闭
	closesocket(hSockClient);
	getchar();
}
void UDPClient()
{
	// 1 创建
	SOCKET hSockClient=socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if (hSockClient==INVALID_SOCKET)return;
	// 2 通信
	// 2.1 首先发送数据
	SOCKADDR_IN addrSvr={0};
	addrSvr.sin_family = AF_INET;
	addrSvr.sin_port = htons(5678);
	addrSvr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	char szSend[]="Hello World";
	sendto(hSockClient,szSend,strlen(szSend),0,(SOCKADDR*)&addrSvr,
		sizeof(addrSvr));
	// 2.2 然后接收数据
	char szBuff[256]={0};
	int nLen=sizeof(addrSvr);
	int nRecv = recvfrom(hSockClient,szBuff,256,0,(SOCKADDR*)&addrSvr,&nLen);
	printf("%s,%d\n",szBuff,nRecv);
	// 3 关闭
	closesocket(hSockClient);
	getchar();
}
int main()
{
	// 1 初始化socket库
	WSAData ws={0};
	WSAStartup(MAKEWORD(2,2),&ws);
	// 2 通信
	//TCPClient();
	UDPClient();
	// 3 卸载
	WSACleanup();
	return 0;
}