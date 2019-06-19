/*
 * 地址操作符演示
 * */
#include <stdio.h>
int main() {
    int val = 0;
    printf("&val是%p\n", &val);
    *(&val) /*val变量的存储区*/ = 10;
    printf("val是%d\n", val);
    return 0;
}




