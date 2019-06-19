/*
 * 数组演示
 * */
#include <stdio.h>
int main() {
    int arr[5] = {0};
    //arr = 10;    数组名称不代表存储区，不能被赋值
    printf("arr是%p,&arr[0]是%p\n", arr, &arr[0]);   //数组名称代表数组里下标为0存储区的地址
    printf("sizeof(arr)是%d\n", sizeof(arr));
    return 0;
}






