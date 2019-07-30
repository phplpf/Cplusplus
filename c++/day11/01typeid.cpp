#include <iostream>
#include <typeinfo>
using namespace std;
class A{ virtual void func(){} };
class B:public A{ void func(){} };
class C:public A{ void func(){} };
//...
void foo(A& ra){
    if(typeid(ra) == typeid(B)){
        cout << "针对B子类处理" << endl;
    }
    else if(typeid(ra) == typeid(C)){
        cout << "针对C子类处理" << endl;
    }
}
int main(void){
    int i = 100;
    cout << typeid(int).name() << endl;
    cout << typeid(i).name() << endl;

    int (*a1)[10];
    int *a2[10];
    cout << typeid(a1).name() << endl;
    cout << typeid(a2).name() << endl;
    
    cout << typeid(void (*[3])(int)).name()
        << endl;
    B b;
    foo(b);
    C c;
    foo(c);

    return 0;
}



