/*
 * 动态分配内存演示
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int size = 0, num = 0;
    int *p_val = NULL;
    srand(time(0));
    printf("请输入数字个数：");
    scanf("%d", &size);
    p_val = (int *)malloc(size * sizeof(int));
    if (p_val) {
        //分配成功
        for (num = 0;num <= size - 1;num++) {
            *(p_val + num) = rand() % 36 + 1;
        }
        for (num = 0;num <= size - 1;num++) {
            printf("%d ", *(p_val + num));
        }
        printf("\n");
        free(p_val);
        p_val = NULL;
    }
    return 0;
}





