/*
 * 栈演示
 * */
#include "02stack.h"
//栈的初始化函数
void stack_init(stack_t *p_stack) {
    p_stack->qty = 0;    //表示栈里没有有效数字
}
//栈的清理函数
void stack_deinit(stack_t *p_stack) {
    p_stack->qty = 0;    //删除栈里所有数字
}
//获得栈里数字个数的函数
int stack_size(const stack_t *p_stack) {
    return p_stack->qty;
}
//判断栈是否空的函数
int stack_empty(const stack_t *p_stack) {
    return !(p_stack->qty);
}
//判断栈是否满的函数
int stack_full(const stack_t *p_stack) {
    return p_stack->qty >= SIZE;
}
//向栈里加入数字的函数
int stack_push(stack_t *p_stack, int val) {
    if (p_stack->qty >= SIZE) {
        return 0;
    }
    p_stack->buf[p_stack->qty] = val;
    p_stack->qty++;
    return 1;
}
//从栈里获得数字的函数(同时从栈里删除数字)
int stack_pop(stack_t *p_stack, int *p_val) {
    if (!(p_stack->qty)) {
        //栈里面没有数字
        return 0;
    }
    *p_val = p_stack->buf[p_stack->qty - 1];
    p_stack->qty--;
    return 1;
}
//从栈里获得数字的函数(不会从栈里删除数字)
int stack_top(const stack_t *p_stack, int *p_val) {
    if (!(p_stack->qty)) {
        return 0;
    }
    *p_val = p_stack->buf[p_stack->qty - 1];
    return 1;
}









