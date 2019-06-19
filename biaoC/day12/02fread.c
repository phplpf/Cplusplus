/*
 * fread函数演示
 * */
#include <stdio.h>
int main() {
    int arr[5] = {0}, size = 0, num = 0;
    FILE *p_file = fopen("a.bin", "rb");
    if (p_file) {
        size = fread(arr, sizeof(int), 10, p_file);
        printf("size是%d\n", size);
        for (num = 0;num <= size - 1;num++) {
            printf("%d ", arr[num]);
        }
        printf("\n");
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}





