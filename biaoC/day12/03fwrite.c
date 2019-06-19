/*
 * fwrite函数练习
 * */
#include <stdio.h>
int main() {
    int arr[][5] = {1, 1, 1, 1, 1,
                    2, 2, 2, 2, 2,
                    3, 3, 3, 3, 3,
                    4, 4, 4, 4, 4,
                    5, 5, 5, 5, 5};
    int size = 0;
    FILE *p_file = fopen("b.bin", "wb");
    if (p_file) {
        size = fwrite(arr, sizeof(int), 25, p_file);
        printf("size是%d\n", size);
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}





