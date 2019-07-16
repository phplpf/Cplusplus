#include <iostream>
#include <cstring>
using namespace std;
int main(void){
    //定义
    string s1 = "hello";
    cout << s1 << endl;
    //拷贝
    string s2;
    s2 = s1;
    cout << s2 << endl;//hello
    //连接
    //s1 += " world"
    s1 = s1 + " world";
    cout << s1 << endl;//hello world
    //比较
    cout << (s1==s2) << endl;//0
    cout << ("hello"==s2) << endl;//1
    //下标访问
    s1[0] = 'H';//char
    s1[6] = 'W';
    cout << s1 << endl;//Hello World
    //成员函数
    cout << "len=" << s1.size() << endl;
    cout << "len=" << s1.length() <<endl;
    cout << "len=" << strlen(s1.c_str())
        << endl;//11
    

    return 0;
}


