#include <stdio.h>
#include "../ClassDll/math.h"
#pragma comment(lib, "../Debug/ClassDll.lib")
int main(void)
{
	CMath math;
	int sum = math.add( 10, 2 );
	int sub = math.sub( 10, 2 );
	printf("sum=%d, sub=%d\n",sum, sub );
	getchar();
	return 0;
}