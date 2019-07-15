#include <p_stdio.h>
#include <sys/socket.h>
#include <sys/socket.h>
#include <ctype.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
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
    char IP[32];
    char buf[128];
    struct sockaddr_in  serv,cli;
    socklen_t  cli_len;
    int fd=socket(AF_INET,SOCK_STREAM,0);
    if(fd==-1)E_MSG("socket",-1);
     serv.sin_family=AF_INET;
     serv.sin_port =htons(8090);
     serv.sin_addr.s_addr=htonl(INADDR_ANY);
    int b=bind(fd,(struct sockaddr *)&serv,sizeof(serv));
    if(b==-1)E_MSG("bind",-1);
    listen(fd,4);
    while(1){
        int cfd=accept(fd,(struct sockaddr *)&cli,&cli_len);
      //  if(cfd==-1)E_MSG("accept",-1);
        //到此三次握手就完成了
        pid_t pid=fork();
        if(pid==-1)E_MSG("fork",-1);
        if(pid==0){
            close(fd);
            t_main(cfd);
            close(cfd);
            exit(0);
        }else{
            close(cfd);
        }
    }


    return 0;
}

