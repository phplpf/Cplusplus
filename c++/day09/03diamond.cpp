#include <iostream>
using namespace std;
class A{//公共基类
public:
    A(int data):m_data(data){
        cout << "A::" << this << ',' << 
            sizeof(A) << endl;
    }
protected:
    int m_data;
};
class B:public A{//中间类
public:
    B(int data):A(data){
        cout << "B::" << this << ',' << 
            sizeof(B) << endl;
    }
    void set(int data){
        m_data = data;
    }
};
class C:public A{//中间类
public:
    C(int data):A(data){
        cout << "C::" << this << ',' << 
            sizeof(C) << endl;
    }
    int get(void){
        return m_data;
    }
};
class D:public B,public C{//末端子类
public:
    D(int data):B(data),C(data){
        cout << "D::" << this << ',' << 
            sizeof(D) << endl;
    }
};
int main(void){
    D d(100);
    cout << d.get() << endl;//100
    d.set(200);
    cout << d.get() << endl;//200
    return 0;
}






