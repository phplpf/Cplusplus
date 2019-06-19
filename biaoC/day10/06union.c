/*
 * 联合演示
 * */
#include <stdio.h>
typedef union {
    int val;
    float fval;
} tmp_t;
int main() {
    tmp_t utmp = {0};
    printf("&(utmp.val)是%p\n", &(utmp.val));
    printf("&(utmp.fval)是%p\n", &(utmp.fval));
    printf("sizeof(utmp)是%d\n", sizeof(utmp));
    return 0;
}



