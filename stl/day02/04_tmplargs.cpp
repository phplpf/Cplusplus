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
template<class D,template<class M>class C>
class Sum{//求和器
public:
    Sum(const C<D>& s):m_s(s){}
    D add(){
        D d = D();
        for(int i=0; i<10; i++){
            d += m_s[i];
        }
        return d;
    }
private:
    C<D> m_s;//Array<D> m_s;
};
int main(){
    Array<int> a;
    for(int i=0; i<10; i++)
        a[i] = i+1;

    Sum<int,Array> s(a);
    cout << s.add() << endl;
    return 0;
}






