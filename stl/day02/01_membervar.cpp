#include <iostream>
using namespace std;

template<class T>class Array{
public:
    T& operator[](size_t i){
        return m_arr[i];
    }
private:
    T m_arr[10];
};
template<class D>class Sum{//求和器
public:
    Sum(const Array<D>& s):m_s(s){}
    D add(){
        D d = D();
        for(int i=0; i<10; i++){
            d += m_s[i];
        }
        return d;
    }
private:
    Array<D> m_s;//模板型成员变量
};
int main(){
    Array<int> a;
    for(int i=0; i<10; i++)
        a[i] = i+1;

    Sum<int> s(a);
    cout << s.add() << endl;
    return 0;
}






