#include <iostream>
using namespace std;

class Integer{
public:
    Integer(int i=0):m_pi(new int(i)){
        cout << "Integer构造函数" << endl;
    }
    void print(void)const{
        cout << *m_pi << endl;
    }
    ~Integer(void){
        cout << "Integer析构函数:"<< m_pi <<endl;
        delete m_pi;
        m_pi = NULL;
    }
    //缺省拷贝构造函数(浅拷贝)
    /*Integer(const Integer& that){
        cout << "缺省拷贝构造函数" << endl;
        m_pi = that.m_pi;
    }*/
    //自定义拷贝构造函数(深拷贝)
    Integer(const Integer& that){
        cout << "自定义拷贝构造函数" << endl;
        m_pi = new int;
        *m_pi = *that.m_pi;
    }
    //缺省拷贝赋值函数(浅拷贝)
    //i2=i3 ==> i2.operator=(i3)
    /*Integer& operator=(const Integer& that){
        cout << "缺省拷贝赋值函数" << endl;
        if(&that != this){//防止自赋值
            m_pi = that.m_pi;
        }
        return *this;//返回自引用
    }*/
    //自定义拷贝赋值函数(深拷贝)
    Integer& operator=(const Integer& that){
        cout << "自定义拷贝赋值函数" << endl;
        if(&that != this){//防止自赋值
            delete m_pi;//释放旧内存
            m_pi = new int;//分配新内存
            *m_pi = *that.m_pi;//拷贝新数据
        }
        return *this;//返回自引用
    }
private:
    int* m_pi;
};
int main(void){
    Integer i1(100);
    i1.print();
    Integer i2(i1);//拷贝构造
    i2.print();//100

    Integer i3(200);
    //i2.operator=(i3);
    i2 = i3;//拷贝赋值
    i2.print();//200
    return 0;
}




