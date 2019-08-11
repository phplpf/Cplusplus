#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Student{
public:
    Student(const string& name="",const int& age=0):
                m_name(name),m_age(age){
        cout << "缺省构造了:" << m_name << "(" << this
             << ")" << endl;
    }
    Student(const Student& that):m_name(that.m_name),
                    m_age(that.m_age){
        cout << "用:" << that.m_name << "(" << &that
             << ")" << "拷贝构造了:" << m_name << "("
             << this << ")" << endl;
    }
    ~Student(){
        cout << "析构了:" << m_name << "(" << this
             << ")" << endl;
    }
private:
    string m_name;
    int m_age;
};

int main(){
    vector<Student> vs;
    vs.reserve(20);
    vs.push_back(Student("杨健",44));
    vs.push_back(Student("王建立",44));
    vs.push_back(Student("蒋贵良",35));
    getchar();

    return 0;
}




