/*
 * 类型转换演示
 * */
#include <stdio.h>
int main() {
    printf("sizeof(1 ? 1 : 0.9)是%d\n", sizeof(1 ? 1 : 0.9));
    printf("-7 + 3 > 0是%d\n", -7 + 3 > 0);
    printf("-7 + 3u > 0是%d\n", -7 + 3u > 0);
    printf("(char)300是%d\n", (char)300);
    return 0;
}






