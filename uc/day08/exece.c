#include <p_stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void){
    char *ps_envp[]={"caption=nanjing",\
        "name=tarena",NULL};
    //创建子进程
    pid_t pid=fork();
    if(pid==-1)E_MSG("fork",-1);
    if(pid==0){
        execle("./p_env","p_env",NULL,ps_envp);
    }else{
        wait(NULL);
    }
    return 0;
}
