#include <iostream>
#include <cstdio>
using namespace std;
class FileError{
public:
    FileError(const string& file,int line)
        :m_file(file),m_line(line){
        cout << "出错位置:" << m_file << 
            "," << m_line << endl;
    }
    void func(){
        cout << "针对文件错误处理" << endl;
    }
private:
    string m_file;
    int m_line;
};

class A{
public:
    A(void){
        cout << "A的构造函数" << endl;
    }
    ~A(void){
        cout << "A的析构函数" << endl;
    }
};
int func3(void){
    A a;
    FILE* fp = fopen("xx.txt","r");
    if(fp == NULL){
        //__FILE__:当前文件名
        //__LINE__:当前行号
        throw FileError(__FILE__,__LINE__);
        throw -1;//抛出异常
    }
    cout << "func3正常运行" << endl;
    fclose(fp);
    return 0;
}
int func2(void){
    A a;
    func3();
    cout << "func2正常运行" << endl;
    return 0;
}
int func1(){
    A a;
    func2();
    cout << "func1正常运行" << endl;
    return 0;
}
int main(void){
    try{//异常检测
        func1();
        cout << "main正常运行" << endl;
    }
    catch(int ex){//捕获和处理异常
        if(ex == -1){
            cout << "文件打开失败" << endl;
            return -1;
        }
    }
    catch(FileError& ex){
        //cout << "文件打开失败!" << endl;
        ex.func();
        return -1;
    }

    return 0;
}













