#include <stdio.h>
#include <unistd.h>
int main(void){
    alarm(5);
    for(int i=1;i<200000;i++)
        printf("i=%d\n",i);

    unsigned int s=alarm(10);//取消了原来的闹钟
    printf("%u\n",s);
    while(1);

    return 0;
}
