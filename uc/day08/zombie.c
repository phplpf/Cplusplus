#include <p_stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    int s;
    //创建子进程
    pid_t pid;
    pid=fork();
    if(pid==-1)E_MSG("fork",-1);
    if(pid==0){//子进程执行的代码
        printf("child process...%d\n",getpid());
        //sleep(13);
        exit(-1);
    }else{//父进程执行的代码
        sleep(10);
        wait(&s);//阻塞等待子进程的终止
        printf("parent process...\n");
        if(WIFEXITED(s))//子进程正常终止
            printf("exit code...%d\n",\
                    WEXITSTATUS(s));
        if(WIFSIGNALED(s))//子进程被信号打断
            printf("signum:%d\n",WTERMSIG(s));
    }
    return 0;
}
