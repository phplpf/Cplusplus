#include <iostream>
using namespace std;
struct Teacher{
    //成员变量
    char name[20];
    int age;
    double salary;
    //成员函数
    void who(void){
        cout << "我叫" << name << ",今年"
          << age << "岁,工资是" << salary
          << endl;
    }
};
int main(void){
    Teacher wangjl = {"王建立",45,800.5};
    wangjl.who();
    Teacher* pt = &wangjl;
    pt->who();//(*pt).who()
    return 0;
}








