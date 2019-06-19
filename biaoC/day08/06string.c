/*
 * 字符串练习
 * */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char str[30] = {0};
    char *p_ch = str;   //指向每个考试成绩开始位置
    int grade = 0, sum = 0;
    printf("请输入考试成绩：");
    fgets(str, 30, stdin);
    if (strlen(str) == 29 && str[28] != '\n') {
        scanf("%*[^\n]");
        scanf("%*c");
    }
    while (1) {
        //每次循环拆出一个考试成绩
        grade = atoi(p_ch);
        sum += grade;
        //让p_ch指针指向下一个考试
        //成绩的开始位置
        p_ch = strstr(p_ch, ",");
        if (!p_ch) {
            //没有找到后面的逗号
            break;
        }
        p_ch++;
    }
    printf("成绩综合是%d\n", sum);
    return 0;
}





