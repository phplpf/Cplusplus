#include <stdio.h>
#include <windows.h>
// 1. 定义函数指针类型
typedef int(*FUNC)( int m, int n );
int main( void )
{
	// 2. 加载动态库
	HMODULE hDll = LoadLibrary( "CppDll.dll" );
	printf("hDll: %d\n", hDll );
	// 3. 根据函数名称字符串，获取函数的绝对地址
	FUNC myAdd = (FUNC)GetProcAddress( hDll, "CppDll_add");
	FUNC mySub = (FUNC)GetProcAddress( hDll, "CppDll_sub");
	FUNC myMul = (FUNC)GetProcAddress( hDll, "?CppDll_mul@@YAHHH@Z");
//	printf("myAdd: %p\n", myAdd );
	// 4. 根据函数的绝对地址调用函数
	int sum = myAdd( 6, 1 );
	int sub = mySub( 6, 1 );
	int mul = myMul( 6, 1 );
	printf("sum = %d, sub=%d, mul=%d\n", sum, sub, mul );
	// 5. 卸载动态库
	FreeLibrary( hDll );
	getchar();
	return 0;
}