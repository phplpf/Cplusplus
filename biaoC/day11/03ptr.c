/*
 * 函数指针演示
 * */
#include <stdio.h>
typedef int (*pfunc_t)(int, int);   //给函数指针类型起名字
int add(int val, int val1) {
    return val + val1;
}
int sub(int val, int val1) {
    return val - val1;
}
int main() {
    //int (*p_add)(int, int) = NULL;    //函数指针声明语句，这个函数指针可以记录add函数地址
    //int (*p_sub)(int, int) = NULL;
    pfunc_t p_add = NULL, p_sub = NULL;   //声明函数指针变量，因为使用函数指针类型名称所以不应该在指针变量名称前加*
    p_add = add;
    p_sub = sub;
    printf("add是%p\n", add);
    printf("结果是%d\n", p_add(7, 2));
    return 0;
}






