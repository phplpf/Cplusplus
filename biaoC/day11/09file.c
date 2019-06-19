/*
 * 文件操作代码框架演示
 * */
#include <stdio.h>
int main() {
    FILE *p_file = fopen("a.bin", "w");
    /*if (p_file) {
        //处理打开文件成功的情况
        fclose(p_file);
        p_file = NULL;
    }*/
    if (!p_file) {
        //处理文件打开失败的情况
        return 0;
    }
    //操作文件
    fclose(p_file);
    p_file = NULL;
    return 0;
}





