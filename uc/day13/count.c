#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
int val=0;//是一个全局变量 数据段 临界资源
//线程执行的函数
void *handle(void *arg){
    int i;
    for(int j=0;j<5000;j++){
        //加锁
        pthread_mutex_lock(&mutex);
        i=val;
        printf("++i=%d...%lu\n",++i,pthread_self());
        val=i;
        //解锁
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
int main(void){
    //初始化mutex变量
    pthread_mutex_init(&mutex,NULL);
    pthread_t tid,pid;
    //创建两个线程，这两个线程的执行函数都是handle
    pthread_create(&tid,NULL,handle,NULL);
    pthread_create(&pid,NULL,handle,NULL);
    //汇合两个线程
    pthread_join(tid,NULL);
    pthread_join(pid,NULL);
    //销毁mutex锁
    pthread_mutex_destroy(&mutex);

    return 0;
}
