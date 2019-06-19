/*
 * 变量分类演示
 * */
#include <stdio.h>
int val_g = 0;         //全局变量
static int val_sg = 0; //静态全局变量
int main() {
    int val = 0;            //非静态局部变量
    static int val_s = 0;   //静态局部变量
    return 0;
}



