#include <p_stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void){
    //创建子进程
    pid_t pid;
    pid=fork();
    if(pid==-1)E_MSG("fork",-1);
    if(pid==0){
        printf("child process...%d\n",getpid());
    }else{
        printf("parent process...%d\n",getpid());
    }
    return 0;
}
