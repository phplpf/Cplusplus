#include <iostream>
using namespace std;
class A{
public:
    A(int data):m_data(data){}
    static void func1(void){
        cout << "静态成员函数" << endl;
        cout << m_data << endl;
        cout << s_data << endl;
    }
    void func2(void){
        cout << "非静态成员函数" << endl;
        cout << m_data << endl;
        cout << s_data << endl;
    }
    int m_data;
    static int s_data;
};
int A::s_data = 20;

int main(void){
    A::func1();
    A a(10);
    a.func2();

    return 0;
}





