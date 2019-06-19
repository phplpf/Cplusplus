/*
 * 指针演示
 * */
#include <stdio.h>
void swap(int *p_val, int *p_val1) {
    int tmp = *p_val;
    *p_val = *p_val1;
    *p_val1 = tmp;
}
void swap1(void *p_v, void *p_v1, int size) {
    //把两个存储区当做两个字符类型
    //数组进行内容交换
    int num = 0;
    char ch = 0;
    char *p_ch = (char *)p_v;
    char *p_ch1 = (char *)p_v1;
    for (num = 0;num <= size - 1;num++) {
        ch = *(p_ch + num);
        *(p_ch + num) = *(p_ch1 + num);
        *(p_ch1 + num) = ch;
    }
}
int main() {
    int val = 3, val1 = 7;
    char ch = 'r', ch1 = 'x';
    //swap(&val, &val1);
    //printf("val是%d,val1是%d\n", val, val1);
    swap1(&val, &val1, sizeof(int));
    printf("val是%d,val1是%d\n", val, val1);
    swap1(&ch, &ch1, sizeof(char));
    printf("ch是%c,ch1是%c\n", ch, ch1);
    return 0;
}




