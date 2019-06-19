/*
 * continue;语句演示
 * */
#include <stdio.h>
int main() {
    int num = 0;
    for (num = 1;num <= 5;num++) {
        printf("%d\n", num);
        if (num == 3) {
            continue;
        }
        printf("%d\n", 10 + num);
    }
    return 0;
}






