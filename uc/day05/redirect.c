#include <p_file.h>
#include <string.h>

int main(int argc,char *argv[]){
    char *msg="this is a test\n";
    //文件不存在,创建文件,指定文件的权限为0644
    //文件存在，将文件的内容清空
    int flags=O_WRONLY|O_CREAT|O_TRUNC;
    int fd=open(argv[1],flags,0644);
    if(fd==-1)E_MSG("open",-1);
    //将标准输出保存
    int s_fd=dup(1);
    dup2(fd,1);
    close(fd);
    write(1,msg,strlen(msg));//写到了打开的文件里
    dup2(s_fd,1);
    write(1,msg,strlen(msg));//写到了标准输出
    close(s_fd);

    return 0;
}
