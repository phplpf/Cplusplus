#include <iostream>
using namespace std;
class A{
public:
    int m_public;//公有成员
protected:
    int m_protected;//保护成员
private:
    int m_private;//私有成员
};
class B:public A{//公有继承的子类
};
class C:protected A{//保护继承的子类
};
class D:private A{//私有继承的子类
};
class X:public B{
    void func(void){
        m_public = 10;
        m_protected = 10;
        //m_private = 10;
    }
};
class Y:public C{
    void func(void){
        m_public = 10;
        m_protected = 10;
        //m_private = 10;
    }
};
class Z:public D{
    void func(void){
        //m_public = 10;
        //m_protected = 10;
        //m_private = 10;
    }
};
int main(void){
    B b;
    b.m_public = 10;
    //b.m_protected = 10;
    //b.m_private = 10;
    
    C c;
    //c.m_public = 10;
    //c.m_protected = 10;
    //c.m_private = 10;
    
    D d;
    //d.m_public = 10;
    //d.m_protected = 10;
    //d.m_private = 10;
    
    return 0;
}






