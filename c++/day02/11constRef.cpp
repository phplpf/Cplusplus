#include <iostream>
using namespace std;
int func(void){
    int num = 100;
    return num;//int tmp = num
}
int main(void){
    //int& r1 = 100;//error
    const int& r1 = 100;//ok
    cout << r1 << endl;//100

    int i = 100;
    //首先将i隐式转换为char类型,转换结果
    //会保存在一个临时变量中,r2实际引用的
    //是临时变量(右值)
    //char& r2 = i;//error
    const char& r2 = i;//ok
    cout << (int)r2 << endl;
    cout << "&i=" << &i << endl;
    cout << "&r2=" << (void*)&r2 << endl;

    //一般函数返回结果会保存到临时变量中,
    //也是右值(将亡右值)
    //int r3 = tmp;
    //int& r3 = func();//error
    const int& r3 = func();//ok
    cout << r3 << endl;//100

    return 0;
}








