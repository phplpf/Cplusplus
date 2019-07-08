#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle(int n){}

unsigned int p_sleep(unsigned int seconds){
    alarm(seconds);
    pause();
    return alarm(0);
}
int main(void){
    signal(SIGALRM,handle);
    while(1){
        p_sleep(2);
        printf("终于要下班了...\n");
    }
    return 0;
}
