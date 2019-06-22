/*
 * 循环队列演示
 * */
#include "02queue.h"
int get_head(const queue_t *p_queue) {
    int head = p_queue->tail - p_queue->qty;
    if (head < 0) {
        head += SIZE;
    }
    return head;
}
//循环队列的初始化函数
void queue_init(queue_t *p_queue) {
    p_queue->tail = 0;
    p_queue->qty = 0;
}
//循环队列的清理函数
void queue_deinit(queue_t *p_queue) {
    p_queue->tail = 0;
    p_queue->qty = 0;
}
//判断队列是否空的函数
int queue_empty(const queue_t *p_queue) {
    return !(p_queue->qty);
}
//判断队列是否满的函数
int queue_full(const queue_t *p_queue) {
    return p_queue->qty >= SIZE;
}
//获得队列里的数字个数的函数
int queue_size(const queue_t *p_queue) {
    return p_queue->qty;
}
//向队列里加入数字的函数
int queue_push(queue_t *p_queue, int val) {
    if (p_queue->qty >= SIZE) {
        return 0;
    }
    p_queue->buf[p_queue->tail] = val;
    p_queue->qty++;
    p_queue->tail++;
    if (p_queue->tail >= SIZE) {
        p_queue->tail = 0;
    }
    return 1;
}
//从队列里获得数字的函数(同时从队列里删除数字)
int queue_pop(queue_t *p_queue, int *p_val) {
    if (!(p_queue->qty)) {
        return 0;
    }
    *p_val = p_queue->buf[get_head(p_queue)];
    p_queue->qty--;
    return 1;
}
//从队列里获得数字的函数(不会从队列里删除数字)
int queue_front(const queue_t *p_queue, int *p_val) {
    if (!(p_queue->qty)) {
        return 0;
    }
    *p_val = p_queue->buf[get_head(p_queue)];
    return 1;
}









