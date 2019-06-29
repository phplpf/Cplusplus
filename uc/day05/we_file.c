#include <p_file.h>

int main(int argc,char *argv[]){
    //打开文件，以写的方式打开
    //如果文件不存在，创建文件，mode指定为0644
    //如果文件存在，报错
    int flags=O_WRONLY|O_CREAT|O_EXCL;
    mode_t mode=0644;
    int fd=open(argv[1],flags,mode);
    if(fd==-1)E_MSG("open",-1);
    printf("file open success...\n");
    //关闭文件
    close(fd);
    return 0;
}
