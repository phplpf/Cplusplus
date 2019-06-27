#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc,char *argv[]){
    FILE *fp=fopen(argv[1],"r");
    if(fp==NULL){
        //errno=13;
#if 0
        //errno=-1;
        printf("fopen file error...%d\n",errno);
        printf("...%s\n",strerror(errno));
#endif
        perror("fopen");
        return -1;
    }
    //关闭文件
    fclose(fp);
    return 0; 
}
