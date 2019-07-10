#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>


//定义节点类型
typedef struct node{
    int data;
    struct node *next;
}node_t;
typedef node_t *list_t;

list_t head=NULL;//定义空链表
pthread_mutex_t mutex;//定义一把锁
pthread_cond_t cond;//定义一个条件变量
//生产者线程
void *product(void *arg){
    node_t *new;
    while(1){
        //生产一个新的节点
        new=(node_t *)malloc(sizeof(node_t));
        new->data=rand()%1000+1;
        new->next=NULL;
        //加锁
        pthread_mutex_lock(&mutex);
        //将新节点插入到链表的头部
        new->next=head;
        head=new;
        //解锁
        pthread_mutex_unlock(&mutex);
        printf("p:%d\n",new->data);
        pthread_cond_signal(&cond);
        sleep(rand()%3+1);
    }
    return NULL;
}
//消费者线程
void *consume(void *arg){
    node_t *tmp;
    while(1){
        //加锁
        pthread_mutex_lock(&mutex);

        // 从链表的头部摘取一个节点
        while(head==NULL)
            //等着生产
            pthread_cond_wait(&cond,&mutex);
        
        tmp=head;
        head=head->next;
        //解锁
        pthread_mutex_unlock(&mutex);
        printf("c:%d\n",tmp->data);
        // 消费这个节点
        free(tmp);
        tmp=NULL;
        sleep(rand()%3+1);
    }
    return NULL;
}
int main(void){
    srand(time(NULL));
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    pthread_t pid,cid;
    //创建两个线程，一个用于生产者 消费者
    pthread_create(&pid,NULL,product,NULL);
    pthread_create(&cid,NULL,consume,NULL);
    //阻塞等待线程的汇合
    pthread_join(pid,NULL);
    pthread_join(cid,NULL);
    //销毁mutex锁
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}
