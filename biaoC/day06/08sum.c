/*
 * 递归练习
 * */
#include <stdio.h>
int sum(int max) {
    if (max == 1) {
        return 1;
    }
    return sum(max - 1) + max;
}
int main() {
    int max = 0;
    printf("请输入最大数字：");
    scanf("%d", &max);
    printf("结果是%d\n", sum(max));
    return 0;
}




