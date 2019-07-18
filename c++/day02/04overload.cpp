#include <iostream>
using namespace std;
void func(int i){
    cout << "func(int)" << endl;
}
void func(int i,int j){
    cout << "func(int,int)" << endl;
}
double func(void){
    cout << "func(void)" << endl;
}
void func(int a,float b){
    cout << "func(int,float)" << endl;
}
int main(void){
    func(100);
    func(100,200);
    func();
    func(100,1.23f);
    
    //当通过函数指针调用重载关系的函数时,
    //根据函数指针类型选择匹配的重载版本.
    void (*pfunc)(int,float) = func;
    pfunc(100,200);

    return 0;
}




