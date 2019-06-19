/*
 * 栈演示
 * */
#ifndef        __02STACK_H__
#define        __02STACK_H__
typedef struct {
    int buf[SIZE];   //记录栈里的数字。前面的数字记录到小下标的存储区里
    int qty;         //记录栈里的数字个数
} stack_t;
//栈的初始化函数
void stack_init(stack_t *);
//栈的清理函数
void stack_deinit(stack_t *);
//获得栈里数字个数的函数
int stack_size(const stack_t *);
//判断栈是否空的函数
int stack_empty(const stack_t *);
//判断栈是否满的函数
int stack_full(const stack_t *);
//向栈里加入数字的函数
int stack_push(stack_t *, int );
//从栈里获得数字的函数(同时从栈里删除数字)
int stack_pop(stack_t *, int *);
//从栈里获得数字的函数(不会从栈里删除数字)
int stack_top(const stack_t *, int *);
#endif           //__02STACK_H__








