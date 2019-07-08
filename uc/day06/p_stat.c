#include <p_file.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
int main(int argc,char *argv[]){
    struct stat b;

    //获取文件的元数据，将元数据填充到b中
    int s=stat(argv[1],&b);
    if(s==-1)E_MSG("stat",-1);
    //已经将文件的元数据填充到了b中
    printf("inode:%lu\n",b.st_ino);
    printf("hrad link:%u\n",b.st_nlink);
    printf("size:%ld\n",b.st_size);
    printf("uid:%u\n",b.st_uid);
    struct passwd *pw=getpwuid(b.st_uid);
    printf("username:%s\n",pw->pw_name);
    printf("gid:%u\n",b.st_gid);
    struct group *gp=getgrgid(b.st_gid);
    printf("group name:%s\n",gp->gr_name);
    printf("mtime:%ld\n",b.st_mtim.tv_sec);
    printf("mtime:%ld\n",b.st_mtime);
    printf("mtime:%s",ctime(&b.st_mtime));
    printf("mode:%o\n",b.st_mode);
    return 0;
}
