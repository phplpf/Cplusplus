/*
 * 循环队列演示
 * */
#ifndef          __02QUEUE_H__
#define          __02QUEUE_H__
typedef struct {
    int buf[SIZE];    //如果数组前面有空的存储区可以重复利用
    int qty;          //队列里的数字个数
    int tail;         //记录下一个数字应该放的位置
} queue_t;
//获得最前面数字所在位置的函数
int get_head(const queue_t *);
//循环队列的初始化函数
void queue_init(queue_t *);
//循环队列的清理函数
void queue_deinit(queue_t *);
//判断队列是否空的函数
int queue_empty(const queue_t *);
//判断队列是否满的函数
int queue_full(const queue_t *);
//获得队列里的数字个数的函数
int queue_size(const queue_t *);
//向队列里加入数字的函数
int queue_push(queue_t *, int );
//从队列里获得数字的函数(同时从队列里删除数字)
int queue_pop(queue_t *, int *);
//从队列里获得数字的函数(不会从队列里删除数字)
int queue_front(const queue_t *, int *);
#endif             //__02QUEUE_H__








