#include "CTO.h"

//虚继承时，位于继承链的末端子类负责构造公共基类子对象
CTO::CTO(const string& name,double salary,double allow,double bonus):
    Technician(name,salary,allow),Manager(name,salary,bonus),Employee(name,salary){}

void CTO::printInfo(void)const{
    printBasic();
    printExtra();
}
void CTO::printExtra(void)const{
    cout << "职位:技术主管" << endl;
    cout << "研发津贴:" << m_allow << endl;
    cout << "绩效奖金:" << m_bonus << endl;
}
void CTO::calSalary(void){
    double salary = calBasic() + calMerit();
    cout << "总工资为:" << salary << endl;
}
double CTO::calMerit(void){
    return (Technician::calMerit() + Manager::calMerit()) / 2;
}




