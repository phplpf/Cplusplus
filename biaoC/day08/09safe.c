/*
 * 保险柜练习
 * */
#include <stdio.h>
#include <string.h>
int main() {
    char buf[10] = {0};
    int num = 0;
    for (num = 0;num <= 2;num++) {
        printf("请输入密码：");
        fgets(buf, 10, stdin);
        if (strlen(buf) == 9 && buf[8] != '\n') {
            scanf("%*[^\n]");
            scanf("%*c");
        }
        if (!strcmp(buf, "123456\n")) {
            //输入正确
            printf("打开成功\n");
            return 0;
        }
    }
    printf("已经报警\n");
    return 0;
}





