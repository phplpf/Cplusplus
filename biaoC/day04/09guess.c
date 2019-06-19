/*
 * 猜数游戏练习
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int val = 0, guess = 0;
    srand(time(0));
    val = rand() % 100;  //得到一个0到99之间的随机数
    for (;;) {
        printf("请猜一个数字：");
        scanf("%d", &guess);
        if (val > guess) {
            //猜小了的情况
            printf("猜小了\n");
        }
        else if (val < guess) {
            //猜大了的情况
            printf("猜大了\n");
        }
        else {
            //猜对了
            printf("猜对了\n");
            break;
        }
    }
    return 0;
}







