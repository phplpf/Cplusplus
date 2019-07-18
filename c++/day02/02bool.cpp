#include <iostream>
using namespace std;

int main(void){
    bool b = false;
    cout << "b=" << b << endl;
    cout << "size=" << sizeof(b) << endl;
    
    b = 300 + 500;
    cout << "b=" << b << endl;//1
    b = 1.23 + 4.56;
    cout << "b=" << b << endl;//1
    int* p = NULL;//NULL->(void*)0
    b = p;
    cout << "b=" << b << endl;//0

    return 0;
}



