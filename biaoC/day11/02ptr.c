/*
 * 二级指针演示
 * */
#include <stdio.h>
void swap(int *p_val, int *p_val1) {
    int tmp = *p_val;
    *p_val = *p_val1;
    *p_val1 = tmp;
}
//把p_val和p_val1指向的存储区
//交换过来
void swap1(int **pp_val, int **pp_val1) {
    int *p_tmp = *pp_val;
    *pp_val = *pp_val1;
    *pp_val1 = p_tmp;
}
int main() {
    int val = 3, val1 = 7;
    int *p_val = &val, *p_val1 = &val1;
    //swap(&val, &val1);
    printf("val是%d,val1是%d\n", val, val1);
    printf("*p_val是%d,*p_val1是%d\n", *p_val, *p_val1);
    swap1(&p_val, &p_val1);
    printf("val是%d,val1是%d\n", val, val1);
    printf("*p_val是%d,*p_val1是%d\n", *p_val, *p_val1);
    return 0;
}





