/*
 * fwrite函数演示
 * */
#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = 0;
    FILE *p_file = fopen("a.bin", "wb");
    if (p_file) {
        size = fwrite(arr, sizeof(int), 5, p_file);
        printf("size是%d\n", size);
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}






