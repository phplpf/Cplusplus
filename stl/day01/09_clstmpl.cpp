#include <iostream>
using namespace std;
class Integer{
public:
    Integer(const int& i):m_i(i){}
    const Integer operator+(const Integer& that)const{
        return m_i + that.m_i;
    }
private:
    int m_i;
};
//类模板
template<class T>class CMath{
public:
    CMath(const T& t1, const T& t2):m_t1(t1),m_t2(t2){}
    T sum(){
        return m_t1 + m_t2;
    }
    //...
private:
    T m_t1;
    T m_t2;
};
/*
class CMath<Integer>{
public:
    CMath(const Integer& t1, const Integer& t2):
                    m_t1(t1),m_t2(t2){}
    Integer sum(){
        return m_t1 + m_t2;
    }
private:
    Integer m_t1;
    Integer m_t2;
};
*/
int main(){
    int nx=10, ny=20;
    CMath<int> m1(nx,ny);
    m1.sum();

    Integer ix=100, iy=200;
    CMath<Integer> m2(ix,iy);
    m2.sum();

//  CMath<> m3(nx,ny);
    return 0;
}





