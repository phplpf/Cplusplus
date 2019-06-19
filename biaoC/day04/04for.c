/*
 * for循环演示
 * */
#include <stdio.h>
int main() {
    int val = 0;
    unsigned char ch = 0;
    printf("请输入一个数字：");
    scanf("%d", &val);
    printf("转换结果是");
    for (ch = 0x80;ch >= 1;ch >>= 1) {   //循环变量ch代表的每个数字用来从val变量里获得一个数位内容
        printf("%d", (val & ch) != 0);
    }
    printf("\n");
    return 0;
}





