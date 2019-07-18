#include "Company.h"
#include <cstdlib>
#include <unistd.h>

//单例对象是静态成员，这里完成定义和初始化
Company Company::company;//匹配无参构造函数

//用于获取表示公司单例对象的静态成员函数
Company& Company::getCompany(void){
    return company;
}
//构造函数
Company::Company(void){
    //判断记录员工id的文件是否存在，不存在则创建
    if(access("id.txt",F_OK)==-1){
        FILE* fp = fopen("id.txt","w");//记录工号
        if(fp == NULL){
            perror("fopen"),exit(-1);
        }
        fprintf(fp,"%d",10001);
        fclose(fp);
    }
    //判断记录员工人数的文件是否存在，不存在则创建
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
        //size()==>Employee::getEmployeeCount();
        
        //从文件中加载员工信息，并保存到文件
        for(int i=0;i<size();i++){
            int id = 10001+i;
            char filename[20]={0};
            sprintf(filename,"%d",id);
            if(access(filename,F_OK)==-1){
                continue;
            }
            else{
                //cout << "从文件" << filename << "加载员工信息.." << endl;
                empVector.push_back(loadInfo(filename));
            }
        }
    }
}
Company::~Company(void){}

//加载文件信息，创建对应的员工对象，返回对象指针
Employee* Company::loadInfo(const string& filename){
    int id;
    char name[20];
    double salary;
    int level;
    Employee* pret;
    FILE* fp = fopen(filename.c_str(),"r");
    if(fp == NULL){
        perror("fopen");
        return NULL;
    }
    fscanf(fp,"%d",&level);
    switch(level){
        case Employee::L1:
            //cout << "加载普通员工" << endl;
            pret = new Employee(filename);
            break;
        case Employee::L2:
            //cout << "加载技术员" << endl;
            pret = new Technician(filename);
            break;
        case Employee::L3:
            //cout << "加载经理" << endl;
            pret = new Manager(filename);
            break;
        case Employee::L4:
            //cout << "加载技术主管" << endl;
            pret = new CTO(filename);
            break;
        default:
            cout << "加载员工信息错误！" << endl;
            return NULL;
    }
    fclose(fp);
    return pret;
}

