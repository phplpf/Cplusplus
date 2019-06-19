/*
 * 字符串演示
 * */
#include <stdio.h>
#include <string.h>
int main() {
    char str[10] = "abc";
    char *p_ch = NULL;
    printf("字符个数是%d\n", strlen(str));
    printf("sizeof(str)是%d\n", sizeof(str));
    p_ch = strcat(str, "def");    //把第二个字符串的内容追加到第一个字符串的末尾，第一个参数必须是字符数组里的字符串
    printf("%s\n", p_ch);
    printf("%s\n", str);
    p_ch = strncat(str, "dgjkkljdg", 3);   //参数3表示 最多只能追加3个字符到字符数组里
    printf("%s\n", p_ch);
    printf("%s\n", str);
    return 0;
}







