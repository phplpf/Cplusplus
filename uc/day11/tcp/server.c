#include <ctype.h>
#include "p_net.h"

int main(void){
    char buf[128];
    //创建socket设备，返回该设备的文件描述符
    int sfd=s_bind(AF_INET,SOCK_STREAM,5577);
    if(sfd==-1)return -1;
    //将sfd指定的设备设置为被动连接状态
    //将客户端连接的到来，放入到未决连接队列中
    listen(sfd,4);
    while(1){
        //从未决连接队列取出一个进行处理
        int cfd=h_accept(sfd);
        if(cfd==-1)return -1;
        //到这里三次握手成功了，使用cfd可以好客户端通讯了
        //从连接描述符读取客户端的请求信息
        //将读取到的信息存储到buf中
        int r=read(cfd,buf,128);
        //处理客户端的请求信息
        for(int i=0;i<r;i++)
            buf[i]=toupper(buf[i]);
        //将处理后的结果回送给客户端
        write(cfd,buf,r);
        close(cfd);
    }
    return 0;
}
