/*
 * if分支练习
 * */
#include <stdio.h>
int main() {
    int val = 0;
    printf("请输入一个数字:");
    scanf("%d", &val);
    /*
     * val > 0 *  显示正数
     *************************
     * val < 0 *  显示负数
     *************************
     * !val    *  显示零
     * */
    if (val > 0) {
        printf("正数\n");
    }
    else if (val < 0) {
        printf("负数\n");
    }
    else {
        printf("零\n");
    }
    return 0;
}






