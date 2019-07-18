#include "Technician.h"

Technician::Technician(const string& name,double salary,double allow)
    :Employee(name,salary),m_allow(allow){
        //保存员工绩效信息
        fprintf(file," %g",m_allow);    
}
void Technician::printInfo(void)const{
    printBasic();
    printExtra();
}
void Technician::printExtra(void)const{
    cout << "职位:技术员" << endl;
    cout << "研发津贴:" << m_allow << endl;
}
void Technician::calSalary(void){
    double salary = calBasic() + calMerit();
    cout << "总工资为:" << salary << endl;
}
double Technician::calMerit(void){
    cout << "请输入进度因数:";
    double factor;
    cin >> factor;
    return 23*8*m_attend * m_allow * factor;
}





