#include <stdio.h>
_declspec(dllimport)int CppDll_add( int, int );
_declspec(dllimport)int CppDll_sub( int, int );
_declspec(dllimport)int CppDll_mul( int, int );
// 通知链接器到什么地方找函数的地址
#pragma comment(lib, "../Debug/CppDll.lib")
int main(void)
{
	int sum = CppDll_add( 8, 3 );
	int sub = CppDll_sub( 8, 3 );
	int mul = CppDll_mul( 8, 3 );
	printf("sum=%d, sub=%d, mul=%d\n",sum, sub, mul );
	getchar();
	return 0;
}