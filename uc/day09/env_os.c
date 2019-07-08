#include <stdio.h>
#include <stdlib.h>
extern char **environ;
int main(void){
#if 0
    char *val=getenv("caption");
    if(val==NULL){
        printf("environ not found...\n");
        return -1;
    }
    printf("val=%s\n",val);
#endif
    setenv("caption","nanjing",0);
    char *val=getenv("caption");
    if(val!=NULL)
        printf("%s\n",val);
    clearenv();
    if(environ==NULL)
        printf("clear all...\n");
    return 0;
}
