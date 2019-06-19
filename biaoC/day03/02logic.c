/*
 * 逻辑操作符演示
 * */
#include <stdio.h>
int main() {
    int val = 0;
    printf("!8是%d\n", !8);
    printf("3 < 7 < 5是%d\n", 3 < 7 < 5);
    printf("3 < 7 && 7 < 5是%d\n", 3 < 7 && 7 < 5);
    1 || ++val;   //由于||的短路特征val变量的自增就没有进行
    printf("val是%d\n", val);
    0 && ++val;   //由于&&的短路特征val变量的自增也没有进行
    printf("val是%d\n", val);
    return 0;
}





