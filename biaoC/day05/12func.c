/*
 * 函数练习
 * */
#include <stdio.h>
void print(int val, int val1) {
    printf("%d X %d = %d\n", val, val1, val * val1);
}
int main() {
    int num = 0;
    for (num = 1;num <= 5;num++) {
        print(num, 10 - num);
    }
    return 0;
}



