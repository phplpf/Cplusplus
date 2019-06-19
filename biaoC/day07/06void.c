/*
 * 无类型指针演示
 * */
#include <stdio.h>
int main() {
    char ch = 'r';
    int val = 10;
    float fval = 4.5f;
    void *p_v = NULL;
    p_v = &ch;    //无类型指针指向字符类型存储区
    printf("%c\n", *(char *)p_v);
    p_v = &val;
    printf("%d\n", *(int *)p_v);
    p_v = &fval;
    printf("%g\n", *(float *)p_v);
    return 0;
}







