#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include <iostream>
#include <cstdio>
using namespace std;

class Employee{
public:
    Employee(int id,const string& name,double salary);
    Employee(void);
    ~Employee(void);
    void printInfo(void)const;
    void calSalary(void);
    void setId(int id);
    void setName(const string& name);
    void setSalary(double salary);
    void saveInfo(void)const;
private:
    int m_id;//工号
    string m_name;//姓名
    double m_salary;//工资
    FILE* file;//保存信息文件
};
#endif//__EMPLOYEE_H



