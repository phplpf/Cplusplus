/*
 * 多重循环练习
 * */
#include <stdio.h>
int main() {
    int num = 0, num1 = 0;
    for (num = 0;num <= 2;num++) {   //循环变量代表5块钱所有可能的数量
        for (num1 = 0;num1 <= 5;num1++) {   //循环变量代表2块钱所有可能的数量
            if (5 * num + 2 * num1 <= 10) {   //5块钱和2块钱的总面值不超过10块钱就表示是一种组合
                printf("5块钱有%d张，2块钱有%d张，1块钱有%d张\n", num, num1, 10 - 5 * num - 2 * num1/*10块钱减去5块和2块的总面值就是1块钱的数量*/);
            }
        }
    }
    return 0;
}








