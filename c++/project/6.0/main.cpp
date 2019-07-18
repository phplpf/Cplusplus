#include "Employee.h"
#include "Technician.h"
#include "Manager.h"

#include <unistd.h>
#include <cstdio>
#include <cstdlib>
void init(void){
    if(access("id.txt",F_OK)==-1){
        FILE* fp = fopen("id.txt","w");//记录工号
        if(fp == NULL){
            perror("fopen"),exit(-1);
        }
        fprintf(fp,"%d",10001);
        fclose(fp);
    }
    if(access("count.txt",F_OK)==-1){
        FILE* fp = fopen("count.txt","w");//记录人数
        if(fp == NULL){
            perror("fopen"),exit(-1);
        }
        fprintf(fp,"%d",0);
        fclose(fp);
    }
    else{
        //加载员工人数
        Employee::getEmployeeCount();
    }
}

int main()
{
    init();
    cout << "欢迎使用企业员工个信息管理系统:" << endl;
    Employee emp("张三",6600);
    emp.printInfo();
    emp.calSalary();
    cout << "===========================" << endl;

    Technician tech("孔明",8800,30);
    tech.printInfo();
    tech.calSalary();
    cout << "===========================" << endl;
    
    Manager manager("刘备",12000,5000);
    manager.printInfo();
    manager.calSalary();
    cout << "===========================" << endl;


    return 0;
}




