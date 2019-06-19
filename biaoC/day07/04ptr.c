/*
 * 指针演示
 * */
#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *p_val = NULL;
    for (p_val = arr;p_val <= arr + 4;p_val++) {   //指针循环变量从数组里第一个存储区开始从前向后依次指向每个存储区，直到最后一个存储区为止
        printf("%d ", *p_val);
    }
    printf("\n");
    return 0;
}






