#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <p_stdio.h>
#include <time.h>
typedef struct{
	char method[20];
	char path[128];
	char potol[30];

}req_t;
typedef struct{
    int code;//状态码
    char *f_type;//文件类型 text/html image/jpg image/png

}rst_t;
char *work_dir="/home/tarena/csd1905/uc/web/html";
void trans_path(char *file){
	  char path[128];
	  strcpy(path,work_dir);
	  strcat(path,file);
	  strcpy(file,path);
	  return;
}
static void get_request(int fd,req_t *rq){
	
	char buf[1024];
	int r = read(fd,buf,1024);
	sscanf(buf,"%s %s %s\r\n",rq->method,rq->path,rq->potol);
        if(strcmp(rq->path,"/")==0)strcpy(rq->path,"/index.html");
        trans_path(rq->path);
	return;
}

static char *get_types(char *path){
        char *type = strrchr(path,'.');
        if(type==NULL)return "text/html";
        if(strcmp(type,".jpg")==0) return "image/jpg";
        if(strcmp(type,".png")==0) return "image/png";
        return "text/html";
}

static void do_request(req_t *req,rst_t *res){
    res->code=!access(req->path,R_OK)?200:404;
    res->f_type=get_types(req->path);
}
static void header(const req_t *req,const rst_t *res,int cfd){
    
        char f_line[32],mime[32],date[80],server[20];
	time_t t;
	char *ct = ctime(&t);
	sprintf(f_line," %s %d %s\r\n",req->potol,res->code,"OK");
	sprintf(mime,"%s%s\r\n","Content-Type:",res->f_type);
	sprintf(date,"%s%s\r\n\r\n","Date:",ct);
	sprintf(server,"%s%s\r\n","Server:","weblpf");
        write(cfd,f_line,strlen(f_line));
        write(cfd,mime,strlen(mime));
	write(cfd,server,strlen(server));
	write(cfd,date,strlen(date));
	return;
}

static void set_response(req_t *req,rst_t *res,int cfd){
	 char f_line[128],content[128];
          sprintf(f_line,"%s%d\r\n",req->potol,res->code);
          sprintf(content,"Content-Type:%s\r\n\r\n",res->f_type);
          write(cfd,f_line,strlen(f_line));
          write(cfd,content,strlen(content));

        //header(req,res,cfd);
        if(res->code==404){
          char *html="<html><body><h2>file not found</h2></body></html>";
           write(cfd,html,strlen(html));

        }else{
            dup2(cfd,1);// 重定向文件描述符
            execlp("cat","cat",req->path,NULL);// 进程映像的更新
        }
	return;
}

int t_main(int cfd)
{
    
    //处理请求来的信息
    req_t rq;
    rst_t rs;
    get_request(cfd,&rq);
    //printf("%s \n",rq.path);  
    //处理客户端的请求，获取到处理结果
    do_request(&rq,&rs);
    //根据处理结果回应客户端 
    set_response(&rq,&rs,cfd);
    return 0;
      
 }

