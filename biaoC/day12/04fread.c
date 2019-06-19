/*
 * fread函数练习
 * */
#include <stdio.h>
int main() {
    int arr[5][5] = {0};
    int num = 0, row = 0, col = 0;
    FILE *p_file = fopen("b.bin", "rb");
    if (p_file) {
        for (num = 4;num >= 0;num--) {
            fread(arr[num], sizeof(int), 5, p_file);
        }
        for (row = 0;row <= 4;row++) {
            for (col = 0;col <= 4;col++) {
                printf("%d", arr[row][col]);
            }
            printf("\n");
        }
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}





