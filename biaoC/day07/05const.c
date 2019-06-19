/*
 * const指针演示
 * */
#include <stdio.h>
int main() {
    int val = 0;
    const int *p_val = &val;
    int * const p_val1 = &val;
    //*p_val = 10;     错误
    p_val = NULL;
    *p_val1 = 10;
    //p_val1 = NULL;
    return 0;
}







