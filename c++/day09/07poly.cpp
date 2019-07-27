#include <iostream>
using namespace std;
class Base{
public:
    virtual int cal(int i,int j){
        return i + j;
    }
    //void func(Base* this=&d)
    void func(void){
        //cout << this->cal(10,20) << ...
        cout << cal(10,20) << endl;
    }
};
class Derived:public Base{
public:
    int cal(int i,int j){
        return i * j;
    }
};
int main(void){
    Derived d;
    //Base b = d;
    //cout << b.cal(10,20) << endl;
    d.func();//func(&d)
    return 0;
}






