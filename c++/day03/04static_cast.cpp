#include <iostream>
using namespace std;
int main(void){
    int* pi = NULL;
    //char c = (int)pi;//C风格
    char c = int(pi);//C++风格

    void* pv = pi;
    pi = static_cast<int*>(pv);//合理
    //c = static_cast<int>(pi);//不合理

    return 0;
}
