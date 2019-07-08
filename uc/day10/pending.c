#include <p_stdio.h>
#include <signal.h>
#include <unistd.h>

void handle(int n){
    printf("recv...%d\n",n);
    return;
}
int main(void){
    signal(2,handle);
    signal(3,handle);
    signal(45,handle);
    sigset_t set,oset,pset;//定义信号集类型的变量
    sigemptyset(&set);
    sigaddset(&set,2);
    sigaddset(&set,3);
    sigaddset(&set,45);
    sigaddset(&set,9);
    //将set信号集设置为进程的信号掩码集
    int sp=sigprocmask(SIG_SETMASK,&set,&oset);
    if(sp==-1)E_MSG("sigprocmask",-1);
    while(1){
        //获取进程的未决信号集
        //将进程的未决信号填充到pset地址空间里
        sigpending(&pset);
        //判断某个信号是不是信号集中的一员
        //如果是  代表该信号是未决信号
        sigismember(&pset,2)?\
            printf("pending"):printf("not pending");
        printf("\n");
        sleep(2);
    }
    return 0;
}
