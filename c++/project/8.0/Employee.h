#ifndef __EMPLOYEE_H_
#define __EMPLOYEE_H_

#include <iostream>
#include <cstdio>
using namespace std;

class Employee{
public:
    Employee(const string& name,double salary);
    ~Employee(void);
    //打印信息
    void printInfo(void)const;
protected:
    void printBasic(void)const;//公有信息
    virtual void printExtra(void)const;//特有信息
public:
    //计算工资
    void calSalary(void);
protected:
    double calBasic(void);//基本工资
    virtual double calMerit(void);//绩效工资
public:
    void setId(int id);
    void setName(const string& name);
    void setSalary(double salary);
    void saveInfo(void);
    bool operator==(int id)const;
    bool operator!=(int id)const;
    friend ostream& operator<<(ostream& os,const Employee& emp);
private:
    //禁止拷贝构造和拷贝复制
    Employee& operator=(const Employee&);
    Employee(const Employee&);
protected://保护成员子类可以直接访问
    int m_id;//工号
    string m_name;//姓名
    double m_salary;//工资
    FILE* file;//保存员工信息指针
    double m_attend;//出勤率
public:
    //获取员工人数
    static const int& getEmployeeCount(void);
private:
    static int m_count;//记录员工人数
};





#endif//__EMPLOYEE_H_

