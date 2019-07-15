#include <p_net.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
extern int t_main(int);
void handle(int n){
    wait(NULL);
    return;
}
int main(void)
{
    signal(SIGCHLD,handle);
    char buf[128];
    //socket  bind  listen
    int sfd=s_listen(AF_INET,SOCK_STREAM,5577,4);
    if(sfd==-1)return -1;
    while(1){
    
        //从未决链接队列里取出一个进行处理
        int cfd=h_accept(sfd);
        if(cfd==-1) return -1;
        pid_t pid=fork();
        if(pid==-1)E_MSG("fork",-1);
        if(pid==0){
          close(sfd);
          t_main(cfd);
          close(cfd);
          exit(0);
        }else{
            close(cfd);
            //waitpid(-1,NULL,WNOHANG);
        }
    }

    return 0;
}
