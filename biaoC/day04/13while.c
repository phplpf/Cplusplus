/*
 * while循环练习
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int val = 0, guess = 0;
    srand(time(0));
    //val = rand() % 100;
    /*while (val != guess) {
        printf("请猜一个数字：");
        scanf("%d", &guess);
        if (val > guess) {
            printf("猜小了\n");
        }
        else if (val < guess) {
            printf("猜大了\n");
        }
        else {
            printf("猜对了\n");
        }
    }*/
    do {
        printf("请猜一个数字：");
        scanf("%d", &guess);
        if (val > guess) {
            printf("猜小了\n");
        }
        else if (val < guess) {
            printf("猜大了\n");
        }
        else {
            printf("猜对了\n");
        }
    } while (val != guess);
    return 0;
}








