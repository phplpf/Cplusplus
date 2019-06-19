/*
 * 字符串练习
 * */
#include <stdio.h>
#include <string.h>
int main() {
    char str[30] = {0}, tmp[10] = {0};
    int num = 0, grade = 0;
    for (num = 0;num <= 4;num++) {
        printf("请输入一个考试成绩：");
        scanf("%d", &grade);
        sprintf(tmp, "%d,", grade);   //把单个考试成绩转换成字符串并记录到tmp数组里
        strcat(str, tmp);
    }
    str[strlen(str) - 1] = 0;   //把最后一个','字符替换成'\0'字符
    printf("结果是%s\n", str);
    return 0;
}






