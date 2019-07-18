#include "Employee.h" 

Employee::Employee(const string& name,double salary,LEVEL level):
    m_name(name),m_salary(salary),m_level(level){
    //读取ID
    FILE* fp = fopen("id.txt","r+");
    fscanf(fp,"%d",&m_id);
    
    //将ID转换为字符串
    char filename[20] = {0};
    sprintf(filename,"%d",m_id);

    //如果和id对应的文件不存在
    if(access(filename,F_OK) == -1){
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

        //将文件读写指针定位到文件头
        fseek(fp,0,SEEK_SET);
        //ID加+1，再保存回id.txt
        fprintf(fp,"%d",m_id+1);
    }
    //关闭id.txt
    fclose(fp);
}
Employee::Employee(const string& filename){
    int level;
    char name[20]={0};
    //将ID转换为字符串
    if(access(filename.c_str(),F_OK) == -1){
        cout << "id=" << filename << "员工不存在!" << endl;
    }
    else{
        //打开对应的员工文件(读写方式)
        file = fopen(filename.c_str(),"r+");
        //从文件中读取员工信息，保存到成员变量中
        fscanf(file,"%d %d %s %lf",&level,&m_id,name,&m_salary);
        //根据level确定员工类型
        switch(level){
        case 101://普通员工
            m_level = L1;
            break;
        case 201://技术员
            m_level = L2;
            break;
        case 301://经理
            m_level = L3;
            break;
        case 401://技术主管
            m_level = L4;
        }
        //初始化员工姓名
        m_name = name;
    }
}
//析构函数
Employee::~Employee(void){
    //员工对象销毁时，关闭对应的文件
    fclose(file);
    file = NULL;
}
//打印员工信息
void Employee::printInfo(void)const{
    printBasic();
    printExtra();
}
//打印员工公有信息
void Employee::printBasic(void)const{
    cout << "姓名：" << m_name << endl;
    cout << "工号：" << m_id << endl;
    cout << "基础工资:"  << m_salary << endl;
}
//打印员工特有信息(virtual)
void Employee::printExtra(void)const{
    cout << "职位：普通员工" << endl;
}
//计算工资
void Employee::calSalary(void){
    double salary = calBasic() + calMerit();
    cout << "总工资为:" << salary << endl;
}
//计算基本工资
double Employee::calBasic(void){
    cout << "请输入出勤天数:";
    int days;
    cin >> days;
    m_attend = days/23.0;//计算出勤率
    return m_salary* m_attend;
}
//计算绩效工资(virtual)
double Employee::calMerit(void){
    return m_salary * m_attend / 2;
}
//修改ID
void Employee::setId(int id){
    if(id<10000)
        cout << "无效的工号" << endl;
    else
        m_id = id;
}
//修改姓名
void Employee::setName(const string& name){
    if(name.size() > 20)
        cout << "无效的姓名" << endl;
    else
        m_name = name;
}
//修改工资
void Employee::setSalary(double salary){
    if(salary<0)
        cout << "无效的工资" << endl;
    else
        m_salary = salary;
}
//保存员工信息到文件
void Employee::saveInfo(void){
    //将文件读写指针定位到文件头
    fseek(file,0,SEEK_SET);
    //级别，工号，姓名，工资
    //-10.2lf:格式化控制,右对齐/10字符宽度/保留2为小数
    int res = fprintf(file,"%d %d %s %-10.2lf",
            m_level,m_id,m_name.c_str(),m_salary);
    //刷新文件流
    fflush(file);
    if(res < 0){
        perror("fprintf");
        cout << "保存信息出错!" << endl;
    }
}

//静态成员需要在类的外部单独定义和初始化
//记录员工人数
int Employee::m_count = 0;

//获取员工人数
const int& Employee::getEmployeeCount(void){
    FILE* fp = fopen("count.txt","r");
    //加载员工人数
    fscanf(fp,"%d",&m_count);
    fclose(fp);
    return m_count;
}

//重载输出操作符(全局函数)
ostream& operator<<(ostream& os,const Employee& emp){
    os << "Employee(" << emp.m_id << "," << emp.m_name << 
        "," << emp.m_salary << ")";
    return os;
}
//根据员工对象的id和参数id比较，返回是否相等的bool值
bool Employee::operator==(int id)const{
    if(m_id == id){
        return true;
    }
    else{
        return false;
    }
}
//根据员工对象的id和参数id比较，返回是否不相等的bool值
bool Employee::operator!=(int id)const{
    return  !(*this == id);
}




