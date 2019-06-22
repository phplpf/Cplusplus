/*
 * 链表测试
 * */
#include <stdio.h>
#include "01link.h"
int main() {
    int val = 0, size = 0, num = 0;
    link_t lnk = {0};
    link_init(&lnk);
    link_add_head(&lnk, 50);
    link_add_head(&lnk, 30);
    link_append(&lnk, 70);
    link_append(&lnk, 100);
    link_insert(&lnk, 80);
    link_insert(&lnk, 40);
    link_insert(&lnk, 20);
    link_insert(&lnk, 10);
    link_insert(&lnk, 90);
    link_insert(&lnk, 60);
    size = link_size(&lnk);
    printf("数字个数是%d\n", size);
    link_get_head(&lnk, &val);
    printf("最前面的数字是%d\n", val);
    link_get_tail(&lnk, &val);
    printf("最后面的数字是%d\n", val);
    link_remove_head(&lnk);
    link_remove_tail(&lnk);
    link_remove(&lnk, 80);
    size = link_size(&lnk);
    printf("数字个数是%d\n", size);
    link_get_head(&lnk, &val);
    printf("最前面的数字是%d\n", val);
    link_get_tail(&lnk, &val);
    printf("最后面的数字是%d\n", val);
    //利用for循环从前向后获得链表
    //里的每个数字并显示在屏幕上
    for (num = 0;num <= size - 1;num++) {
        link_get(&lnk, num, &val);
        printf("%d ", val);
    }
    printf("\n");
    link_deinit(&lnk);
    return 0;
}





