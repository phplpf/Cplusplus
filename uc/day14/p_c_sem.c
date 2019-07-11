#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>

typedef int que_t[5];
que_t q; //定义一个环状队列
sem_t p,c;//定义两个信号量 p代表可生产数
                //c代表可消费数
//生产者线程
void *product(void *arg){
    int h=0;
    while(1){
        sem_wait(&p);
        q[h]=rand()%1000+1;
        printf("p:%d\n",q[h]);
        h=(h+1)%5;
        sem_post(&c);
        sleep(rand()%3+1);
    }
    return NULL;
}
//消费者线程
void *consume(void *arg){
    int t=0;
    int tmp;
    while(1){
        sem_wait(&c);
        tmp=q[t];
        q[t]=-1;
        t=(t+1)%5;
        sem_post(&p);
        printf("c:%d\n",tmp);
        sleep(rand()%3+1);
    }
    return NULL;
}
int main(void){
    srand(time(NULL));
    sem_init(&p,0,5);
    sem_init(&c,0,0);
    pthread_t pid,cid;
    //创建两个线程，一个用于生产者 消费者
    pthread_create(&pid,NULL,product,NULL);
    pthread_create(&cid,NULL,consume,NULL);
    //阻塞等待线程的汇合
    pthread_join(pid,NULL);
    pthread_join(cid,NULL);
    //销毁信号量
    sem_destroy(&p);
    sem_destroy(&c);
    return 0;
}
