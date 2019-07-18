#include <iostream>
using namespace std;
int main(void){
    //int* pi = (int*)malloc(4);//C中
    int* pi = new int;//C++
    *pi = 100;
    cout << *pi << endl;
    //free(pi);//C中
    delete pi;//C++,防止内存泄露
    pi = NULL;//防止野指针

    //动态分配内存同时初始化
    int* pi2 = new int(200);
    (*pi2)++;
    cout << *pi2 << endl;//201
    delete pi2;
    pi2 = NULL;

    return 0;
}


