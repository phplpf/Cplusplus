#include <p_stdio.h>
#include <unistd.h>
#include <pthread.h>

//线程执行函数
void *thr_func(void *arg){
    printf("%s\n",(char *)arg);
    return NULL;
}

int main(void){
    pthread_t tid;
    //创建一个新的线程
    pthread_create(&tid,NULL,thr_func,"new");
    //到这里该进程中已经有两个线程了
    //这两个线程是异步的
    sleep(1);//只有主线程执行
    thr_func("main");
    return 0;
}
