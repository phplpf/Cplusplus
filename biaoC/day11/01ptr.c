/*
 * 二级指针演示
 * */
#include <stdio.h>
int main() {
    char ch = 'r';
    int val = 45;
    float fval = 4.7f;
    char *p_ch = &ch;
    int *p_val = &val;
    float *p_fval = &fval;
    void *p_v = NULL;
    p_v = &p_ch;   //无类型指针指向字符类型指针
    **(char **)p_v = 'p';   //对ch变量做赋值
    printf("ch是%c\n", ch);
    p_v = &p_val;
    **(int **)p_v = 10;    //对val变量做赋值
    printf("val是%d\n", val);
    p_v = &p_fval;
    **(float **)p_v = 8.2f;  //对fval变量赋值
    printf("fval是%g\n", fval);
    return 0;
}






