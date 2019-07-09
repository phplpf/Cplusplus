#include <ctype.h>
#include <unistd.h>
#include <string.h>

int t_main(int cfd){
    char buf[128];    
    while(1){
        //什么情况下终止本次连接
        //客户端放过来"quit"字符串的时候
        //要终止本次连接
        int r=read(cfd,buf,128);
        //处理客户端的请求信息
        for(int i=0;i<r;i++)
            buf[i]=toupper(buf[i]);
        //将处理后的结果回送给客户端
        write(cfd,buf,r);
        if(strcmp(buf,"QUIT")==0)break;
    }
    return 0;
}
