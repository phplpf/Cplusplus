#include <stdio.h>

int main(void){
    //int val=300;
    //int *p=&val;
    int *p=(int *)30000000;
    //printf("&val=%p\n",&val);
    printf("*p=%d\n",*p);
    return 0;
}
