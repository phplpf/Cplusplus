#include <stdio.h>
#include <dlfcn.h>

typedef int (*p_math)(int,int);

int main(int argc,char *argv[]){
    //加载动态库文件  文件名通过argv[1]传递
    void *handle=dlopen(argv[1],RTLD_NOW);
    if(handle==NULL){
        //printf("dlopen failed...\n");
        printf("%s\n",dlerror());
        return -1;
    }
    //加载成功
    printf("dlopen success...\n");
    p_math p=(p_math)dlsym(handle,"p_sub");
    if(p==NULL){
        printf("%s\n",dlerror());
        return -1;
    }
    //p里存放的是p_sub这个函数加载到内存的地址
    //p_math=p;
    printf("6-2=%d\n",p(6,2));
    //关闭动态库
    dlclose(handle);
    
    return 0;
}
