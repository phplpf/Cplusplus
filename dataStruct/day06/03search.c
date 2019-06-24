/*
 * 折半查找算法演示
 * */
#include <stdio.h>
//折半查找函数
int *half_search(const int *p_val, int size, int val) {
    const int *p_head = p_val;   //p_head指针指向查找范围里最前面的存储区，最开始的时候指向数组里的第一个存储区
    const int *p_tail = p_val + size - 1;  //p_tail指针指向查找范围里最后面的存储区，最开始的时候指向数组里的最后一个存储区
    const int *p_mid = NULL;
    while (p_head <= p_tail) {   //两个指针还没有交错，这个时候就应该继续查找
        //每次循环排除掉一半的数字
        p_mid = p_head + (p_tail - p_head + 1)/*所有存储区的总个数*/ / 2;
        if (*p_mid == val) {
            //中间位置存储区的内容
            //就是要找的数字
            return (int *)p_mid;
        }
        else if (*p_mid > val) {
            //中间位置存储区里的内容
            //比要找的数字大，这个
            //时候应该排除右半边的
            //所有数字
            p_tail = p_mid - 1;
        }
        else {
            //中间位置存储区的内容
            //比要找的数字小，这个
            //时候应该排除左半边的
            //所有数字
            p_head = p_mid + 1;
        }
    }
    return NULL;    //表示没有找到数字
}
int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int val = 0, *p_val = NULL;
    printf("请输入要查找的数字：");
    scanf("%d", &val);
    p_val = half_search(arr, 10, val);
    if (p_val) {
        printf("找到的数字是%d\n", *p_val);
    }
    else {
        printf("没有找到数字\n");
    }
    return 0;
}







