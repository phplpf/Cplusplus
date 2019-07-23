#include <iostream>
using namespace std;
class A{
public:
    A(void){
        cout << "A的构造函数" << endl;
    }
    ~A(void){
        cout << "A的析构函数" << endl;
    }
};
class B{
public:
    B(void){
        cout << "B的构造函数" << endl;
    }
    ~B(void){
        cout << "B的析构函数" << endl;
    }
    A m_a;//成员子对象
};
int main(void){
    B b;
    return 0;
}







