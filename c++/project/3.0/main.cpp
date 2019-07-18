#include "Employee.h"

int main()
{
    Employee emp(10001,"张三",6600);
    emp.printInfo();
    emp.calSalary();

    Employee* pemp = new Employee(10002,"李四",8800);
    pemp->printInfo();
    pemp->calSalary();
    return 0;
}




