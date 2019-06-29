#include <p_file.h>

int main(int argc,char *argv[]){
    //打开文件，以只读方式
    int fd=open(argv[1],O_RDONLY);
    if(fd==-1)E_MSG("open",-1);
    printf("open file success...\n");
    //关闭文件
    close(fd);
    return 0;
}
