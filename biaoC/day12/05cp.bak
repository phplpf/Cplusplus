/*
 * 文件拷贝练习
 * */
#include <stdio.h>
int main(int argc, char **argv) {
    char buf[100] = {0};
    int size = 0;
    FILE *p_src = NULL, *p_dest = NULL;
    if (argc < 3) {
        //用户输入的命令不包含必要的信息
        printf("命令错误\n");
        return 0;
    }
    p_src = fopen(*(argv + 1)/*原始文件的路径*/, "rb");
    if (!p_src) {
        printf("原始文件打开失败\n");
        return 0;
    }
    p_dest = fopen(*(argv + 2)/*目标文件的路径*/, "wb");
    if (!p_dest) {
        printf("目标文件打开失败\n");
        //关闭原始文件
        fclose(p_src);
        p_src = NULL;
        return 0;
    }
    while (1) {
        size = fread(buf, sizeof(char), 100, p_src);   //从原始文件里获得100个字节的内容并记录到buf数组里
        if (!size) {
            //没有从原始文件里获得数字
            break;
        }
        fwrite(buf, sizeof(char), size, p_dest);    //把从原始文件里获得的数据都记录到目标文件里
    }
    fclose(p_dest);
    p_dest = NULL;
    fclose(p_src);
    p_src = NULL;
    return 0;
}





