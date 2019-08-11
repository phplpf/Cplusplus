#include <iostream>
using namespace std;
//类型参数和调用参数完全相关
template<class T>T Max(T x, T y){
    return x > y ? x : y;
}
//类型参数和调用参数不完全相关
template<class D,class T>void Foo(T x){
}
template<class R,class T>R Bar(T x){
    R r;
    return r;
}
int main(){
    int nx=10, ny=20;
    cout << Max(nx,ny) << endl;
            //Max<> ==> Max<int>
    double dx=12.3, dy=45.6;
    cout << Max(dx,dy) << endl;
            //Max<> ==> Max<double>
    string sx="world", sy="hello";
    cout << Max(sx,sy) << endl;
            //Max<> ==> Max<string>
    Foo<float>(nx);
    Max(nx,static_cast<int>(dy));
    Bar<int>(nx);
    return 0;
}






