#include <p_file.h>

int main(int argc,char *argv[]){
    char buf[128];
    //打开文件,argv[1]   只读
    int fd=open(argv[1],O_RDONLY);
    if(fd==-1)E_MSG("open",-1);
#if 0
    while(1){
        //对文件操作
        //从指定文件中读取数据
        int r=read(fd,buf,128);
        if(r>0)
            write(1,buf,r);
        else
            break;
    
    }
#endif
    int r;
    while((r=read(fd,buf,128))>0)
        write(1,buf,r);
    //关闭文件
    close(fd);

    return 0;
}
