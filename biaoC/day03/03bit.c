/*
 * 位操作符演示
 * */
#include <stdio.h>
int main() {
    char ch = ~0x93;
    int val = ch;
    printf("val是0x%x\n", val);
    printf("3 & 5是%d\n", 3 & 5);
    printf("3 | 5是%d\n", 3 | 5);
    printf("3 ^ 5是%d\n", 3 ^ 5);
    printf("3 << 2是%d\n", 3 << 2);
    return 0;
}






