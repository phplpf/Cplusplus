#include <stdio.h>
#include <string.h>
char *p_strcpy(char *dest,const char *src){
    char *p_str = dest;
    while(*src!='\0'){        
           *p_str++ = *src++; 
    }
        *p_str = *src;
    return dest;
}

int main(void){

    char buf[32]="hello beijng";
    char name[32];
    char name1[32];
    p_strcpy(name1,p_strcpy(name,buf));
    printf("%s \n",name1);

    return 0;
}
