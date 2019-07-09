#include <p_net.h>
#include <string.h>

int main(int argc,char *argv[]){
    SA4 serv;
    char buf[128];
    char *msg="this is a test...\n";
    //创建socket，返回该设备的文件描述符
    int fd=socket(AF_INET,SOCK_DGRAM,0);
    if(fd==-1)E_MSG("socket",-1);
    serv.sin_family=AF_INET;
    serv.sin_port=htons(7788);
    //srgv[1]  text--->binary
    inet_pton(AF_INET,argv[1],&serv.sin_addr);
    //向服务器发送消息
    sendto(fd,msg,strlen(msg)+1,0,(SA *)&serv,sizeof(SA4));
    //阻塞等待服务器的响应消息
    int rcv=recvfrom(fd,buf,128,0,NULL,NULL);
    if(rcv==-1)E_MSG("RECVFROM",-1);
    write(1,buf,rcv);
    close(fd);
    return 0;
}
