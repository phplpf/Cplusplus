/*
 * 返回值演示
 * */
#include <stdio.h>
int read(void) {
    int val = 0;
    printf("请输入一个数字：");
    scanf("%d", &val);
    return val;
}
int main() {
    int val = read();
    printf("val是%d\n", val);
    return 0;
}






