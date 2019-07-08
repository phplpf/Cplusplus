#include <stdio.h>
#include <unistd.h>

int main(void){
    char buf[128];
    char comm[256];
    while(1){
        printf("%s$",getcwd(buf,128));
        gets(comm);
        printf("%s\n",comm);
        fork()
    }
    return 0;
}
