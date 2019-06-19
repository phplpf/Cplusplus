/*
 * if分支练习
 * */
#include <stdio.h>
int main() {
    int val = 0, val1 = 0, val2 = 0;
    printf("请输入三个数字：");
    scanf("%d%d%d", &val, &val1, &val2);
    /*if (val < val1 && val < val2) {
        printf("最小数字是%d\n", val);
    }
    else if (val1 < val && val1 < val2) {
        printf("最小数字是%d\n", val1);
    }
    else if (val2 < val && val2 < val1) {
        printf("最小数字是%d\n", val2);
    }*/
    if (val < val1) {
        //排除val1的情况
        if (val < val2) {
            //排除val2的情况
            printf("最小数字是%d\n", val);
        }
        else {
            //排除val的情况
            printf("最小数字是%d\n", val2);
        }
    }
    else {
        //排除val的情况
        if (val1 < val2) {
            //排除val2的情况
            printf("最小数字是%d\n", val1);
        }
        else {
            //排除val1的情况
            printf("最小数字是%d\n", val2);
        }
    }
    return 0;
}






