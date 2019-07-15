#include <p_net.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct{
    char method[32];
    char path[128];
    char proto[32];

}req_t;
char *work_dir="/home/csd1905/uc/web/www";
static void trans_path(char *file){
    char path[128];
    strcpy(path,work_dir);
    strcat(path,file);
    strcpy(file,path);
    return; 
}
//接收客户端的请求信息
static void get_requests(int fd,req_t *req){
    char buf[1024];
    int r=read(fd,buf,1024);
    sscanf(buf,"%s %s %s\r\n",req->method,req->path,req->proto);
    if(strcmp(req->path,"/")==0)strcpy(req->path,"/index.html");
    trans_path(req->path);
    return;
}
int t_main(int cfd)
{
    req_t rq;
    //接收客户端的请求信息
    get_requests(cfd,&rq);
    printf("path:%s\n",rq.path);
    //处理客户端的请求信息，获取到处理结果
    // 根据处理姐夫哦回应客户端
    return 0;
}


