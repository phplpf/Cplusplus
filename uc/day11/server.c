#include <p_file.h>
#include <sys/socket.h>
#include <ctype.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void){
    char buf[128];
    char IP[32];
    struct sockaddr_in serv,cli;//ipv4地址家族
    socklen_t cli_len;
    //创建socket设备，返回该设备的文件描述符
    int sfd=socket(AF_INET,SOCK_STREAM,0);
    if(sfd==-1)E_MSG("socket",-1);

    //初始化serv的成员
    serv.sin_family=AF_INET;
    serv.sin_port=htons(5577);
    serv.sin_addr.s_addr=htonl(INADDR_ANY);

    //将sfd和本地的ip地址  端口号绑定
    int b=bind(sfd,(struct sockaddr *)&serv,sizeof(serv));
    if(b==-1)E_MSG("bind",-1);
    //将sfd指定的设备设置为被动连接状态
    //将客户端连接的到来，放入到未决连接队列中
    listen(sfd,4);
    while(1){
        cli_len=sizeof(cli);
        //从未决连接队列取出一个进行处理
        int cfd=accept(sfd,(struct sockaddr *)&cli,&cli_len);
        if(cfd==-1)E_MSG("accept",-1);
        //binary--->text
        inet_ntop(AF_INET,&cli.sin_addr,IP,32);
        printf("%s\n",IP);
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
