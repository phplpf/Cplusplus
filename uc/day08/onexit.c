#include <stdio.h>
#include <stdlib.h>

void handle(int n, void *arg){
    printf("%d\t%s\n",n,(char *)arg);
    return;
}
int main(void){
    //向进程注册遗言函数
    on_exit(handle,"beijing");
    getchar();
    exit(-1);
}
