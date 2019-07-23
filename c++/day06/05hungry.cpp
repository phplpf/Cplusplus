//单例模式:饿汉式
//使用场景:使用频率高,耗内存少
//特点:以空间换时间
#include <iostream>
using namespace std;

class Singleton{
public:
    //3)提供单例对象的访问方法
    static Singleton& getInstance(void){
        return s_instance;
    }
    void print(void)const{
        cout << m_data << endl;
    }
private:
    //1)私有化构造函数
    Singleton(int data = 0):m_data(data){
        cout << "单例对象被创建了" << endl;
    }
    Singleton(const Singleton&);
    //2)使用静态成员变量表示单例对象
    static Singleton s_instance;
private:
    int m_data;
};
Singleton Singleton::s_instance(123);
int main(void){
    cout << "main开始执行" << endl;
    Singleton& s1=Singleton::getInstance();
    Singleton& s2=Singleton::getInstance();
    Singleton& s3=Singleton::getInstance();
    
    s1.print();
    s2.print();
    s3.print();
    
    cout << "&s1=" << &s1 << endl;
    cout << "&s2=" << &s2 << endl;
    cout << "&s3=" << &s3 << endl;

    //Singleton s4(321);
    //Singleton s4 = s1;
    //Singleton* ps4 = new Singleton(321);

    return 0;
}









