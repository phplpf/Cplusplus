#include <p_stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(void){
    char buf[128];
    int fd[2];
    char *msg="this is a test...\n";
    //创建一个管道
    int pp=pipe(fd);
    if(pp==-1)E_MSG("PIPE",-1);
    //创建一个子进程，子进程继承父进程的文件描述符
    pid_t pid=fork();
    if(pid==-1)E_MSG("fork",-1);
    if(pid==0){// 子进程负责的任务
        close(fd[1]);//关闭写端
        int r=read(fd[0],buf,128);//从管道读取数据到buf中
        //将读取到的数据输出到显示器
        write(1,buf,r);
        //关闭读端
        close(fd[0]);
        exit(0);

    }else{//父进程负责的任务
        close(fd[0]);
        write(fd[1],msg,strlen(msg)+1);
        close(fd[1]);
        wait(NULL);
    }
    return 0;
}
//注意：管道里没有数据，从管道读取数据，这时候，阻塞等待
//管道满的时候，write(2)会阻塞
