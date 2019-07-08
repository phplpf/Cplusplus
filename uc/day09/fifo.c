#include <p_stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc,char *argv[]){
    //argv[1]传递新建文件的名字
    int ff=mkfifo(argv[1],0644);
    if(ff==-1)E_MSG("mkfifo",-1);

    return 0;
}
