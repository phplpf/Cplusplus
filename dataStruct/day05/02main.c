/*
 * 树测试
 * */
#include <stdio.h>
#include "02tree.h"
void print_cb(int val) {
    printf("%d ", val);
}
int main() {
    tree_t tr = {0};
    tree_init(&tr);
    tree_insert(&tr, 50);
    tree_insert(&tr, 25);
    tree_insert(&tr, 75);
    tree_insert(&tr, 13);
    tree_insert(&tr, 37);
    tree_insert(&tr, 66);
    tree_insert(&tr, 99);
    tree_insert(&tr, 7);
    tree_miter(&tr, print_cb);
    printf("\n");
    tree_deinit(&tr);
    return 0;
}




