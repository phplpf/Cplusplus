/*
 * 输入缓冲区演示
 * */
#include <stdio.h>
int main() {
    int val = 0, val1 = 0;
    printf("请输入一个数字：");
    scanf("%d", &val);
    scanf("%*[^\n]");
    scanf("%*c");
    printf("val是%d\n", val);
    printf("请输入一个数字：");
    scanf("%d", &val1);
    printf("val1是%d\n", val1);
    return 0;
}





