/*
 * if分支演示
 * */
#include <stdio.h>
int main() {
    int val = 0;
    printf("请输入一个数字：");
    scanf("%d", &val);
    /*
     * val >= 0 *  显示非负数
     **************************
     * val < 0  *  显示负数
     * */
    if (val >= 0) {
        printf("非负数\n");
    }
    else if (val < 0) {
        printf("负数\n");
    }
    return 0;
}





