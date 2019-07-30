#include <iostream>
using namespace std;
class A{ virtual void func(){} };
class B:public A{ void func(){} };
class C:public A{ void func(){} };
int main(void){
    B b;
    A* pa = &b;
    //B* pb = static_cast<B*>(pa);//合理
    B* pb = dynamic_cast<B*>(pa);//ok
    //C* pc = static_cast<C*>(pa);//不合理
    C* pc = dynamic_cast<C*>(pa);//error
    cout << "pa=" << pa << endl;
    cout << "pb=" << pb << endl;
    cout << "pc=" << pc << endl;//NULL

    A& ra = b;
    C& rc = dynamic_cast<C&>(ra);//不合理

    return 0;
}



