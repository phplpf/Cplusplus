/*
 * 变量交换演示
 * */
#include <stdio.h>
int main() {
    int val = 3, val1 = 7, tmp = 0;
    //交换变量内容
    /*tmp = val;
    val = val1;
    val1 = tmp;*/
    val ^= val1;
    val1 ^= val;
    val ^= val1;
    printf("val是%d, val1是%d\n", val, val1);
    return 0;
}





