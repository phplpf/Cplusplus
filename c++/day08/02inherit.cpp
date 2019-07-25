#include <iostream>
using namespace std;
class Human{//人类(基类)
public:
    Human(const string& name,int age)
        :m_name(name),m_age(age){}
    void eat(const string& food){
        cout << "我在吃" << food << endl;
    }
    void sleep(int hour){
        cout << "我睡了" << hour << "小时"
            << endl;
    }
//private:
protected:
    //保护成员:在类内部和子类中可以使用
    string m_name;
    int m_age;
};
//学生类(人类派生的一个子类)
class Student:public Human{
public:
    //Human(...):指明基类部分的初始化方式
    Student(const string& name,int age,
        int no):Human(name,age),m_no(no){}
    void who(void){
        cout << "我叫" << m_name << ",今年"
            << m_age << "岁,学号是" << m_no 
            << endl;
    }
    void learn(const string& course){
        cout << "我在学" << course << endl;
    }
private:
    int m_no;
};
//教师类(人类派生的另一个子类)
class Teacher:public Human{
public:
    Teacher(const string& name,int age,
      int sal):Human(name,age),m_sal(sal){}
    void who(void){
        cout << "我叫" << m_name << ",今年"
            << m_age << "岁,工资为" << 
            m_sal << endl;
    }
    void teach(const string& course){
        cout << "我在讲" << course << endl;
    }
private:
    int m_sal;
};
int main(void){
    Student s("关羽",28,10086);
    s.who();
    s.eat("牛肉拉面");
    s.sleep(8);
    s.learn("孙武兵法");
    Teacher t("孙悟空",30,50000);
    t.who();
    t.eat("桃子");
    t.sleep(6);
    t.teach("unix系统编程");
    
    //Student*->Human*:向上造型
    Human* ph = &s;
    ph->eat("牛肉拉面");
    ph->sleep(8);
    //ph->who();

    //Human*->Student*:向下造型(合理)
    Student* ps = static_cast<Student*>(ph);
    ps->who();

    Human h("王建立",45);
    //Human*->Student*:向下造型(不合理)
    Student* ps2=static_cast<Student*>(&h);
    ps2->who();//危险

    /*int* pi = NULL;
    Student* ps3 = (Student*)pi;
    ps3->who();*/

    return 0;
}













