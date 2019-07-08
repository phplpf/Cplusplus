#include <p_stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    char *ps_argv[]={"ps","-o",\
        "pid,ppid,pgrp,comm",NULL};
    //创建子进程
    pid_t pid=fork();
    if(pid==-1)E_MSG("fork",-1);
    if(pid==0){//子进程执行的代码
        //更新进程的映像
        //execv("/bin/ps",ps_argv);
        execlp("ps","ps","-o","pid,ppid,pgrp,comm",NULL);
        perror("execvp");//什么时候会执行到
        exit(0);
    }else{//父进程执行的代码
        wait(NULL);
    }
    return 0;
}
