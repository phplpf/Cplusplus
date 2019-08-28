#include <stdio.h>
#include <windows.h>
HANDLE g_hSema = 0; // 信号量句柄
DWORD CALLBACK PrintProc( LPVOID pParam )
{
//	while( 1 ){
		WaitForSingleObject( g_hSema, INFINITE ); // 等候信号量句柄有信号
		printf( "**************\n" );
//	}
	return 0;
}
DWORD CALLBACK PrintProc2( LPVOID pParam )
{
	while( 1 ){
		WaitForSingleObject( g_hSema, INFINITE ); // 等候信号量句柄有信号
		printf( "---------------\n" );
	}
	return 0;
}
int main( void )
{
	// 创建信号量
	g_hSema = CreateSemaphore( NULL, 3, 10, NULL );
	DWORD nID = 0;
	HANDLE hThread = CreateThread( NULL, 0, PrintProc, NULL, 0, &nID );
	HANDLE hThread2 = CreateThread( NULL, 0, PrintProc2, NULL, 
		CREATE_SUSPENDED, &nID );
	getchar();
	ReleaseSemaphore( g_hSema, 8, NULL );
	ResumeThread( hThread2 );
	getchar();
	CloseHandle( hThread );
	CloseHandle( g_hSema );
	return 0;
}