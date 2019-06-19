#include <stdio.h>
#include "08read.h"
/*static*/ int val;
void read(void) {
    printf("请输入数字：");
    scanf("%d", &val);
}
