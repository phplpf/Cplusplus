/*
 * 宏演示
 * */
#include <stdio.h>
#define  ABS(n)       n >= 0 ? n : 0 - n
#define  NEG(n)       n = 0 - n
int abs(int val) {
    if (val >= 0) {
        return val;
    }
    else {
        return 0 - val;
    }
}
int main() {
    int val = 0;
    printf("请输入一个数字：");
    scanf("%d", &val);
    printf("绝对值是%d\n", abs(val));
    printf("绝对值是%d\n", ABS(val));
    NEG(val);
    printf("val是%d\n", val);
    return 0;
}




