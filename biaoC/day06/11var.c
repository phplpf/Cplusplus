/*
 * 变量分类演示
 * */
#include <stdio.h>
void func(void) {
    static int val = 100;
    printf("val是%d\n", val);
    val = 10;
}
void func1(void) {
    int val = 1000;
    func();
}
int main() {
    func();
    func1();
    return 0;
}





