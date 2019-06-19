/*
 * 宏操作符演示
 * */
#include <stdio.h>
#define    STR(n)         #n
#define    PTR(n)         p_##n
int main() {
    int val = 0;
    int *PTR(val) = &val;
    STR(2 + 3);
    return 0;
}







