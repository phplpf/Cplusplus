#include <pthread.h>
#include <p_stdio.h>
#include <unistd.h>

//线程执行的 函数
void *thr_f(void *arg){
    printf("thr_f ...running\n");
    //sleep(2);
    return (void *)1;
}

void *thr_f1(void *arg){
    printf("thr_f1 ...running\n");
    pthread_exit((void *)3);
}

void *thr_f2(void *arg){
    while(1){
        printf("thr_f2 ...running\n");
        sleep(1);
    }
}
int main(void){
    void *retv;
    //创建线程
    pthread_t tid;
    pthread_create(&tid,NULL,thr_f,NULL);
    //阻塞等待线程的终止.void **retval; *retval
    pthread_join(tid,&retv);
    printf("exit code...%d\n",(int)retv);
    pthread_create(&tid,NULL,thr_f1,NULL);
    //阻塞等待线程的终止.void **retval; *retval
    pthread_join(tid,&retv);
    printf("exit code F1...%d\n",(int)retv);
    pthread_create(&tid,NULL,thr_f2,NULL);
    sleep(3);
    //向tid指定的线程发送取消请求
    pthread_cancel(tid);
    //阻塞等待线程的终止.void **retval; *retval
    pthread_join(tid,&retv);
    if(retv==PTHREAD_CANCELED)
        printf("exit code F2...%d\n",(int)retv);


    return 0;
}
