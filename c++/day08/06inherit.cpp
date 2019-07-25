#include <iostream>
using namespace std;
class Base{
public:
    void func(void){
        cout << "Base::func(void)" << endl;
    }
};
class Derived:/*private*/protected Base{
};
int main(void){
    Derived d;
    //d.func();//error
    //Base* pb = &d;//向上造型,error
    //pb->func();//ok
    return 0;
}


