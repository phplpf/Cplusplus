/*
 * fprintf标准函数演示
 * */
#include <stdio.h>
int main() {
    int arr[] = {45, 286, 1283, 5, 374};
    int num = 0;
    FILE *p_file = fopen("a.txt", "w");
    if (p_file) {
        for (num = 0;num <= 4;num++) {
            //printf("%d ", arr[num]);
            fprintf(p_file, "%d ", arr[num]);
        }
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}






