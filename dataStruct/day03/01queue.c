/*
 * 队列演示
 * */
#include "01queue.h"
//队列的初始化函数
void queue_init(queue_t *p_queue) {
    p_queue->head = 0;
    p_queue->tail = 0;
}
//队列的清理函数
void queue_deinit(queue_t *p_queue) {
    p_queue->head = 0;
    p_queue->tail = 0;
}
//判断队列是否空的函数
int queue_empty(const queue_t *p_queue) {
    return p_queue->head == p_queue->tail;
}
//判断队列是否满的函数
int queue_full(const queue_t *p_queue) {
    return p_queue->tail >= SIZE;
}
//获得队列里数字个数的函数
int queue_size(const queue_t *p_queue) {
    return p_queue->tail - p_queue->head;
}
//向队列里加入数字的函数
int queue_push(queue_t *p_queue, int val) {
    if (p_queue->tail >= SIZE) {
        return 0;
    }
    p_queue->buf[p_queue->tail] = val;
    p_queue->tail++;
    return 1;
}
//从队列里获得数字的函数(同时从队列里删除数字)
int queue_pop(queue_t *p_queue, int *p_val) {
    if (p_queue->head == p_queue->tail) {
        return 0;
    }
    *p_val = p_queue->buf[p_queue->head];
    p_queue->head++;
    return 1;
}
//从队列里获得数字的函数(不会从队列里删除数字)
int queue_front(const queue_t *p_queue, int *p_val) {
    if (p_queue->head == p_queue->tail) {
        return 0;
    }
    *p_val = p_queue->buf[p_queue->head];
    return 1;
}








