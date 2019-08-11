#include <iostream>
using namespace std;
//类模板
template<class T>class CMath{
public:
    CMath(const T& t1, const T& t2):m_t1(t1),m_t2(t2){}
    T sum();
/*  T sum(){
        return m_t1 + m_t2;
    }*/
private:
    T m_t1;
    T m_t2;
};

template<class T>T CMath<T>::sum(){
    return m_t1 + m_t2;
} 

//class CMath<int>{....};
//class CMath<double>{....};
//class CMath<string>{....};
int main(){
    int nx=10, ny=20;
    CMath<int> m1(nx,ny);
    cout << m1.sum() << endl;

    double dx=12.3, dy=45.6;
    CMath<double> m2(dx,dy);
    cout << m2.sum() << endl;

    string sx="hello", sy=" world";
    CMath<string> m3(sx,sy);
    cout << m3.sum() << endl;

    return 0;
}





