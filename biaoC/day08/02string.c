/*
 * 字符串函数演示
 * */
#include <stdio.h>
int main() {
    char ch = 0;
    int val = 0;
    float fval = 0.0f;
    char buf[20] = {0};
    //printf("%d %g %c\n", 45, 4.2f, 'p');
    sprintf(buf, "%d %g %c\n", 45, 4.2f, 'p');
    printf("%s", buf);
    //scanf("%c%d%g", &ch, &val, &fval);
    sscanf("t 23 7.1", "%c%d%g", &ch, &val, &fval);   //从字符串里获得数字并记录到存储区里
    printf("%d %g %c\n", val, fval, ch);
    return 0;
}






