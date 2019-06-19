/*
 * 函数声明演示
 * */
#include <stdio.h>
double add(double, double);   //函数声明语句
int main() {
    int val = add(3, 6);
    printf("val是%d\n", val);
    return 0;
}
double add(double val, double val1) {
    return val + val1;
}





