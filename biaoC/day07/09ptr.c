/*
 * 指针演示
 * */
#include <stdio.h>
int *read(void) {
    static int val = 0;
    printf("请输入一个数字：");
    scanf("%d", &val);
    return &val;
}
int main() {
    int *p_val = read();
    printf("数字是%d\n", *p_val);
    return 0;
}







