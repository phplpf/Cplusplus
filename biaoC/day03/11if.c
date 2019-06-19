/*
 * if分支演示
 * */
#include <stdio.h>
int main() {
    int val = 0;
    printf("请输入一个数字：");
    scanf("%d", &val);
    //如果多个逻辑表达式同时
    //为真就执行第一个为真的
    //逻辑表达式后面的语句
    if (val < 0) {
        printf("负数\n");
    }
    else if (val & 1) {
        printf("奇数\n");
    }
    else if (!(val & 1)) {
        printf("偶数\n");
    }
    return 0;
}






