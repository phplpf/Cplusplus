/*
 * 排序算法演示
 * */
#include <stdio.h>
//冒泡排序函数
void bubble_sort(int *p_val, int size) {
    int num = 0, num1 = 0, tmp = 0;
    for (num = size - 1;num >= 1;num--) {
        //每次循环把合适的数字放在
        //循环变量num做下标的存储区里
        for (num1 = 0;num1 <= num - 1;num1++) {
            //把下标为num1和num1 + 1的
            //两个存储区内容做顺序调整
            if (*(p_val + num1) > *(p_val + num1 + 1)) {
                //前面存储区的内容大
                //就需要交换两个存储区
                //的内容
                tmp = *(p_val + num1);
                *(p_val + num1) = *(p_val + num1 + 1);
                *(p_val + num1 + 1) = tmp;
            }
        }
    }
}
void bubble_sort1(int *p_val, int size) {
    int num = 0, num1 = 0, tmp = 0;
    for (num = 0;num <= size - 2;num++) {
        for (num1 = size - 2;num1 >= num;num1--) {
            if (*(p_val + num1) < *(p_val + num1 + 1)) {
                tmp = *(p_val + num1);
                *(p_val + num1) = *(p_val + num1 + 1);
                *(p_val + num1 + 1) = tmp;
            }
        }
    }
}
//选择排序算法函数
void choice_sort(int *p_val, int size) {
    int num = 0, num1 = 0, tmp = 0;
    for (num = size - 1;num >= 1;num--) {
        //每次循环把合适的数字放在
        //下标为num的存储区里
        for (num1 = 0;num1 <= num - 1;num1++) {
            //每次循环把选定位置里的
            //数字和下标为num1的存储区
            //里的数字进行顺序调整
            if (*(p_val + num1) > *(p_val + num)) {
                tmp = *(p_val + num1);
                *(p_val + num1) = *(p_val + num);
                *(p_val + num) = tmp;
            }
        }
    }
}
//插入排序函数
void insert_sort(int *p_val, int size) {
    int num = 0, num1 = 0, tmp = 0;
    for (num = 1;num <= size - 1;num++) {
        //每次循环把下标为num的存储区
        //里的内容向前插入到合适位置上
        for (num1 = num - 1;num1 >= 0;num1--) {
            //每次把选定数字向下标
            //为num1的存储区里插入
            //(选定数字一定在下标为
            //num1 + 1的存储区里)
            if (*(p_val + num1) > *(p_val + num1 + 1)) {
                tmp = *(p_val + num1);
                *(p_val + num1) = *(p_val + num1 + 1);
                *(p_val + num1 + 1) = tmp;
            }
            else {
                break;
            }
        }
    }
}
//快速排序函数
void quick_sort(int *p_val, int size) {
    int base = *p_val;   //把最前面的数字作为选定数字记录下来
    int *p_head = p_val;   //p_head指针指向两个存储区里前面的那个(最开始的时候指向数组里最前面的存储区)
    int *p_tail = p_val + size - 1;  //p_tail指针指向两个存储区里后面的那个(最开始的时候指向数组里最后的存储区)
    int tmp = 0;
    if (size <= 1) {
        //要排序的数字个数不超过1个
        return ;
    }
    while (p_head < p_tail) {   //如果两个指针没有互相重叠就表示还有数字没有处理完，循环应该继续
        if (*p_head > *p_tail) {
            //如果两个存储区里前面
            //存储区的内容大就需要
            //交换它们的内容
            tmp = *p_head;
            *p_head = *p_tail;
            *p_tail = tmp;
        }
        //排除非选定数字
        if (*p_head == base) {
            //前面的数字是选定数字，
            //这个时候应该排除后面
            //的数字
            p_tail--;
        }
        else {
            //后面的数字是选定数字，
            //这个时候应该排除前面
            //的数字
            p_head++;
        }
    }
    //循环结束后两个指针互相重叠，
    //它们都指向选定数字所在的存储区
    //递归调用quick_sort函数对左半边
    //数字进行排序
    quick_sort(p_val, p_head - p_val/*左半边的存储区个数*/);
    //递归调用quick_sort函数对右半边
    //数字进行排序
    quick_sort(p_head + 1, size - (p_head - p_val) - 1/*右半边的存储区个数*/);
}
int main() {
    int arr[] = {50, 20, 80, 30, 10, 40, 70, 60};
    int num = 0;
    //bubble_sort(arr, 8);
    //bubble_sort1(arr, 8);
    //choice_sort(arr, 8);
    //insert_sort(arr, 8);
    quick_sort(arr, 8);
    for (num = 0;num <= 7;num++) {
        printf("%d ", arr[num]);
    }
    printf("\n");
    return 0;
}




