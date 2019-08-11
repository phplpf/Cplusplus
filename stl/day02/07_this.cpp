#include <iostream>
using namespace std;
template<class T>class Base{
public:
    int m_i;
    void foo(){ cout<<"Base::foo()"<<endl; }
};
//int m_i;
//void foo(){}
template<class T,class D>
class Derived : public Base<T>{
public:
//  int m_i;
//  void foo(){}
    void bar(){
        this->m_i = 10;
        Base<T>::foo();
    }
};

int main(){
    Derived<int,double> d;
    d.bar();
    return 0;
}
