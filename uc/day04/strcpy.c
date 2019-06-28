#include  <stdio.h>

char *p_strcpy(char *dest, const char *src){
    char *tmp=dest;
    while(*src!='\0'){
        *tmp++=*src++;
    }
    *tmp='\0';
    return dest;

}
int main(void){
    char buf[32]="hello beijing";
    char name[32];
    char name1[32];
    p_strcpy(name1,p_strcpy(name,buf));
    printf("%s\n",name);
    return 0;
}
