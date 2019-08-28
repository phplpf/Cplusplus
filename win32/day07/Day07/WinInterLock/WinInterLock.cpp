#include <stdio.h>
#include <windows.h>
long g_nValue = 0;
DWORD CALLBACK ThreadProc1( LPVOID pParam )
{
	for( int i = 0; i<100000000; i++ ){
//		g_nValue++;
		InterlockedIncrement(&g_nValue);
	}
	return 0;
}
DWORD CALLBACK ThreadProc2( LPVOID pParam )
{
	for( int i = 0; i<100000000; i++ ){
//		g_nValue++;
		InterlockedIncrement(&g_nValue);
	}
	return 0;
}
int main()
{
	DWORD nIDs[2];
	HANDLE hThreads[2];
	hThreads[0] = CreateThread( NULL, 0, ThreadProc1, NULL, 0, &nIDs[0]);
	hThreads[1] = CreateThread( NULL, 0, ThreadProc2, NULL, 0, &nIDs[1]);
	// 等待两个线程都执行完
	WaitForMultipleObjects( 2, hThreads, TRUE, INFINITE );
	printf("g_nValue =  %d\n", g_nValue);
	getchar();
	CloseHandle(hThreads[0]);
	CloseHandle(hThreads[1]);
	return 0;
}