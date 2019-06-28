#include <sys/types.h>
#include <unistd.h>
#include <p_stdio.h>

int main(void){
    printf("pid:%d\n",getpid());
    getchar();    
    return 0;
}
