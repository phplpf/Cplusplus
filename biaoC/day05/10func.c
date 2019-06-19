/*
 * 返回值练习
 * */
#include <stdio.h>
int rabbit(int heads, int legs) {
    int num = 0;
    for (num = 0;num <= heads;num++) {
        if (4 * num + 2 * (heads - num) == legs) {
            return num;
        }
    }
    return -1;
}
int main() {
    int heads = 0, legs = 0, result = 0;
    printf("请输入头和脚的数量：");
    scanf("%d%d", &heads, &legs);
    result = rabbit(heads, legs);
    if (result == -1) {
        printf("没有找到答案\n");
    }
    else {
        printf("答案是%d\n", result);
    }
    return 0;
}




