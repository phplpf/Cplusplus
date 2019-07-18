#include <iostream>
using namespace std;
int main(void){
    int* pi;
    //delete野指针结果未知,危险!
    //delete pi;

    int* pi2 = NULL;
    //delete空指针,安全
    delete pi2;

    int* pi3 = new int;
    //不能对同一个指针,连续delete,危险!
    delete pi3;
    //delete pi3;

    return 0;
}





