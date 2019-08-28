// 包含头文件，解决编译时找不到printf和getchar的问题
#include <stdio.h>
// 增加函数声明，解决编译时找不到自定义函数的问题
int CppLib_add( int, int );
int CppLib_sub( int, int );
// 增加库函数的路径，解决链接时无法获取源码的问题
#pragma comment(lib,"../Debug/CppLib.lib")
// C库函数的声明 （按照C风格对函数名进行处理）
extern "C"int CLib_add( int, int );
extern "C"int CLib_sub( int, int );
// 增加C库函数的路径
#pragma comment(lib,"../Debug/CLib.lib")
int main(void)
{
	int sum = CppLib_add( 10, 5 );
	int sub = CppLib_sub( 10, 5 );
	printf("sum=%d, sub=%d\n", sum, sub );

	sum = CLib_add( 8, 3 );
	sub = CLib_sub( 8, 3 );
	printf("sum=%d, sub=%d\n", sum, sub );

	getchar();
	return 0;
}