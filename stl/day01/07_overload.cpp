#include <iostream>
using namespace std;
//普通函数
void Max(int x, int y){
    cout << "1:Max(int,int)" << endl;
}
//函数模板
template<class T>void Max(T x, T y){
    cout << "2:Max(T,T)" << endl;
}

template<class T>void Max(T* x, T* y){
    cout << "3:Max(T*,T*)" << endl;
}
int main(){
    int nx=10, ny=20;
    Max(nx,ny);
    double dx=12.3, dy=45.6;
    Max(dx,dy);
    Max(nx,dy);

    Max<>(nx,ny);

    Max<>(&nx,&ny);
    return 0;
}



