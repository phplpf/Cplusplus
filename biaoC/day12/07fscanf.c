/*
 * fscanf标准函数演示
 * */
#include <stdio.h>
int main() {
    int val = 0, num = 0;
    FILE *p_file = fopen("a.txt", "r");
    if (p_file) {
        for (num = 0;num <= 4;num++) {
            //scanf("%d", &val);
            fscanf(p_file, "%d", &val);
            printf("%d ", val);
        }
        printf("\n");
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}





