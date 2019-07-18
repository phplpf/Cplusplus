#include "Employee.h" 

Employee::Employee(const string& name,
        double salary):m_name(name),m_salary(salary){
    //读取ID
    FILE* fp = fopen("id.txt","r+");
    fscanf(fp,"%d",&m_id);
    //将文件读写指针定位到文件头
    fseek(fp,0,SEEK_SET);
    //ID加+1，再保存回id.txt
    fprintf(fp,"%d",m_id+1);
    //关闭id.txt
    fclose(fp);
    
    //将ID转换为字符串
    char filename[20] = {0};
    sprintf(filename,"%d",m_id);
    //根据id创建文件保存当前员工信息
    file = fopen(filename,"w");
    //保存员工信息
    saveInfo();

    //记录员工人数
    ++m_count;
    //保存员工人数
    FILE* fp2 = fopen("count.txt","w");
    fprintf(fp2,"%d",m_count);
    fclose(fp2);
}
Employee::~Employee(void){
    fclose(file);
    file = NULL;
}

void Employee::printInfo(void)const{
    printBasic();
    printExtra();
}
void Employee::printBasic(void)const{
    cout << "姓名：" << m_name << endl;
    cout << "工号：" << m_id << endl;
    cout << "基础工资:"  << m_salary << endl;
}
void Employee::printExtra(void)const{
    cout << "职位：普通员工" << endl;
}

void Employee::calSalary(void){
    double salary = calBasic() + calMerit();
    cout << "总工资为:" << salary << endl;
}

double Employee::calBasic(void){
    cout << "请输入出勤天数:";
    int days;
    cin >> days;
    m_attend = days/23.0;//计算出勤率
    return m_salary* m_attend;
}
double Employee::calMerit(void){
    return m_salary * m_attend / 2;
}

void Employee::setId(int id){
    if(id<10000)
        cout << "无效的工号" << endl;
    else
        m_id = id;
}
void Employee::setName(const string& name){
    if(name.size() > 20)
        cout << "无效的姓名" << endl;
    else
        m_name = name;
}
void Employee::setSalary(double salary){
    if(salary<0)
        cout << "无效的工资" << endl;
    else
        m_salary = salary;
}

void Employee::saveInfo(void){
    fprintf(file,"%d %s %g",m_id,m_name.c_str(),m_salary);
}

//静态成员需要在类的外部单独定义和初始化
int Employee::m_count = 0;

const int& Employee::getEmployeeCount(void){
    FILE* fp = fopen("count.txt","r");
    //加载员工人数
    fscanf(fp,"%d",&m_count);
    fclose(fp);
    return m_count;
}
bool Employee::operator==(int id)const{
    if(m_id == id){
        return true;
    }   
    else{
        return false;
    }   
}
bool Employee::operator!=(int id)const{
    return  !(*this == id);
}

//全局函数
ostream& operator<<(ostream& os,const Employee& emp){
    os << "Employee(" << emp.m_id << "," << emp.m_name << 
        "," << emp.m_salary << ")";
    return os;
}




