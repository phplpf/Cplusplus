#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(void){
    printf("pid:%d\n",getpid());
    char *p=(char *)malloc(1024);
    printf("p content...%p\n",p);
    printf("p address...%p\n",&p);
    strcpy(p,"hello beijing");
    printf("%s\n",p);
    free(p);
    p=NULL;
    //printf("free:%s\n",p);
    getchar();
    return 0;
}
