#define CLASSDLL_EXPORT
#include <windows.h>
#include <stdio.h>
#include "math.h"
BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, 
	LPVOID lpvReserved)
{
	switch( fdwReason )
	{
	case DLL_PROCESS_ATTACH:
		printf("Loading...\n");
		break;
	case DLL_PROCESS_DETACH:
		printf("Unloading...\n");
		break;
	}
	return TRUE;
}

int CMath::add( int m, int n )
{
	return m + n;
}
int CMath::sub( int m, int n )
{
	return m - n;
}