/*
 * 地址计算规则演示
 * */
#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    printf("arr是%p\n", arr);
    printf("arr + 1是%p\n", arr + 1);
    printf("arr - 1是%p\n", arr - 1);
    printf("&arr[2] - arr是%d\n", &arr[2] - arr);
    return 0;
}






