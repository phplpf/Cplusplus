/*
 * for循环练习
 * */
#include <stdio.h>
int main() {
    int num = 0;
    for (num = 0;num <= 40;num++) {  //把0到40之间的每个数字作为兔子的数量测试一下
        if (4 * num + 2 * (40 - num) == 100) {
            //处理循环变量就是要找的兔子数量的情况
            printf("兔子有%d只，鸡有%d只\n", num, 40 - num);
            break;
        }
    }
    printf("num是%d\n", num);
    return 0;
}







