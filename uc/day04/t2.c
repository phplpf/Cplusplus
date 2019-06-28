#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void fun( int *n){
    while((*n)--); printf("%d \n",++(*n)); 
}



void f(char* s1,char* s2){ 
    while(*s1++); s1--;
    while(*s1++ = *s2++); 

}
int main(){ 
    // int a = 10; fun(&a);
//    char  arr[10]="fdsdf";
  //  char arr2[10]="abcd";
    // f(arr,arr2);
    // printf("%s \n",arr);
    //
    char *st="1234.56";
    int i = atoi(st); 
    printf("%d\n",i); 
    return 0;
} 
