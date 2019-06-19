/*
 * 二级指针演示
 * */
#include <stdio.h>
int main() {
    int val = 0;
    int *p_val = &val;
    int **pp_val = &p_val;    //二级指针声明，这个二级指针指向一级指针p_val
    **pp_val = 10;   //二级指针前使用**可以表示普通类型存储区
    printf("val是%d\n", val);
    *pp_val = NULL;  //二级指针前使用*可以表示一级指针
    printf("p_val是%p\n", p_val);
    return 0;
}





