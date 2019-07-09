#include <p_net.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

//信号处理函数
void handle(int n){
    wait(NULL);
    return;
}
extern int t_main(int);
int main(void){
    signal(SIGCHLD,handle);
    //socket(2)   bind(2)  listen(2)
    int sfd=s_listen(AF_INET,SOCK_STREAM,5577,4);
    if(sfd==-1)return -1;
    
    while(1){
        //从未决连接队列取出一个进行处理
        int cfd=h_accept(sfd);
        if(cfd==-1)return -1;
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
