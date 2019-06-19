/*
 * 三目操作符演示
 * */
#include <stdio.h>
int main() {
    int val = 0;
    printf("请输入一个数字：");
    scanf("%d", &val);
    val = val >= 0 ? val : 0 - val;
    //val >= 0 ? val = val : val = 0 - val;
    printf("绝对值是%d\n", val);
    return 0;
}







