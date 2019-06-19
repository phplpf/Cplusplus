/*
 * 递归函数演示
 * */
#include <stdio.h>
void print(int);
void print(int max) {
    if (max == 1) {
        //处理不可分解的情况
        printf("1 ");
        return ;   //分支必须保证函数可以结束
    }
    print(max - 1);   //显示从1到max - 1之间的所有整数
    printf("%d ", max);   //显示max本身
}
int main() {
    int max = 0;
    printf("请输入最大数字：");
    scanf("%d", &max);
    print(max);
    printf("\n");
    return 0;
}



