#include <iostream>
using namespace std;
int main(void){
    int a = 3;
    int b = 5;

    cout << a++ << endl;//3
    cout << a << endl;//4
    
    a++ = 10;//error
    a++++;//error
    
    return 0;
}
