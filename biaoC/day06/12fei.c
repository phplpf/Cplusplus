/*
 *  费氏数列练习
 * */
#include <stdio.h>
int arr[50];
int fei(int sn) {
    //static int arr[50];
    if (sn <= 1) {
        //计算编号为0和1的数字
        return 1;
    }
    //保证数组里以sn - 2做下标的
    //存储区里是有数字的
    if (!arr[sn - 2]) {
        arr[sn - 2] = fei(sn - 2);
    }
    //保证数组里以sn - 1做下标的
    //存储区里是有数字的
    if (!arr[sn - 1]) {
        arr[sn - 1] = fei(sn - 1);
    }
    return arr[sn - 2]/*编号为sn - 2的数字*/ + arr[sn - 1]/*编号为sn - 1的数字*/;
}
int main() {
    int sn = 0;
    printf("请输入编号：");
    scanf("%d", &sn);
    printf("结果是%d\n", fei(sn));
    return 0;
}




