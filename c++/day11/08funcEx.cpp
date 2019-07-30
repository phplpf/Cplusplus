#include <iostream>
using namespace std;
class FileError{};
class MemoryError{};
class Base{
public:
    virtual void func(void)
        throw(FileError,MemoryError){
        cout << "Base::func" << endl;    
    }
    virtual ~Base(void) throw() {}
};
class Derived:public Base{
public:
    void func(void)
        throw(FileError){
        cout << "Derived::func" << endl;
    }
    ~Derived(void) throw() {}
    //int m_i;
    //string m_s;
};
int main(void){
    Base* pb = new Derived;
    pb->func();
    
    delete pb;

    return 0;
}















