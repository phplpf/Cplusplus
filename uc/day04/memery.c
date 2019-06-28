#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main(void)
{
    char *str1 = "hello beijing";
    char *str2 = "hello beijing";
    //char buf[32]="hello beijing";
    char buf[32];
//    buf = "hello beijing";
    strcpy(buf," hello beijing");
#if 0
    char *p;//悬空指针
    *p='c';
#endif
    printf("pid:%d \n",getpid());
    printf("str1 content ...%p\n",str1);
    printf("str2 content ...%p\n",str2);
    printf("str1 address ...%p\n",&str1);
    printf("str2 address ...%p\n",&str2);
    printf("buf ...%p\n",buf);
    printf("buf ...%s\n",buf);
    getchar();
    return 0;
}
