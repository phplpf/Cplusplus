/*
 * 队列演示
 * */
#ifndef         __01QUEUE_H__
#define         __01QUEUE_H__
typedef struct {
    int buf[SIZE];     //记录队列里的数字.小下标的存储区记录前面的数字
    int head;          //记录第一个数字所在存储区的下标(如果队列里没有数字head应该等于tail)
    int tail;          //记录下一个数字应该放置的下标
} queue_t;
//队列的初始化函数
void queue_init(queue_t *);
//队列的清理函数
void queue_deinit(queue_t *);
//判断队列是否空的函数
int queue_empty(const queue_t *);
//判断队列是否满的函数
int queue_full(const queue_t *);
//获得队列里数字个数的函数
int queue_size(const queue_t *);
//向队列里加入数字的函数
int queue_push(queue_t *, int );
//从队列里获得数字的函数(同时从队列里删除数字)
int queue_pop(queue_t *, int *);
//从队列里获得数字的函数(不会从队列里删除数字)
int queue_front(const queue_t *, int *);
#endif           //__01QUEUE_H__







