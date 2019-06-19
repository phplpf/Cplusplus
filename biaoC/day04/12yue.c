/*
 * while循环练习
 * */
#include <stdio.h>
int main() {
    int val = 0, val1 = 0, tmp = 0;
    printf("请输入两个数字：");
    scanf("%d%d", &val, &val1);
    while (val % val1) {   //两个数字之间没有整数倍关系的时候循环应该继续
        tmp = val % val1;
        val = val1;
        val1 = tmp;
    }
    printf("最大公约数是%d\n", val1);
    return 0;
}







