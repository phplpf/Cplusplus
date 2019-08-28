// 引入lib库，告诉链接器到哪个文件中复制CLib_add和CLib_sub的源码
#pragma comment(lib, "../Debug/CLib.lib")
int main(void)
{
	int sum = CLib_add( 10, 5 );
	int sub = CLib_sub( 10, 5 );
	printf( "sum=%d,sub=%d\n", sum, sub );
	getchar();
	return 0;
}