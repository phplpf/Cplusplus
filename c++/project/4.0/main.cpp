#include "Employee.h"
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
    cout << "员工人数:" << Employee::getEmployeeCount() << endl;; 
    
    Employee emp("张三",6600);
    emp.printInfo();
    emp.calSalary();
    cout << "员工人数:" << Employee::getEmployeeCount() << endl;; 

    Employee* pemp = new Employee("李四",8800);
    pemp->printInfo();
    pemp->calSalary();
    cout << "员工人数:" << Employee::getEmployeeCount() << endl;; 
    return 0;
}




