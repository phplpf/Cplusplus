#include <iostream>
using namespace std;
class Integer{
public:
    Integer(int i=0):m_i(i){}
    void print(void)const{
        cout << m_i << endl;
    }
    //前++:成员函数形式
    Integer& operator++(void){
        ++m_i;
        return *this;
    }
    //前--:全局函数形式
    friend Integer& operator--(Integer& i){
        --i.m_i;
        return i;
    }
    //后++:成员函数形式
    const Integer operator++(int){
        Integer old = *this;
        ++*this;//++m_i;
        return old;
    }
    //后--:全局函数形式
    friend const Integer operator--(
            Integer& i,int){
        Integer old = i;
        --i;//--i.m_i;
        return old;
    }
private:
    int m_i;
};
int main(void){
    Integer i(100);
    Integer j = ++i;//i.operator++()
    i.print();//101
    j.print();//101
    j = ++++i;
    i.print();//103
    j.print();//103
    
    j = --i;//operator--(i)
    i.print();//102
    j.print();//102
    j = ----i;
    i.print();//100
    j.print();//100

    j = i++;//i.operator++(0/*哑元*/)
    i.print();//101
    j.print();//100

    j = i--;//operator--(i,0/*哑元*/)
    i.print();//100
    j.print();//101

    return 0;
}









