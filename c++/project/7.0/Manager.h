#ifndef __MANAGER_H_
#define __MANAGER_H_

#include "Employee.h"

class Manager:virtual public Employee{
public:
    Manager(const string& name,double salary,double m_bonus);
    void printInfo(void)const;
    void printExtra(void)const;
    void calSalary(void);
    double calMerit(void);
protected:
    double m_bonus;//绩效奖金
};

#endif//__MANAGER_H_


