/*
 * 回调函数演示
 * */
#include <stdio.h>
typedef void (*pfunc_t)(int *);   //给函数指针类型起别名
void print(const int *p_val, int size) {
    int num = 0;
    for (num = 0;num <= size - 1;num++) {
        printf("%d ", *(p_val + num));
    }
    printf("\n");
}
void print_cb(int *p_val) {
    printf("%d ", *p_val);
}
void neg_cb(int *p_val) {
    *p_val = 0 - *p_val;
}
void for_each(int *p_val, int size, pfunc_t p_func) {   //函数指针形参代表一个函数，这个函数用来处理数组里的每个存储区
    int num = 0;
    for (num = 0;num <= size - 1;num++) {
        p_func(p_val + num);
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    print(arr, 5);
    for_each(arr, 5, print_cb);  //把print_cb函数作为参数交给for_each函数使用
    printf("\n");
    for_each(arr, 5, neg_cb);   //把数组里每个存储区的内容都变成相反数
    for_each(arr, 5, print_cb);  //把print_cb函数作为参数交给for_each函数使用
    printf("\n");
    return 0;
}






