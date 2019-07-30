#include <iostream>
#include <cstdio>
#include <csetjmp>
using namespace std;
jmp_buf g_env;
class A{
public:
    A(void){
        cout << "A的构造函数" << endl;
    }
    ~A(void){
        cout << "A的析构函数" << endl;
    }
};
int func3(void){
    A a;
    FILE* fp = fopen("xx.txt","r");
    if(fp == NULL){
        longjmp(g_env,-1);
    }
    cout << "func3正常运行" << endl;
    fclose(fp);
    return 0;
}
int func2(void){
    A a;
    func3();
    cout << "func2正常运行" << endl;
    return 0;
}
int func1(){
    A a;
    func2();
    cout << "func1正常运行" << endl;
    return 0;
}
int main(void){
    if(setjmp(g_env)==-1){
        cout << "文件打开失败" << endl;
        return -1;
    }
    func1();
    cout << "main正常运行" << endl;
    return 0;
}













