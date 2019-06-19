/*
 * 参数演示
 * */
#include <stdio.h>
int add(int val, int val1) {
    return val + val1;
}
int main() {
    int val = add(5, 9);
    printf("val是%d\n", val);
    val = add(8 - 3, 6 * 2);
    printf("val是%d\n", val);
    return 0;
}






