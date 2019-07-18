#include <iostream>
using namespace std;
int main(void){
    int a = 10;
    int& b = a;//b引用a,b就是a别名
    b++;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "&a=" << &a << endl;
    cout << "&b=" << &b << endl;

    //int& r;//error,引用定义必须初始化
    
    int c = 20;
    b = c;//ok,不是修改目标,仅是赋值操作
    
    cout << "a=" << a << endl;//20
    cout << "b=" << b << endl;//20
    cout << "&a=" << &a << endl;
    cout << "&b=" << &b << endl;

    //char& rc = c;//error,类型要保持一致

    return 0;
}


