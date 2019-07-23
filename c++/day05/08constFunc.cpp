#include <iostream>
using namespace std;
class A{
public:
    void func(void)const{
        cout << "func常版本" << endl;
    }
    void func(void){
        cout << "func非常版本" << endl;
    }
};
int main(void){
    A a1;
    a1.func();//非常版本
    const A a2 = a1;
    a2.func();//常版本
    return 0;
}



