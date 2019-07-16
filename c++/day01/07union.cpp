#include <iostream>
#include <cstdio>
using namespace std;
int main(void){
    union{//匿名联合
        unsigned int ui;
        unsigned char uc[4];
    };
    ui = 0x12345678;
    for(int i=0;i<4;i++){
        printf("%#x ",uc[i]);
    }
    printf("\n");
    return 0;
}

