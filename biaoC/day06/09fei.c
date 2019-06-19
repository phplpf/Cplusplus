/*
 *  费氏数列练习
 * */
#include <stdio.h>
int fei(int sn) {
    if (sn <= 1) {
        //计算编号为0和1的数字
        return 1;
    }
    return fei(sn - 2)/*编号为sn - 2的数字*/ + fei(sn - 1)/*编号为sn - 1的数字*/;
}
int main() {
    int sn = 0;
    printf("请输入编号：");
    scanf("%d", &sn);
    printf("结果是%d\n", fei(sn));
    return 0;
}




