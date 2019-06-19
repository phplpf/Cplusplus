/*
 * 位置指针演示
 * */
#include <stdio.h>
int main() {
    char ch = 0;
    FILE *p_file = fopen("abc.txt", "rb");
    if (p_file) {
        //rewind(p_file);
        fseek(p_file, 2, SEEK_SET);   //把位置指针设置到文件头向后2个字节的位置
        printf("位置指针是%ld\n", ftell(p_file));
        fread(&ch, sizeof(char), 1, p_file);
        printf("%c\n", ch);
        //rewind(p_file);
        fseek(p_file, 4, SEEK_CUR);   //把位置指针移动到当前位置后面4个字节的位置
        printf("位置指针是%ld\n", ftell(p_file));
        fread(&ch, sizeof(char), 1, p_file);
        printf("%c\n", ch);
        //rewind(p_file);
        fseek(p_file, -4, SEEK_END);   //把位置指针移动到文件尾向前4个字节的位置
        printf("位置指针是%ld\n", ftell(p_file));
        fread(&ch, sizeof(char), 1, p_file);
        printf("%c\n", ch);
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}




