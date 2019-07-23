#include <iostream>
using namespace std;
class Student;//短视声明
class Teacher{//教师类
public:
    void educate(Student* s);
    void reply(const string& answer);
private:
    string m_answer;
};
class Student{//学生类
public:
    void ask(const string& ques,Teacher* t);
};
void Teacher::educate(Student* s){
    s->ask("什么this指针?",this);
    cout << "学生回答:" << m_answer << endl;
}
void Teacher::reply(const string& answer){
    m_answer = answer;
}
void Student::ask(const string& ques,Teacher* t){
    cout << "问题:" << ques << endl;
    t->reply("this指针指向调用对象的地址");
}
int main(void){
    Teacher t;
    Student s;
    t.educate(&s);
    return 0;
}







