#include "p_net.h"

int s_bind(int domain, int type,in_port_t port){
    SA4 serv;
    int fd=socket(domain,type,0);
    if(fd==-1)E_MSG("socket",-1);

    serv.sin_family=AF_INET;
    serv.sin_port=htons(port);
    serv.sin_addr.s_addr=htonl(INADDR_ANY);
    int b=bind(fd,(SA *)&serv,sizeof(serv));
    if(b==-1)E_MSG("bind",-1);
    return fd;
}
/*无来电显示*/
int n_accept(int fd){
    int cfd=accept(fd,NULL,NULL);
    if(cfd==-1)E_MSG("accept",-1);
    return cfd;
}

int h_accept(int fd){
    char IP[32];
    SA4 cli;
    socklen_t len;
    len=sizeof(cli);
    int cfd=accept(fd,(SA *)&cli,&len);
    if(cfd==-1)E_MSG("accept",-1);
    inet_ntop(AF_INET,&cli.sin_addr,IP,32);
    printf("%s\n",IP);

    return cfd;

}
