#include <iostream>
using namespace std;
class Base1{
public:
    void func(void){
        cout << "Base1的func" << endl;
    }
    int m_int;
};
class Base2{
public:
    void func(int i){
        cout << "Base2的func" << endl;
    }
    typedef int m_int;
};
class Derived:public Base1,public Base2{
public:
    //将两个基类中func函数都引入到当前子类
    //作用域,让它们在子类中形成重载.
    //using Base1::func;
    //using Base2::func;
};
int main(void){
    Derived d;
    d.Base1::func();
    d.Base2::func(10);
    
    d.Base1::m_int = 100;
    Derived::Base2::m_int i = 200;
    cout << d.Base1::m_int << ',' << i 
        << endl;

    return 0;
}







