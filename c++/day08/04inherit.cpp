#include <iostream>
using namespace std;
class Base{
public:
    void func(void){
        cout << "Base的func" << endl;
    }
};
class Derived:public Base{
public:
    void func(int i){
        cout << "Derived的func" << endl;
    }
    //将基类中的func引入到子类作用域,让它们
    //在子类中形成重载.
    //using Base::func;
};
int main(void){
    Derived d;
    d.Base::func();
    d.func(10);
    return 0;
}





