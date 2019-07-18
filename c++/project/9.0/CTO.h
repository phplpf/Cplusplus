#ifndef __CTO_H_
#define __CTO_H_

#include "Technician.h"
#include "Manager.h"
//技术主管类，钻石结构的“末端子类”
class CTO:public Technician,public Manager{
public:
    //构造函数1：员工姓名，工资，研发津贴，绩效奖金
    CTO(const string& name,double salary,
        double allow,double bonus);
    //构造函数2:从文件中获取员工姓名，工资，研发津贴，绩效奖金
    CTO(const string& filename);
    //析构函数
    ~CTO(void);
private:
    //打印技术主管特有信息(自动变虚函数)
    void printExtra(void)const;
    //计算技术主管的绩效工资(自动变虚函数)
    double calMerit(void);
};

#endif//__CTO_H_



