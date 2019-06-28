#include <stdio.h>
int main(void)
{
    int *p=(int*)30000000;
    //printf("%d \n",*p); 段错误
    return 0;
}

