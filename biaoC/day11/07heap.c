/*
 * 动态分配内存演示
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *create(int size) {
    int num = 0;
    int *p_val = (int *)malloc(size * sizeof(int));
    if (p_val) {
        for (num = 0;num <= size - 1;num++) {
            *(p_val + num) = rand() % 36 + 1;
        }
    }
    return p_val;   //如果分配内存成功就返回有效地址，如果分配失败就返回NULL
}
int main() {
    int *p_val = NULL;
    int size = 0, num = 0;
    srand(time(0));
    printf("请输入数字个数：");
    scanf("%d", &size);
    p_val = create(size);
    if (p_val) {
        //内存分配成功
        for (num = 0;num <= size - 1;num++) {
            printf("%d ", *(p_val + num));
        }
        printf("\n");
        free(p_val);
        p_val = NULL;
    }
    return 0;
}






