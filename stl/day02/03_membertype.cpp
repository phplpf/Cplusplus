#include <iostream>
using namespace std;

template<class X>class A{
public:
    template<class Y>class B{
    public:
        template<class Z>class C;
    };
};
template<class X>
template<class Y>
template<class Z>class A<X>::B<Y>::C{
public:
    template<class M>void foo(){
        cout << 
          "A<X>::B<Y>::C<Z>::foo<M>()" 
          << endl;
    }
};
int main(){
    A<int>::B<double>::C<string> c;
    c.foo<float>();
    return 0;
}






