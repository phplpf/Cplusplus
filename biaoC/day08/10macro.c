/*
 * 宏演示
 * */
#include <stdio.h>
#define    PI               3.14f
#define    CIRCLE(r)        2 * PI * r
int main() {
    int radius = 0;
    float pi = 3.14f;
    printf("请输入半径：");
    scanf("%d", &radius);
    printf("周长是%g\n", CIRCLE(radius));
    printf("周长是%g\n", 2 * pi * radius);
    return 0;
}







