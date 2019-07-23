#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>
#include <cstdio>
using namespace std;

class Employee{
public:
    Employee(const string& name,double salary);
    ~Employee(void);
    void printInfo(void)const;
    void calSalary(void);
    void setId(int id);
    void setName(const string& name);
    void setSalary(double salary);
    void saveInfo(void);

    //根据员工对象的id和参数id比较，判断是否为同一个员工
    bool operator==(int id)const;
    bool operator!=(int id)const;    
    //重载插入操作符，实现员工信息打印输出
    friend ostream& operator<<(
            ostream& os,const Employee& emp);

private:
    //禁止拷贝构造和拷贝复制
    Employee& operator=(const Employee&);
    Employee(const Employee&);
private:
    int m_id;//工号
    string m_name;//姓名
    double m_salary;//工资
    FILE* file;//保存员工信息的文件
public:
    //获取员工人数
    static const int& getEmployeeCount(void);
private:
    static int m_count;//记录员工人数
};

#endif
