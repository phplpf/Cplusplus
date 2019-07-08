#include <p_stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
    //创建子进程
    pid_t pid=fork();
    if(pid==-1)E_MSG("fork",-1);
    if(pid==0){
        sleep(13);
        exit(0);
    }else{
        sleep(5);        
    }

    return 0;
}
