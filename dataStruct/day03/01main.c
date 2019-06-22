/*
 * 队列测试
 * */
#include <stdio.h>
#include "01queue.h"
int main() {
    int val = 0;
    queue_t que = {0};
    queue_init(&que);
    printf("判断空的结果是%d\n", queue_empty(&que));
    printf("判断满的结果是%d\n", queue_full(&que));
    printf("数字个数是%d\n", queue_size(&que));
    queue_push(&que, 10);
    queue_push(&que, 20);
    queue_push(&que, 30);
    printf("判断空的结果是%d\n", queue_empty(&que));
    printf("判断满的结果是%d\n", queue_full(&que));
    printf("数字个数是%d\n", queue_size(&que));
    queue_front(&que, &val);
    printf("最前面的数字是%d\n", val);
    queue_pop(&que, &val);
    printf("%d ", val);
    queue_pop(&que, &val);
    printf("%d\n", val);
    printf("判断空的结果是%d\n", queue_empty(&que));
    printf("判断满的结果是%d\n", queue_full(&que));
    printf("数字个数是%d\n", queue_size(&que));
    queue_push(&que, 40);
    queue_push(&que, 50);
    printf("判断空的结果是%d\n", queue_empty(&que));
    printf("判断满的结果是%d\n", queue_full(&que));
    printf("数字个数是%d\n", queue_size(&que));
    while (1) {
        if (!queue_pop(&que, &val)) {
            break;
        }
        printf("%d ", val);
    }
    printf("\n");
    printf("判断空的结果是%d\n", queue_empty(&que));
    printf("判断满的结果是%d\n", queue_full(&que));
    printf("数字个数是%d\n", queue_size(&que));
    queue_deinit(&que);
    return 0;
}





