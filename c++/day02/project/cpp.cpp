#include <iostream>
using namespace std;

extern "C" void hello(void){
    cout << "hello C++!" << endl;
}
