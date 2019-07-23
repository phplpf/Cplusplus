#include <iostream>
#include <cstdio>
using namespace std;
class Student{
public:
    Student(const string& name)
        :m_name(name){}
    void who(void){
        cout << "姓名:" << m_name << endl;
    }
    string m_name;
};
int main(void){
    //成员函数指针
    void (Student::*pwho)(void) =
        &Student::who;
    Student s("张三");
    Student* ps = new Student("李四");
    (s.*pwho)();
    (ps->*pwho)();

    delete ps;
    return 0;
}






