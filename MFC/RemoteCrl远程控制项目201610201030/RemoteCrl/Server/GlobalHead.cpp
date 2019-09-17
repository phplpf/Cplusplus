
#include "stdafx.h"
#include "GlobalHead.h"

//////////////////////////////////////////////////////////////////////
/////////一些重要的系统句柄///////////
HANDLE hOnlyInstance=NULL;	//	要求只有一个实例
WSAEVENT hExitEvent=NULL;	//	退出系统事件
//////////////////////////////////////

/////////系统参数/////////////////////
char szHostName[MAX_COMPUTERNAME_LENGTH + 1]; //主机名称
char szHostAddr[MAX_STRING_LEN];	//主机地址
int	 nHostPort=8111;	//服务器端口号

DWORD SENDRECV_TIMEOUT=1200000;	//收发数据时超时设置

HANDLE hAcceptThread=NULL;	//接受连接线程句柄
HANDLE hCleanupThread=NULL;	//清理资源线程句柄
UINT uAcceptThreadID=0;		//接受连接线程ID值
UINT uCleanupThreadID=0;	//清理资源线程ID值
