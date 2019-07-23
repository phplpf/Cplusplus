#include <iostream>
using namespace std;
int num = 200;
class A{
public:
    /*A(void){
        m_i = 100;
        m_r = num;
    }*/
    A(void):m_i(100),m_r(num){}
    const int m_i;
    int& m_r;
};
int main(void){
    A a;
    cout << a.m_i << ',' << a.m_r << endl;
    return 0;
}




