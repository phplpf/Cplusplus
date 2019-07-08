#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    kill(atoi(argv[2]), atoi(argv[1]));
    return 0;
}
