#pragma once

/////////////////声明全局变量//////////////////
#define MAX_STRING_LEN 50
#define PEER_WAITTIME 60000	//超时设定时间
#define PEER_KILLTHREADTIME 5000
#define PEER_CLEANTHREADTIME 200	//超时设定时间
#define PEER_FUNERROR 4116010325
extern DWORD SENDRECV_TIMEOUT;		//收发数据时超时设置

// 全局实例及主窗体变量
extern HINSTANCE hInst;							
extern HWND		 hMainWnd;

/////////一些重要的系统句柄///////////
extern HANDLE hOnlyInstance;	//	要求只有一个实例
extern HANDLE hExitEvent;		//	退出系统事件
//////////////////////////////////////
/////////系统参数/////////////////////
extern char szHostName[MAX_COMPUTERNAME_LENGTH + 1]; //主机名称
extern char szHostAddr[MAX_STRING_LEN];	//主机地址
extern int	nHostPort;	//服务器端口号

extern HANDLE hAcceptThread;	//接受连接线程句柄
extern HANDLE hCleanupThread;	//清理资源线程句柄
extern UINT uAcceptThreadID;	//接受连接线程ID值
extern UINT uCleanupThreadID;	//清理资源线程ID值
extern UINT nThread;
//////////////////////////////////////