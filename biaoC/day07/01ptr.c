/*
 * 指针练习
 * */
#include <stdio.h>
int main() {
    int val = 0, val1 = 0, val2 = 0;
    int *p_val = &val, *p_val1 = &val1, *p_val2 = &val2;
    int *p_min = NULL;    //指针p_min指向最小数字所在的存储区
    printf("请输入三个数字：");
    scanf("%d%d%d", &val, &val1, &val2);
    p_min = &val;    //假设val变量里的数字最小
    if (*p_min > val1) {
        //假设失败的情况
        p_min = &val1;   //假设val1变量里的数字最小
    }
    if (*p_min > val2) {
        //假设失败的情况
        p_min = &val2;   //假设val2变量里的数字最小
    }
    printf("最小数字是%d\n", *p_min);
    /*if (*p_val > *p_val1) {
        if (*p_val1 > *p_val2) {
            printf("最小数字是%d\n", *p_val2);
        }
        else {
            printf("最小数字是%d\n", *p_val1);
        }
    }
    else {
        if (*p_val > *p_val2) {
            printf("最小数字是%d\n", *p_val2);
        }
        else {
            printf("最小数字是%d\n", *p_val);
        }
    }*/
    return 0;
}





