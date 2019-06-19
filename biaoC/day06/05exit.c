/*
 * exit标准函数演示
 * */
#include <stdio.h>
#include <stdlib.h>
void func(void) {
    printf("2\n");
    //return ;
    exit(0);   //参数0的作用和主函数返回值的作用一样
    printf("3\n");
}
int main() {
    printf("1\n");
    func();
    printf("4\n");
    return 0;
}







