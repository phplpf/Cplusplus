#include <stdio.h>
#include <windows.h>
HANDLE g_hEvent = 0; // 事件句柄
DWORD CALLBACK PrintProc( LPVOID pParam )
{
	while( 1 ){
		WaitForSingleObject( g_hEvent, INFINITE );
		ResetEvent( g_hEvent ); // 复位
		printf("******************\n");
	}
	return 0;
}
DWORD CALLBACK CtrlProc( LPVOID pParam )
{
	while( 1 ){
		Sleep(1000); 
		SetEvent( g_hEvent );  // 触发
	}
	return 0;
}
int main( void )
{
	// 创建事件
	g_hEvent = CreateEvent( NULL, TRUE, FALSE, NULL );
	HANDLE hThreads[2];
	DWORD nID = 0;
	hThreads[0] = CreateThread( NULL, 0, PrintProc, NULL, 0, &nID );
	hThreads[1] = CreateThread( NULL, 0, CtrlProc, NULL, 0, &nID );
	getchar();
	// 关闭句柄
	CloseHandle( hThreads[0] );
	CloseHandle( hThreads[1] );
	CloseHandle( g_hEvent );
	return 0;
}