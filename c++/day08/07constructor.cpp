#include <iostream>
using namespace std;
class Member{
public:
    Member(void):m_j(0){
        cout << "Member(void)" << endl;
    }
    Member(int j):m_j(j){
        cout << "Member(int)" << endl;
    }
    int m_j;
};
class Base{
public:
    Base(void):m_i(0){
        cout << "Base(void)" << endl;
    }
    Base(int i):m_i(i){
        cout << "Base(int)" << endl;
    }
    int m_i;
};
class Derived:public Base{
public:
    Derived(void){
        cout << "Derived(void)" << endl;
    }
    //Base(i):指明基类子对象初始化方式
    //m_mem(j):指明成员子对象初始化方式
    Derived(int i,int j):Base(i),m_mem(j){
        cout << "Derived(int)" << endl;
    }
    Member m_mem;
};
int main(void){
    Derived d;
    cout << d.m_i << ',' << d.m_mem.m_j
        << endl;//0,0
    Derived d2(100,200);
    cout << d2.m_i << ',' << d2.m_mem.m_j 
        << endl;//100,200
    return 0;
}








