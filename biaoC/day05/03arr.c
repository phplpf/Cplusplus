/*
 * 数组练习
 * */
#include <stdio.h>
int main() {
    int card[17] = {0};   //记录身份证号码的前17个数位的内容
    int arr[] = {7, 9, 10, 5, 8, 4, 2, 1,
                 6, 3, 7, 9, 10, 5, 8,
                 4, 2};    //记录题目中给出的17个数字
    int arr1[] = {1, 0, -1, 9, 8, 7, 6, 5, 4, 3, 2};   //记录备选的11个数字
    int num = 0, sum = 0;
    //得到用户输入的前17个数位内容
    for (num = 0;num <= 16;num++) {
        printf("请输入一个数位内容：");
        scanf("%d", &card[num]);
    }
    //把两个数组对应位置的数字相乘并求和
    for (num = 0;num <= 16;num++) {
        sum += arr[num] * card[num];
    }
    //找到最终的结果
    if (arr1[sum % 11] == -1) {
        printf("结果是X\n");
    }
    else {
        printf("结果是%d\n", arr1[sum % 11]);
    }
    return 0;
}




