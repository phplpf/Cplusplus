#include <iostream>
using namespace std;
class Human{//人类(基类)
public:
    Human(const string& name,int age)
        :m_name(name),m_age(age){}
    friend ostream& operator<<(
        ostream& os,const Human& h){
        os << h.m_name << ',' << h.m_age;
        return os;
    }
protected:
    string m_name;
    int m_age;
};
//学生类(人类派生的一个子类)
class Student:public Human{
public:
    Student(const string& name,int age,
        int no):Human(name,age),m_no(no){}
    friend ostream& operator<<(
        ostream& os,const Student& s){
        /*os << s.m_name << ',' << s.m_age
            << ',' << s.m_no;*/
        os << (Human&)s << ',' << s.m_no;
        return os;
    }
private:
    int m_no;
};
int main(void){
    Student s("关羽",28,10086);
    cout << s << endl;
    return 0;
}













