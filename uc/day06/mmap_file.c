#include <p_file.h>
#include <sys/mman.h>

int main(int argc,char *argv[]){
    int prot=PROT_READ|PROT_WRITE;
    int flags=MAP_SHARED;
    //打开文件,以读写的方式
    int fd=open(argv[1],O_RDWR);
    if(fd==-1)E_MSG("open",-1);
    //将文件映射到进程的虚拟地址空间，对内存中数据的修改直接同步到底层的文件中
    int *p=(int *)mmap(NULL,6,prot,flags,fd,0);
    if(p==MAP_FAILED)E_MSG("mmap",-1);
    //到这里就映射成功了，p指向了映射区域的起始地址
    close(fd);//关闭文件描述符，不接触文件的映射
    //对p指向的虚拟地址空间里的数据进行修改，同步到底层文件
    *p=0x31323334;
    //解除映射
    munmap(p,6);
    return 0;
}
