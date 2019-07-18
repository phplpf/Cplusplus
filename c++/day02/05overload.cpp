#include <iostream>
using namespace std;
//char->int:升级转换
void foo(int i){
    cout << "foo(1)" << endl;
}
//char->const char:常量转换
void foo(const char c){
    cout << "foo(2)" << endl;
}
//short->char:降级转换
void bar(char c){
    cout << "bar(1)" << endl;
}
//short->int:升级转换
void bar(int i){
    cout << "bar(2)" << endl;
}
//省略号匹配
void hum(int i,...){
    cout << "hum(1)" << endl;
}
//double->int:降级转换
void hum(int i,int j){
    cout << "hum(2)" << endl;
}
int main(void){
    char c = 'A';
    foo(c);
    short s = 100;
    bar(s);
    hum(100,1.23);
    return 0;
}




