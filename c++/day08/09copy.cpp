#include <iostream>
using namespace std;
class Base{
public:
    Base(int i=0):m_i(i){}
    Base(const Base& that){
        cout << "Base(const Base&)" << endl;
        m_i = that.m_i;
    }
    Base& operator=(const Base& that){
        cout << "Base::operator=" << endl;
        if(&that != this){
            m_i = that.m_i;
        }
        return *this;
    }
    int m_i;
};
class Derived:public Base{
public:
    Derived(int i=0,int j=0)
        :Base(i),m_j(j){}
    //Base(that):显式指明基类子对向以拷贝
    //方式初始化
    Derived(const Derived& that)
        :Base(that),m_j(that.m_j){
    }
    Derived& operator=(const Derived& that){
        if(&that != this){
            //显式调用基类的拷贝赋值函数,完
            //成基类子对象的赋值操作.
            Base::operator=(that);
            m_j = that.m_j;
        }
        return *this;
    }
    int m_j;
};
int main(void){
    Derived d1(10,20);
    cout << d1.m_i << ',' << d1.m_j << endl;
    Derived d2(d1);//拷贝构造
    cout << d2.m_i << ',' << d2.m_j << endl;
    Derived d3;
    d3 = d1;//拷贝赋值
    cout << d3.m_i << ',' << d3.m_j << endl;
    return 0;
}




