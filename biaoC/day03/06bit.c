/*
 * 二进制练习
 * */
#include <stdio.h>
int main() {
    int val = 0;
    unsigned char ch = 0x80;   //右移的时候左边空出来的数位里固定填0
    printf("请输入一个数字：");
    scanf("%d", &val);
    printf("转换结果是");
    printf("%d", (val & ch) != 0);
    ch >>= 1;   //ch变量里所有数位向右移动一步并把结果记录到ch变量里
    printf("%d", (val & ch) != 0);
    ch >>= 1;   //ch变量里所有数位向右移动一步并把结果记录到ch变量里
    printf("%d", (val & ch) != 0);
    ch >>= 1;   //ch变量里所有数位向右移动一步并把结果记录到ch变量里
    printf("%d ", (val & ch) != 0);
    ch >>= 1;   //ch变量里所有数位向右移动一步并把结果记录到ch变量里
    printf("%d", (val & ch) != 0);
    ch >>= 1;   //ch变量里所有数位向右移动一步并把结果记录到ch变量里
    printf("%d", (val & ch) != 0);
    ch >>= 1;   //ch变量里所有数位向右移动一步并把结果记录到ch变量里
    printf("%d", (val & ch) != 0);
    ch >>= 1;   //ch变量里所有数位向右移动一步并把结果记录到ch变量里
    printf("%d\n", (val & ch) != 0);
    return 0;
}






