/*
 * 动态分配内存演示
 * */
#include <stdio.h>
#include <stdlib.h>
int main() {
    int *p_val = (int *)malloc(5 * sizeof(int));   //分配5个连续的整数类型存储区
    /*if (p_val) {
        //分配内存成功
        //编写语句使用动态分配的内存
        free(p_val);  //释放动态分配内存
        p_val = NULL;
    }*/
    if (!p_val) {
        //分配内存失败
        return 0;
    }
    //编写语句使用动态分配内存
    free(p_val);
    p_val = NULL;
    return 0;
}







