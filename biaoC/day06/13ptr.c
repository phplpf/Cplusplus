/*
 * 指针变量演示
 * */
#include <stdio.h>
typedef int *pint_t;    //给指针类型起别名
int main() {
    int val = 0;
    int *p_val = &val, *p_val1 = NULL;    //指针变量声明语句
    //pint_t p_val = &val, p_val1;    //用指针类型名称声明指针变量(这种语句里不需要使用*)
    *p_val = 10;     //实际对val变量做赋值
    printf("val是%d\n", val);
    return 0;
}





