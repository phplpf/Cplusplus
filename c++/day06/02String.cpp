#include <iostream>
#include <cstring>
using namespace std;
class String{
public:
    //构造函数
    String(const char* str){
        m_str = new char[strlen(str)+1];
        strcpy(m_str,str);
    }
    //析构函数
    ~String(void){
        cout << "析构函数:" << 
            (void*)m_str << endl;
        delete[] m_str;
        m_str = NULL;
    }
    //拷贝构造
    String(const String& that){
        m_str = new char[strlen(that.m_str)+1];
        strcpy(m_str,that.m_str);
    }
    //拷贝赋值
    String& operator=(const String& that){
        if(&that != this){
            delete[] m_str;
            m_str = new char[
                strlen(that.m_str)+1];
            strcpy(m_str,that.m_str);
            /*String tmp(that);
            swap(m_str,tmp.m_str);*/
        }
        return *this;
    }
    void print(void)const{
        cout << m_str << endl;
    }
private:
    char* m_str;
};
int main(void){
    String s1 = "hello world";
    s1.print();
    String s2 = s1;//拷贝构造
    s2.print();
    String s3 = "学习C++很开心!";
    s2 = s3;//拷贝赋值
    s2.print();

    return 0;
}


