#include <iostream>
using namespace std;

template<class T>class Base{
public:
    virtual void foo(){
        cout << "Base<T>::foo()" << endl;
    }
};
template<class T,class D>
class Derived : public Base<T>{
public:
/*  virtual void foo(){
        cout<<"Derived<T,D>::foo()"<<endl;
    }*/
    virtual template<class M>void bar(){
    
    }
};
int main(){
    Derived<int,int> d;
    Base<int> *pob = &d;
    pob->foo();
    d.bar<int>();
    return 0;
}



