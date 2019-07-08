#include <p_stdio.h>
#include <signal.h>

int main(void){
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set,2);
    sigaddset(&set,3);
    int is=sigismember(&set,3);
    is?printf("is"):printf("not is");
    printf("\n");
    sigdelset(&set,3);
    is=sigismember(&set,3);
    is?printf("is"):printf("not is");
    printf("\n");
    return 0;
}
