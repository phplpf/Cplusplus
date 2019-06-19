/*
 * 二维数组演示
 * */
#include <stdio.h>
int main() {
    int arr[][2] = {{1}, {2}, {3}};    //二维数组声明，一共分为三组，每组里有两个存储区
    //arr[1][0] = 10;
    int row = 0, col = 0, cnt = 1;
    /*for (row = 0;row <= 2;row++) {
        for (col = 0;col <= 1;col++) {
            arr[row][col] = cnt;
            cnt++;
        }
    }*/
    for (row = 0;row <= 2;row++) {
        for (col = 0;col <= 1;col++) {
            printf("%d ", arr[row][col]);
        }
        printf("\n");
    }
    return 0;
}









