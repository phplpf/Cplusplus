#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H
#include <iostream>
using namespace std;

class Employee{
public:
    Employee(int id,const string& name,double salary);
    Employee(void);
    void printInfo(void);
    void calSalary(void);
    void setId(int id);
    void setName(const string& name);
    void setSalary(double salary);
private:
    int m_id;//工号
    string m_name;//姓名
    double m_salary;//工资
};

#endif//__EMPLOYEE_H


