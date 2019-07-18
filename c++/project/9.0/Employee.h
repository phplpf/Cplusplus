#ifndef __EMPLOYEE_H_
#define __EMPLOYEE_H_

#include <iostream>
#include <cstdio>
#include <unistd.h>
using namespace std;

class Employee{
public:
    //员工级别：L1:普通员工 L2:技术员 L3:经理 L4:技术主管
    enum LEVEL{L1=101,L2=201,L3=301,L4=401};
public:
    //创建新的员工
    Employee(const string& name,double salary,LEVEL level=L1);

    //根据文件信息，创建员工对象
    Employee(const string& filename);

    //虚析构函数
    virtual ~Employee(void);
    
    //打印信息
    void printInfo(void)const;
    
    //计算工资
    void calSalary(void);

protected:
    void printBasic(void)const;//公有信息
    virtual void printExtra(void)const;//特有信息
protected:
    double calBasic(void);//基本工资
    virtual double calMerit(void);//绩效工资
public:
    void setId(int id);
    void setName(const string& name);
    void setSalary(double salary);
    void saveInfo(void);
    //根据员工对象的id和参数id比较，是否相等
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
    LEVEL m_level;//员工级别
public:
    //获取员工人数
    static const int& getEmployeeCount(void);
private:
    static int m_count;//记录员工人数
};

#endif//__EMPLOYEE_H_

