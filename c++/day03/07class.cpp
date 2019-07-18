#include <iostream>
using namespace std;
//原来:结构体
//现在:类
//struct Student{
class Student{
public:
    //成员函数:描述行为
    void eat(const string& food){
        cout << "我在吃" << food << endl;
    }
    void sleep(int time){
        cout << "我睡了" << time <<
            "小时" << endl;
    }
    void learn(const string& course){
        cout << "我在学" << course<<endl;
    }
    void who(void){
        cout << "我叫" << m_name << ",今年" 
            << m_age << "岁,学号是" << m_no 
                << endl;
    }
public:
    /* 类中私有成员不能在外部直接访问,但是可
     * 以通过类似如下的公有函数来间接访问,这
     * 样可以实现对非法数据加以限定,控制程序
     * 逻辑的合理性,这种编程方法即为封装!*/
    void setName(const string& newName){
        if(newName == "二")
            cout << "你才二" << endl;
        else
            m_name = newName;
    }
    void setAge(int newAge){
        if(newAge < 0)
            cout << "无效的年龄" << endl;
        else
            m_age = newAge;
    }
    void setNo(int newNo){
        if(newNo < 10000)
            cout << "无效的学号" << endl;
        else
            m_no = newNo;
    }
private:
    //成员变量:描述属性
    string m_name;
    int m_age;
    int m_no;
};
int main(void){
    //原来:定义结构体类型变量
    //现在:创建对象/实例化对象/构造对象
    Student s;
    /*s.m_name = "张飞";
    s.m_name = "二";
    s.m_age = 28;
    s.m_no = 10011;*/
    s.setName("张翼德");
    s.setName("二");
    s.setAge(29);
    s.setAge(-1);
    s.setNo(10086);
    s.setNo(-1);

    s.who();
    s.eat("兰州拉面");
    s.sleep(8);
    s.learn("C++编程");

    return 0;
}





