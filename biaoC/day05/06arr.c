/*
 * 二维数组练习
 * */
#include <stdio.h>
int main() {
    int arr[5][5] = {0};
    int row = 0, col = 0;
    for (row = 0;row <= 4;row++) {
        for (col = 0;col <= 4;col++) {
            if (!row && col <= 3) {
                //第一组的前四个存储区
                arr[row][col] = 1;
            }
            else if (row <= 3 && col == 4) {
                //最后一列的前四个存储区
                arr[row][col] = 2;
            }
            else if (row == 4 && col >= 1) {
                //最后一组的后四个存储区
                arr[row][col] = 3;
            }
            else if (row >= 1 && !col) {
                //第一列的后四个存储区
                arr[row][col] = 4;
            }
        }
    }
    for (row = 0;row <= 4;row++) {
        for (col = 0;col <= 4;col++) {
            printf("%d", arr[row][col]);
        }
        printf("\n");
    }
    return 0;
}







