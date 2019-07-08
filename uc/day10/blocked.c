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
    sigset_t set,oset;//定义信号集类型的变量
    sigemptyset(&set);
    sigaddset(&set,2);
    sigaddset(&set,3);
    sigaddset(&set,45);
    sigaddset(&set,9);
    //将set信号集设置为进程的信号掩码集
    int sp=sigprocmask(SIG_SETMASK,&set,&oset);
    if(sp==-1)E_MSG("sigprocmask",-1);
    sleep(30);
    sigprocmask(SIG_SETMASK,&oset,NULL);
    return 0;
}
