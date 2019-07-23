#include <iostream>
using namespace std;
class Teacher{
public:
    /*Teacher(const string& name,int age)
        :m_name(name),m_age(age){
        cout << "this=" << this << endl;    
    }*/
    //通过this可以区分成员变量和形参变量
    //通过this所访问的一定是成员变量
    Teacher(const string& m_name,int m_age){
        cout << "this=" << this << endl;    
        this->m_name = m_name;
        this->m_age = m_age;
    }
    void print(void){
        cout << m_name << "," << m_age <<endl;
        cout << this->m_name << "," << 
            this->m_age << endl;
    }/*print函数编译以后:
    void print(Teacher* this){
        cout << this->m_name << "," << 
            this->m_age << endl;
    }*/
private:
    string m_name;
    int m_age;
};
int main(void){
    Teacher t1("杨健",46);
    Teacher t2("王建立",45);
    t1.print();//Teacher::print(&t1);
    t2.print();//Teacher::print(&t2);
    cout << "&t1=" << &t1 << endl;
    cout << "&t2=" << &t2 << endl;
    return 0;
}






