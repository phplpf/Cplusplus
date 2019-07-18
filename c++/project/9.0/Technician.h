#ifndef __TECHNICION_H_
#define __TECHNICION_H_

#include "Employee.h"
//技术员类，钻石结构的“中间类”，需要使用虚继承
class Technician:virtual public Employee{
public:
    //构造函数1：员工姓名、工资、研发津贴
    Technician(const string& name,double salary,double allow);
    //构造函数2：从文件中获取员工姓名、工资、研发津贴
    Technician(const string& filename);
    //析构函数
    ~Technician(void);
protected:
    //打印技术员特有信息(自动变虚函数)
    void printExtra(void)const;
    //计算技术员的绩效工资(自动变虚函数)
    double calMerit(void);
protected:
    double m_allow;//研发津贴
};

#endif//__TECHNICION_H_


