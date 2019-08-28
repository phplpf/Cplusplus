#include <windows.h>
#include <stdio.h>
// 线程处理函数
DWORD CALLBACK TestProc( LPVOID pParam ){
	char* pszText = (char*)pParam;
	while( 1 ){
		for( int i=0 ;i<strlen(pszText); i++){
			printf( "%c", pszText[i] );
			Sleep(10);
		}
		printf("\n");
	}
	return 0;
}
DWORD CALLBACK TestProc2( LPVOID pParam ){
	char* pszTest  = (char*)pParam;
	while( 1 ){
		for( int i=0; i<strlen(pszTest); i++ ){
			printf("%c", pszTest[i]);
			Sleep(10);
		}
		printf("\n");
	}
	return 0;
}
int main( void ){
	DWORD nID = 0;
	char* pszText = "********";
	// 创建线程
	HANDLE hThread = CreateThread( NULL, 0, TestProc, pszText, 0, &nID );
	char* pszText2 = "--------";
	HANDLE hThread2 = CreateThread( NULL, 0, TestProc2, pszText2, 0,&nID );
	getchar();
//	ResumeThread( hThread2 );  // 线程重新执行
//	SuspendThread( hThread );   // 线程挂起
//	getchar();
	// 关闭线程句柄
	CloseHandle( hThread );
	CloseHandle( hThread2 );

/*	nID = GetCurrentThreadId();
	HANDLE hThread = GetCurrentThread();
	printf("线程ID： %d, 线程句柄: %d\n", nID, hThread);
	hThread = OpenThread( THREAD_ALL_ACCESS, TRUE, nID );
	printf(" 线程句柄: %d\n", hThread);
	CloseHandle(hThread);*/
	getchar();
	return 0;
}