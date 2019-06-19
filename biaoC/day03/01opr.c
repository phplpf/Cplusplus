/*
 * 操作符演示
 * */
#include <stdio.h>
int main() {
    int val = 10, val1 = 0;
    val += 5;     //把加法计算的结果记录到val变量存储区里
    printf("val是%d\n", val);
    val *= 2 + 3;
    printf("val是%d\n", val);
    val = 10;
    val++;    //采用后操作方式使用自增操作符
    printf("val是%d\n", val);
    ++val;    //采用前操作方式使用自增操作符
    printf("val是%d\n", val);
    val = 10;
    val1 = val++;    //val++可以作为数字使用，这个数字是修改前的10
    printf("val是%d,val1是%d\n", val, val1);
    val1 = ++val;    //++val可以作为数字使用，这个数字是修改后的12
    printf("val是%d,val1是%d\n", val, val1);
    return 0;
}







