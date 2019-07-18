#include <iostream>
using namespace std;
//函数声明
void func(int a,int b=20,int c=30);
//void func(int a){}//注意歧义错误

int main(void){
    func(11,22,33);
    func(11,22);//11 22 30
    func(11);//11 20 30
    return 0;
}
//函数定义
void func(int a,int b/*=20*/,int c/*=30*/){
    cout << "a=" << a << ",b=" << b <<
        ",c=" << c << endl;
}

