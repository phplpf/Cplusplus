/*
 * 数据对齐和补齐演示
 * */
#include <stdio.h>
typedef struct {
    char buf[2];
    int val;
} tmp_t;
typedef struct {
    char ch;
    int val;
    char ch1;
} tmp1_t;
int main() {
    printf("sizeof(tmp_t)是%d\n", sizeof(tmp_t));
    printf("sizeof(tmp1_t)是%d\n", sizeof(tmp1_t));
    return 0;
}






