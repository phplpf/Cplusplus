//单例模式:懒汉式(多线程)
//使用场景:单例对象使用频率低,耗内存多
//特点:以时间换空间
#include <iostream>
#include <pthread.h>
using namespace std;

class Singleton{
public:
    //3)提供单例对象的访问方法
    static Singleton& getInstance(void){
        pthread_mutex_lock(&mutex);
        if(s_instance == NULL){
            s_instance = new Singleton(123);
        }
        ++s_count;//s_count = s_count + 1;
        pthread_mutex_unlock(&mutex);
        return *s_instance;
    }
    //单例对象不用即销毁,什么时候销毁?
    //最后一个使用者不用时再销毁.
    void release(void){
        pthread_mutex_lock(&mutex);
        if(--s_count == 0){
            delete s_instance;
            s_instance = NULL;
        }
        pthread_mutex_unlock(&mutex);
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
    ~Singleton(void){
        cout << "单例对象被销毁了" << endl;
    }
    //2)使用静态成员变量表示单例对象
    static Singleton* s_instance;
    //计数:记录单例对象使用者个数
    static int s_count;
    static pthread_mutex_t mutex;
private:
    int m_data;
};
Singleton* Singleton::s_instance = NULL;
int Singleton::s_count = 0;
pthread_mutex_t Singleton::mutex = 
    PTHREAD_MUTEX_INITIALIZER;

int main(void){
    cout << "main开始执行" << endl;
    //++s_count:1,new
    Singleton& s1=Singleton::getInstance();
    //++s_count:2
    Singleton& s2=Singleton::getInstance();
    //++s_count:3
    Singleton& s3=Singleton::getInstance();
    
    s1.print();
    s1.release();//--s_count:2
    
    s2.print();
    s3.print();
    
    cout << "&s1=" << &s1 << endl;
    cout << "&s2=" << &s2 << endl;
    cout << "&s3=" << &s3 << endl;

    s2.release();//--s_count:1
    s3.release();//--s_count:0,delete

    return 0;
}









