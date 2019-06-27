#include <p_stdio.h>

int main(int argc,char *argv[]){
    FILE *fp=fopen(argv[1],"r");
    if(fp==NULL)E_MSG("fopen",-1);
    //关闭文件
    fclose(fp);
    return 0; 
}
