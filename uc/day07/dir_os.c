#include <p_stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc,char *argv[]){
    //打开文件夹
    DIR *dir=opendir(argv[1]);
    if(dir==NULL)E_MSG("opendir",-1);
    //文件夹打开成功了
    printf("opendir success...\n");
    struct dirent *dirp;
    while((dirp=readdir(dir))!=NULL)
        printf("filename:%s\t inode:%lu\n",\
                dirp->d_name,dirp->d_ino);

    closedir(dir);
    return 0;
}
