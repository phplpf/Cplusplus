/*
 * 字符串演示
 * */
#include <stdio.h>
#include <string.h>
int main() {
    char str[10] = "akdlgjsg";
    char *p_ch = NULL;
    int ret = 0;
    ret = strcmp("abc", "abd");  //'d'的ASCII码比'c'大，所以后一个字符串大
    printf("比较结果是%d\n", ret);
    ret = strncmp("abc", "abd", 2);
    printf("比较结果是%d\n", ret);
    p_ch = strcpy(str, "abc");   //会把最后的'\0'字符也复制到字符数组里
    printf("%s\n", p_ch);
    printf("%s\n", str);
    p_ch = strncpy(str, "def", 2);   //参数2表示最多只能复制2个字符.有可能不复制\0字符
    printf("%s\n", p_ch);
    printf("%s\n", str);
    memset(str, 'r', 9);   //把数组里前9个字符类型存储区的内容都设置成字符'r'
    printf("%s\n", str);
    p_ch = strstr("abcdefghijklmn", "def");   //在前一个字符串里找后一个字符串的位置
    printf("%s\n", p_ch);
    return 0;
}








