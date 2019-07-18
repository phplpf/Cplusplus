#include "Technician.h"

Technician::Technician(const string& name,double salary,double allow)
    :Employee(name,salary,L2),m_allow(allow){
        //保存员工绩效信息
        fprintf(file," %g",m_allow);    
        fflush(file);
}

Technician::Technician(const string& filename)
    :Employee(filename){
    fscanf(file,"%lf",&m_allow);
}

Technician::~Technician(void){}

void Technician::printExtra(void)const{
    cout << "职位:技术员" << endl;
    cout << "研发津贴:" << m_allow << endl;
}

double Technician::calMerit(void){
    cout << "请输入进度因数:";
    double factor;
    cin >> factor;
    return 23*8*m_attend * m_allow * factor;
}





