#ifndef __TECHNICION_H_
#define __TECHNICION_H_

#include "Employee.h"

class Technician:public Employee{
public:
    Technician(const string& name,double salary,double allow);
    void printInfo(void)const;
    void printExtra(void)const;
    void calSalary(void);
    double calMerit(void);
private:
    double m_allow;//研发津贴
};

#endif//__TECHNICION_H_


