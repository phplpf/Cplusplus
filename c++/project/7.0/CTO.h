#ifndef __CTO_H_
#define __CTO_H_

#include "Technician.h"
#include "Manager.h"

class CTO:public Technician,public Manager{
public:
    CTO(const string& name,double salary,
        double allow,double bonus);
    void printInfo(void)const;
    void calSalary(void);
private:
    void printExtra(void)const;
    double calMerit(void);
};

#endif//__CTO_H_



