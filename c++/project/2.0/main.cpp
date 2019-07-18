#include "Employee.h"

int main()
{
    Employee emp2;
    emp2.printInfo();
    
    Employee emp(10011,"张三",6600);
    emp.printInfo();
    emp.calSalary();

    Employee* pemp = new Employee(10012,"李四",8800);
    pemp->printInfo();
    pemp->calSalary();
    return 0;
}




