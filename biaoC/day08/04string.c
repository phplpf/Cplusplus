/*
 *  字符串演示
 * */
#include <stdio.h>
#include <string.h>
int main() {
    char str[10] = {0};
    printf("请输入一个字符串：");
    fgets(str, 10, stdin);
    if (strlen(str) == 9 && str[8] != '\n') {  //数组里不包含'\n'换行字符
        scanf("%*[^\n]");
        scanf("%*c");
    }
    //scanf("%s", str);    有可能出错误
    printf("%s\n", str);
    printf("请输入一个字符串：");
    fgets(str, 10, stdin);
    //scanf("%s", str);    有可能出错误
    printf("%s\n", str);
    return 0;
}





