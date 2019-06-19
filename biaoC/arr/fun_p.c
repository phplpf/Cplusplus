//一个函数在编译的时候被分一个
//入口地址,这个地址就被称为函数指针
//所以我们可以用一个指针指向一个函数
//然后通过这个指针就可以调用这个函数
#include <stdio.h>
int min(int a,int b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}
int main(){
    int a,b,m;
    int (*p_min)();//函数指针
    p_min = min;
    printf("please input two integer numbers:\n");
    scanf("%d%d",&a,&b);
    m = (*p_min)(a,b);
    printf("%d\n",m);
}
















