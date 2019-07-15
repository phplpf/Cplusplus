#include <p_net.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "web.h"
char *work_dir="/home/tarena/csd1905/uc/web/html";
static void trans_path(char *file){
    char path[128];
    strcpy(path,work_dir);
    strcat(path,file);
    strcpy(file,path);
    return; 
}

static char *get_ftyp(const char *file){
   char *h = strrchr(file,'.');
   if(h==NULL)return "text/html";
   if(strcmp(h,".jpg")==0) return "image/jpg";
   if(strcmp(h,".png")==0) return "image/png";
   return "text/html";
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
static void do_request(const req_t *req,res_t *res){
    //获取响应码
    res->code=(!access(req->path,R_OK))?200:404;
    //获取文件的类型
    res->f_typ=get_ftyp(req->path);

    return;
}
static void response_b(int fd,res_t *res,req_t *req){
    char f_line[128],content[128];
    sprintf(f_line,"%s%d\r\n",req->proto,res->code);
    sprintf(content,"Content-Type:%s\r\n\r\n",res->f_typ);
    write(fd,f_line,strlen(f_line));
    write(fd,content,strlen(content));
    if(res->code==404){
        char *html="<html><body><h2>file not found</h2></body></html>";
        write(fd,html,strlen(html));
    }else{
        dup2(fd,1);
        execlp("cat","cat",req->path,NULL);
    }
    return;
}
int t_main(int cfd)
{
    req_t rq;
    res_t *res;
    //接收客户端的请求信息
    get_requests(cfd,&rq);
    //处理客户端的请求信息，获取到处理结果
    do_request(&rq,res); 
    printf("%s \n",rq.path);
    printf("code: %d\t content-type:%s\n",res->code,res->f_typ);
    // 根据处理结果回应客户端
    response_b(cfd,res,&rq);
    return 0;
}


