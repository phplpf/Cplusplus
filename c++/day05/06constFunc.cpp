#include <iostream>
using namespace std;
class A{
public:
    A(int data = 0):m_data(data){}
    //void print(const A* this)
    void print(void) const {//常成员函数
        //cout << this->m_data++ << endl;
        cout << m_data/*++*/ << endl;
        //const_cast<A*>(this)->m_spec = 321;
        m_spec = 321;
        cout << m_spec << endl;
    }
private:
    int m_data;
    mutable int m_spec;
};
int main(void){
    A a(123);
    a.print();//123
    a.print();//124
    return 0;
}






