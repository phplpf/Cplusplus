#include <string.h>
#include "p_net.h"

int main(int argc,char *argv[]){
    char buf[128];
    char *msg="this is a test...\n";
    SA4 serv;
    //创建socket设备，返回该设备的文件描述符
    int sfd=socket(AF_INET,SOCK_STREAM,0);
    if(sfd==-1)E_MSG("socket",-1);
    //初始化服务器的相关信息
    serv.sin_family=AF_INET;
    serv.sin_port=htons(5577);
    //127.0.0.1 --->binary
    inet_pton(AF_INET,argv[1],&serv.sin_addr);

    //在sfd指定的设备上向服务器发送连接请求
    int c=connect(sfd,(SA *)&serv,sizeof(serv));
    if(c==-1)E_MSG("connect",-1);
    //到这里三次握手成功了
    //向服务器发送请求消息
    write(sfd,msg,strlen(msg)+1);
    //阻塞等待服务器端的响应消息
    int r=read(sfd,buf,128);
    //接收到服务器的响应消息，处理消息
    write(1,buf,r);
    close(sfd);
    return 0;
}
