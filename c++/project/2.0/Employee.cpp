#include "Employee.h" 

Employee::Employee(void){
    m_id = 0;
    m_name = "无名";
    m_salary = 0.0;
}
Employee::Employee(int id,const string& name,double salary){
    m_id = id;
    m_name = name;
    m_salary = salary;
}
void Employee::printInfo(void){
    cout << "姓名：" << m_name << endl;
    cout << "工号：" << m_id << endl;
    cout << "基础工资:"  << m_salary << endl;
}
void Employee::calSalary(void){
    cout << "请输入出勤天数:";
    int days;
    cin >> days;
    double basic = m_salary* (days/23.0);
    double merit = basic / 2;
    cout << "总工资:" << (basic + merit) << endl;
}
void Employee::setId(int id){
    if(id<10000)
        cout << "无效的工号" << endl;
    else
        m_id = id;
}
void Employee::setName(const string& name){
    if(name.size() > 20)
        cout << "无效的姓名" << endl;
    else
        m_name = name;
}
void Employee::setSalary(double salary){
    if(salary<0)
        cout << "无效的工资" << endl;
    else
        m_salary = salary;
}

