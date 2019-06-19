/*
 * 点菜练习
 * */
#include <stdio.h>
int main() {
    int order = 0;
    printf("请点菜：");
    scanf("%d", &order);
#ifdef         ZHAO
    if (order == 2) {
        printf("真没有\n");
    }
    else {
        printf("没有\n");
    }
#else
    if (order == 2) {
        printf("没有\n");
    }
    else {
        printf("有\n");
    }
#endif
    return 0;
}





