#include <iostream>
using namespace std;

template<class T>class CMath{
public:
    static void print(){
        cout << "&m_i:" << &m_i << "," << "&m_t:"
             << &m_t << endl;
    }
private:
    static int m_i;
    static T m_t;
};
template<class T>int CMath<T>::m_i;
template<class T>T CMath<T>::m_t;//?????
int main(){
    CMath<int> a, b;
    a.print();
    b.print();
    CMath<int>::print();

    cout << "---------------------" << endl;

    CMath<double> c, d;
    c.print();
    d.print();
    CMath<double>::print();
    return 0;
}

