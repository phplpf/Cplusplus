/*
 * 字符串演示
 * */
#include <stdio.h>
int main() {
    char str[] = "abc";    //会把'\0'字符初始化到数组里去
    printf("sizeof(str)是%d\n", sizeof(str));
    printf("%s\n", "daef");
    printf("%s\n", str);
    return 0;
}






