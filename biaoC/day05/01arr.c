/*
 * 数组演示
 * */
#include <stdio.h>
int main() {
    //int arr[5] = {0, 1, 2, 3, 4};     //数组声明
    //int arr[5] = {0, 1, 2, 3, 4, 5, 6};  //5和6会被忽略，因为它们没有对应的存储区
    //int arr[5] = {0, 1, 2};      //后两个存储区自动被初始化成0
    int arr[] = {0, 1, 2, 3, 4};   //根据初始化数据个数分配数组里的存储区个数
    int num = 0;
    //arr[2]/*代表数组中间的存储区*/ = 10;
    /*for (num = 0;num <= 4;num++) {
        arr[num] = num;   //存储区的内容被赋值成下标
    }*/
    for (num = 4;num >= 0;num--) {
        printf("%d ", arr[num]);
    }
    printf("\n");
    return 0;
}






