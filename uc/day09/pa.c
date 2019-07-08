#include <p_file.h>
#include <string.h>

int main(int argc,char *argv[]){
    char *msg="hello beijing\n";
    int fd=open(argv[1],O_WRONLY);
    if(fd==-1)E_MSG("open",-1);
    write(fd,msg,strlen(msg)+1);
    close(fd);
    return 0;
}
