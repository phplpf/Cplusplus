#include <iostream>
using namespace std;
void swap1(int* x,int* y){
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}
void swap2(int& x,int& y){
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}
int main(void){
    int a = 3,b = 5;
    //swap1(&a,&b);
    swap2(a,b);
    cout << "a=" << a << ",b=" << b 
        << endl;
    return 0;
}
