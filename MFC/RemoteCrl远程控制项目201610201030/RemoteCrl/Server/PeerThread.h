#pragma once
#include <process.h>
#include "command.h"//封装通信时的结构体

/////////////////////////////////////////////////////
#define CUR_THREADID GetCurrentThreadId()

typedef unsigned (__stdcall *PTHREAD_START)(void*);
//定义创建线程函数,以简化代码的书写
#define BeginPeerThread(pfnStartAddr,pvParam,pdwThreadID)\
		((HANDLE)(_beginthreadex((void*)NULL,\
                                 0,\
								 (PTHREAD_START)(pfnStartAddr),\
								 (void*)(pvParam),\
								 0,\
								 (unsigned*)(pdwThreadID)\
								)\
                 )\
		)

#define EndPeerThread(retVal) _endendthreadex((unsigned)retVal)
///////////////////////////////////////////////////////

typedef struct tagConnectThread
{
	HANDLE			hThread;	//线程句柄
	UINT			threadID;	//线程ID
}CONNECTTHREAD;

typedef struct tagConnectSocket
{
	SOCKET			socket;		//连接Socket
	char			IP[64];		//IP地址,为了兼容IP6
}CONNECTSOCKET;


//用户list查找时使用的比较函数
struct IDCompare:binary_function<CONNECTTHREAD,unsigned int, bool>
{
	bool operator()(const CONNECTTHREAD& _X, const unsigned int& _Y) const
	{
		return (_X.threadID == _Y); 
	}
};

typedef list<CONNECTTHREAD>	CONNECTTHREADLIST;	//客户连接线程列表
typedef list<HANDLE>	UNUSEDTHREADLIST;	//不用的线程句柄列表

UINT WINAPI AcceptThread(PVOID pParam);
UINT WINAPI ServerThread(PVOID pParam);
UINT WINAPI CleanupThread(PVOID pParam);

////////////////////////////////////////////
extern CONNECTTHREADLIST	listConnectThread;	//客户连接线程列表
extern UNUSEDTHREADLIST		listUnusedThread;	//不用的线程句柄列表
extern CRITICAL_SECTION		csProtectList;		//只允许一个线程访问这些列表
//////////////////////////////////////////
void DeleteThread(DWORD dwThreadID);