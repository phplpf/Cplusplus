#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <p_stdio.h>
#include <time.h>
static char *crlf="\r\n";
typedef struct{
	char method[20];
	char path[128];
	char potol[30];

}req_t;
char *work_dir="/home/lpf/code/Cplusplus/uc/web/html";
void trans_path(char *file){
	  char path[128];
	  strcpy(path,work_dir);
	  strcat(path,file);
	  strcpy(file,path);
	  return;
}
void get_request(int fd,req_t *rq){
	
	char buf[1024];
	int r = read(fd,buf,1024);
	sscanf(buf,"%s %s %s\r\n",rq->method,rq->path,rq->potol);
	if(strcmp(rq->path,"/")==0)strcpy(rq->path,"/index.html");
	trans_path(rq->path);
	return;
}
char *header(req_t *req,int len,int code,const char *file_type ){
	static char head_global[512];
	char desc[32];
	char mime[32],length[32],date[128],server[32],encoding[32];
	strcpy(head_global,req->potol);
	switch(code){
		case 200:
		sprintf(desc," %d %s %s",code,"OK",crlf);
		break;
		case 404:
		sprintf(desc," %d %s %s",code,"NOT FOUND",crlf);
		break;
		case 403:
		sprintf(desc," %d %s %s",code,"FORBIDDEN",crlf);
	}
	strcat(head_global,desc);
	time_t t;
	char *ct = ctime(&t);
	sprintf(mime,"%s%s%s","Content-Type:",file_type,crlf);
	sprintf(length,"%s%d%s","Content-Length:",len,crlf);
	sprintf(date,"%s%s%s","Date:",ct,crlf);
	sprintf(server,"%s%s%s","Server:","weblpf",crlf);
	strcat(head_global,mime);
	strcat(head_global,length);
	strcat(head_global,server);
	strcat(head_global,encoding);
	strcat(head_global,date);
	return head_global;
}
char *is_mime(char *path){
	int i=0;
	char *types=NULL;
	char *files=NULL;
	for(i=strlen(path);i>0;i--){
		if(path[i]=='/'){
			files=&path[i+1];
			break;
		}
	}
	for(i=strlen(files);i>0;i--){
		if(files[i]=='.'){
		   types=&files[i+1];
		   break;
		}
	}
	return types;
}
int content(req_t *req,char html[]){
	//	char *type = is_mime(req->path);
		int r = 0;
	//	if(strcmp(type,"html\0")==0){
	
			int fd = open(req->path,O_RDONLY);
			 r = read(fd,html,1024);
			close(fd);
	/*	}else{
			FILE * file = fopen(req->path,"rb");
			 r = fread(html,1024,1,file);
			fclose(file);
		}*/
		return r;
}
char *get_types(char path[]){
	char *type = is_mime(path);
	char *img_plain ="image/";
	char *text_plain="text/";
	printf("%d \n",strcmp(type,"html\0"));
	if(strcmp(type,"html\0")==0){
		strcat(text_plain,type);
		printf("%s \n",text_plain);
		return text_plain;
	}else{
		strcat(img_plain,type);
		printf("%s \n",img_plain);
		return img_plain;
	}
	char *mm="text/html";
	return mm;
}
void set_response(const req_t *req,int cfd){
	
	char html[1024];
	//char *types = get_types((char *)req->path);
	int r = content((req_t *)req,html);
	char *head = header((req_t *)req,r,200,"text/html");
	write(cfd,head,strlen(head));
	write(cfd,html,strlen(html));
	
	return;
}

int t_main(int cfd)
{
    
    //处理请求来的信息
    req_t rq;
    get_request(cfd,&rq);
    //printf("%s \n",rq.path);  
    //处理客户端的请求，获取到处理结果
    set_response(&rq,cfd);
    //根据处理结果回应客户端 
    return 0;
      
 }

