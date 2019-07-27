#include <iostream>
using namespace std;
class A{};
class B:public A{};
class Base{
public:
    virtual void func(void){
        cout << "Base::func" << endl;
    }
    virtual A& foo(void){
        cout << "Base::foo" << endl;
    }
};
class Derived:public Base{
public:
    void func(void){
        cout << "Derived::func" << endl;
    }
    B& foo(void){
        cout << "Derived::foo" << endl;
    }
};
int main(void){
    Derived d;
    Base* pb = &d;
    pb->func();
    pb->foo();
    return 0;
}




