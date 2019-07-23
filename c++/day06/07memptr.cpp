#include <iostream>
#include <cstdio>
using namespace std;
class Student{
public:
    Student(const string& name)
        :m_name(name){}
    int m_age;
    double m_no;
    string m_name;
};
int main(void){
    //成员变量指针
    string Student::*pname=&Student::m_name;
    //printf("%p\n",pname);

    Student s("张三");
    Student* ps = new Student("李四");
    cout << s.*pname << endl;
    cout << ps->*pname << endl;

    delete ps;
    return 0;
}






