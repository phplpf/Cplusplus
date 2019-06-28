#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int g_val;

static void count(void){
    static int val=1;
    printf("val++=%d\n",val++);
    printf("&val=%p\n",&val);
    return;
}

int main(void){
    int i;
    printf("pid:%d\n",getpid());
    for(i=0;i<5;i++)
        count();
    printf("&g_val=%p\n",&g_val);
    getchar();
    return 0;
}
