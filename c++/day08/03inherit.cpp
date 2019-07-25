#include <iostream>
using namespace std;
class Base{
public:
    Base(void)
        :m_pub(100),m_pro(200),m_pri(300){}
    int m_pub;
protected:
    int m_pro;
private:
    int m_pri;
protected:
    const int& getPri(void)const{
        return m_pri;
    }
};
class Derived:public Base{
public:
    void print(void)const{
        cout << m_pub << endl;
        cout << m_pro << endl;
        cout << getPri() << endl;
    }
};
int main(void){
    Derived d;
    cout << sizeof(d) << endl;//12
    d.print();

    return 0;
}







