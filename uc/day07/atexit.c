#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//遗言函数的定义
void handle(void){
    printf("bye...bye...\n");
    return;
}
void handle1(void){
    printf("goodbye...goodbye...\n");
    return;
}

int main(void){
    //向进程注册遗言函数
    atexit(handle);
    atexit(handle1);
    //创建子进程
    pid_t pid=fork();
    sleep(1);
    return 0;
}
