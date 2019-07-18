#include "Employee.h"
#include "Technician.h"
#include "Manager.h"
#include "CTO.h"
#include "Company.h"

int main()
{
    //获取表示公司的单例对象
    Company& company = Company::getCompany();
    //运行公司管理系统
    company.run();
    return 0;
}




