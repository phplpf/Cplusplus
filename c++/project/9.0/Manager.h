#ifndef __MANAGER_H_
#define __MANAGER_H_

#include "Employee.h"
//经理类,钻石结构的“中间类”，需要使用虚继承
class Manager:virtual public Employee{
public:
    //构造函数1：指定员工姓名、工资、绩效工资
    Manager(const string& name,double salary,double m_bonus);
    //构造函数2：从文件中获取员工姓名、工资、绩效工资
    Manager(const string& filiename);
    //析构函数
    ~Manager(void);
protected:
    //打印经理的特有信息(自动变虚)
    void printExtra(void)const;
    //计算经理的绩效工资(自动变虚)
    double calMerit(void);
protected:
    double m_bonus;//绩效奖金
};
#endif//__MANAGER_H_

