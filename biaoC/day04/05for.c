/*
 * 循环演示
 * */
#include <stdio.h>
int main() {
    int num = 0, num1 = 0;
    /*for (num = 1;;num++) {   //省略小括号中间的逻辑表达式相当于逻辑表达式永远为真
        printf("%d\n", num);
    }*/
    /*for (num = 1, num1 = 9;num <= num1;num++, num1--) {  //小括号里最前面和最后面的部分可以是用逗号连接的多条语句
        printf("%d X %d = %d\n", num, num1, num * num1);
    }*/
    for (int num2 = 1;num2 <= 5;num2++) {   //C99规范里允许临时声明循环变量
        printf("%d ", num2);
    }
    printf("\n");
    //printf("%d\n", num2);    错误,num2只能在循环里使用
    return 0;
}