//获取员工人数
size_t Company::size(void)const{
    return Employee::getEmployeeCount();
}
//员工系统开始运行(循环)
void Company::run(void){
    while(1){
        //system("clear");
        printMenu();//打印选择菜单
        int choose=0;
        cin >> choose;
        switch(choose){
            case 1:
                addEmployee();//增
                break;
            case 2:
                deleteEmployee();//删
                break;
            case 3:
                updateEmployee();//改
                break;
            case 4:
                queryEmployee();//查
                break;
            case 5:
                paySalary();//结算工资
                break;
            case 0:
                cout << "系统退出..." << endl;
                sleep(1);
                exit(0);
            default:
                cout << "输入错误，请重试" << endl;
        }
    }
}
void Company::printMenu(void){
    cout << "*****************************" << endl;
    cout << "《欢迎进入企业员工管理系统》" << endl;
    cout << "<1> 添加员工" << endl;
    cout << "<2> 删除员工" << endl;
    cout << "<3> 修改员工信息" << endl;
    cout << "<4> 查询员工信息" << endl;
    cout << "<5> 结算工资" << endl;
    cout << "<0> 退出" << endl;
    cout << "*****************************" << endl;
}
void Company::addEmployee(void){
    string name;
    double salary = 0.0;
    double allow = 0.0;
    double bonus = 0.0;
    
    //cout << "添加员工" << endl;
    cout << "姓名:";
    cin >> name;

    cout << "工资:";
    cin >> salary;
   
    cout << "选择职位:<1>/<2>/<3>/<4>:" << endl;;
    cout << "<1> 添加普通员工" << endl;
    cout << "<2> 添加技术员" << endl;
    cout << "<3> 添加经理" << endl;
    cout << "<4> 添加技术主管" << endl;
    int type = 0;
    cin >> type;
    switch(type){
        case 1://创建普通员工
            empVector.push_back(new Employee(name,salary));
            break;
        case 2://创建技术员
            cout << "请输入研发津贴:";
            cin >> allow;
            empVector.push_back(new Technician(name,salary,allow));
            break;
        case 3://创建经理
            cout << "请输入绩效奖金:";
            cin >> bonus;
            empVector.push_back(new Manager(name,salary,bonus));
            break;
        case 4://创建技术主管
            cout << "请输入研发津贴:";
            cin >> allow;
            cout << "请输入绩效奖金:";
            cin >> bonus;
            empVector.push_back(new CTO(name,salary,allow,bonus)); 
            break;
        default:
            cout << "输入错误" << endl;
            break;
    }
}
//删除某个员工信息(将id对应文件删除)
void Company::deleteEmployee(void){
    cout << "删除员工" << endl;
    cout << "请输入员工工号:";
    int id = 0;
    cin >> id;
    //根据工号获取对应的员工文件
    char filename[20]={0};
    sprintf(filename,"%d",id);
    
    //如果对应文件不存在，则说明输入工号信息错误
    if(access(filename,F_OK)==-1){
        cout << "该员工不存在!" << endl;
        return;
    }
    else{
        cout << "确定删除吗? <1>确定/<2>取消" << endl;
        int flag = 0;
        cin >> flag;
        if(flag == 1){
            //遍历容器，找到对应的员工对象
            for(int i=0;i<empVector.size();i++){
                //*empVector[i].operator==(id)
                if(*empVector[i] == id){
                    //将员工对象从容器中删除
                    cout << "删除id==" << id << "的对象" << endl;
                    delete empVector[i];
                    empVector.erase(empVector.begin()+i);
                    break;
                }
            }
            //删除员工信息文件
            if(unlink(filename)==0){
                cout << "删除id= "<< id << "的文件" << endl;
            }
            else{
                cout << "删除失败!" << endl;
            }
        }
    }
}
//支持修改基本工资
void Company::updateEmployee(void){
    cout << "修改信息" << endl;
    cout << "请输入员工工号:";
    int id = 0;
    cin >> id;
    //根据工号获取对应的员工文件 
    char filename[20]={0};
    sprintf(filename,"%d",id);
    
    //如果对应文件不存在，则说明输入工号信息错误
    if(access(filename,F_OK)==-1){
        cout << "该员工不存在!" << endl;
        return;
    }
    //遍历容器，找到对应的员工对象
    for(int i=0;i<empVector.size();i++){
        if(*empVector[i] == id){
            cout << *empVector[i] << endl;
            cout << "请输入修改后的工资:";
            double salary=0.0;
            cin >> salary;
            empVector[i]->setSalary(salary);
            empVector[i]->saveInfo();
        }
    }
}
void Company::queryEmployee(void){
    cout << "查询信息:<1>全部信息/<2>个人信息" << endl;
    int choose=0;
    cin >> choose;
    switch(choose){
        case 1:
            queryAll();
            break;
        case 2:
            queryOne();
            break;
        default:
            cout << "输入错误!" << endl;
            return;
    }
}
void Company::queryAll(void){
    cout << "全部员工信息如下:" << endl;
    for(int i = 0;i<empVector.size();i++){
        empVector[i]->printInfo();
        cout << "=======================" << endl;
    }
}
void Company::queryOne(void){
    int id;
    while(1){
        int flag = 0;//标记是否找到对应的工号
        cout << "请输入员工的工号:";
        cin >> id;
        for(int i=0;i<empVector.size();i++){
            if(*empVector[i] == id){
                flag = 1;
                cout << "该员工信息如下:";
                empVector[i]->printInfo();
                cout << "==========================" << endl;
                break;
            }
        }
        if(flag == 0){
            cout << "要查询的员工不存在!" << endl;
        }

        cout << "继续查询按1，返回按2" << endl;
        int choose = 0;
        cin >> choose;
        if(choose == 1){
            continue;
        }
        else{
            break;
        }
    }
}
void Company::paySalary(void){
    cout << "结算工资:" << endl;
    cout << "请输入员工工号:";
    int id = 0;
    cin >> id;
    char filename[20]={0};
    sprintf(filename,"%d",id);
    if(access(filename,F_OK)==-1){
        cout << "该员工不存在!" << endl;
        return;
    }
    for(int i=0;i<empVector.size();i++){
        if(*empVector[i] == id){
            empVector[i]->printInfo();
            empVector[i]->calSalary();
            break;
        }
    }
}




