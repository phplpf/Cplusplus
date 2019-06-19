/*
 * 指针演示
 * */
#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *p_val = arr;   //指针p_val指向数组里第一个存储区
    int num = 0;
    for (num = 0;num <= 4;num++) {
        printf("%d ", arr[num]);
        printf("%d ", *(arr + num));
        printf("%d ", p_val[num]);   //不要采用这种写法
        printf("%d ", *(p_val + num));
    }
    printf("\n");
    return 0;
}






