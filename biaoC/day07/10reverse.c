/*
 * 指针练习
 * */
#include <stdio.h>
int *reverse(int *p_val, int size) {
    int *p_head = p_val;   //指向配对存储区里前面那个,初始化后指针指向第一个存储区
    int *p_tail = p_val + size - 1;   //指向配对存储区里后面那个，初始化后指针指向最后一个存储区
    int tmp = 0;
    while (p_head < p_tail) {
        //每循环一次交换一对配对
        //存储区的内容
        tmp = *p_head;
        *p_head = *p_tail;
        *p_tail = tmp;
        p_head++;
        p_tail--;
    }
    return p_val;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int num = 0;
    int *p_val = reverse(arr, 5);
    for (num = 0;num <= 4;num++) {
        printf("%d ", arr[num]);
        printf("%d ", *(p_val + num));
    }
    printf("\n");
    return 0;
}














