#include <p_net.h>
#include <ctype.h>

int main(void){
    char buf[128];
    SA4 cli;
    socklen_t len;
    int fd=s_bind(AF_INET,SOCK_DGRAM,7788);
    if(fd==-1)return -1;
    while(1){
        len=sizeof(SA4);
        //接收客户端的消息.源地址需要保存吗？为什么？
        //将客户端的ip地址和端口号保存到cli的内存中
        int rcv=recvfrom(fd,buf,128,0,(SA *)&cli,&len);
        if(rcv==-1)E_MSG("recvfrom",-1);
        //处理客户端的响应信息
        for(int i=0;i<rcv;i++)
            buf[i]=toupper(buf[i]);
        //将处理结果发送给客户端
        sendto(fd,buf,rcv,0,(SA *)&cli,sizeof(cli));
    }
    return 0;
}
