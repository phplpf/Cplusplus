#include <iostream>
using namespace std;

struct Employee{
//public:
    void printInfo(void){
        cout << "姓名：" << m_name << endl;
        cout << "工号：" << m_id << endl;
        cout << "基础工资:"  << m_salary << endl;
    }
    void calSalary(void){
        cout << "请输入出勤天数:";
        int days;
        cin >> days;
        double basic = m_salary * (days/23.0);
        double merit = basic / 2;
        cout << (basic + merit) << endl;
    }
public:
    void setId(int id){
        if(id<10000)
            cout << "无效的工号" << endl;
        else
            m_id = id;
    }
    void setName(const string& name){
        if(name.size() > 20)
            cout << "无效的姓名" << endl;
        else
            m_name = name;
    }
    void setSalary(double salary){
        if(salary<0)
            cout << "无效的工资" << endl;
        else
            m_salary = salary;
    }
private:
    int m_id;//工号
    string m_name;//姓名
    double m_salary;//工资
};
int main()
{
    Employee emp;
    emp.setId(10011);
    emp.setName("张三");
    emp.setSalary(6600);

    emp.printInfo();
    emp.calSalary();
    return 0;
}




