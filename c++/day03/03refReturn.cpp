#include <iostream>
using namespace std;
struct A{
    int data;
    int& func(void){
        return data;//安全
    }
    int& foo(void){
        int num = 100;
        return num;//危险!
    }
};
int main(void){
    A a = {100};
    cout << a.data << endl;//100
    //a.data = 200
    a.func() = 200;//ok
    cout << a.data << endl;//200
    //a.foo() = 300;
    return 0;
}



