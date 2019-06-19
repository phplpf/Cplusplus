/*
 * 宏练习
 * */
#include <stdio.h>
#define   SQUARE(n)        ((n) * (n))
int main() {
    int val = 5;
    printf("100 / SQUARE(val)是%d\n", 100 / SQUARE(val));
    printf("SQUARE(2 + 3)是%d\n", SQUARE(2 + 3));
    printf("SQUARE(++val)是%d\n", SQUARE(++val));
    return 0;
}






