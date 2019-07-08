#include <signal.h>
#include <p_stdio.h>
#include <unistd.h>

//用户自定义的信号处理函数
void handle(int n){
    printf("recv...%d\n",n);
    return;
}
int main(void){
    signal(2,SIG_IGN);
    signal(3,handle);
    signal(9,SIG_IGN);
    //创建子进程
    pid_t pid=fork();
    if(pid==-1)E_MSG("frok",-1);

    while(1);
    return 0;
}
