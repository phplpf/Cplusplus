#include <iostream>
using namespace std;

class A{
public:
    void foo(){
        cout << "A::foo()" << endl;
    }
};
template<class T>void Max(){
//    fjdksfjsjfkdsl;
    A a;
    a.foo();
    T t;
    t.foo();
}
int main(){
    Max<A>();
    return 0;
}



