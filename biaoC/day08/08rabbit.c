/*
 * 主函数参数练习
 * */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int heads = 0, legs = 0;
    int num = 0;
    heads = atoi(argv[1]);
    legs = atoi(argv[2]);
    for (num = 0;num <= heads;num++) {
        if (4 * num + 2 * (heads - num) == legs) {
            printf("兔子有%d只，鸡有%d只\n", num, heads - num);
            return 0;
        }
    }
    printf("数据错误，没有找到答案\n");
    return 0;
}





