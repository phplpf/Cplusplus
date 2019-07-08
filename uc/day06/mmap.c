#include <p_stdio.h>
#include <string.h>
#include <sys/mman.h>

int main(void){
    int prot=PROT_READ|PROT_WRITE;
    int flags=MAP_PRIVATE|MAP_ANONYMOUS;

    //将物理地址映射到进程的虚拟地址空间
    void *p=mmap(NULL,1024,prot,flags,-1,0);
    if(p==MAP_FAILED)E_MSG("mmap",-1);
    //到这里就映射成功了，p指向了映射区域的起始地址
    strcpy(p,"this is a test...");
    printf("%s\n",(char *)p);
    //解除映射
    munmap(p,1024);
    return 0;
}
