#include <iostream>
using namespace std;
class A{
public:
    //void func1(const A* this)
    void func1(void) const {
        cout << "常函数" << endl;
        //常函数里面不能调用非常函数!
        //func2();//error
    }
    //void func2(A* this)
    void func2(void) {
        cout << "非常函数" << endl;
    }
};
int main(void){
    A a;
    a.func1();//A::func1(&a),A*
    a.func2();//A::func2(&a),A*
    
    const A a2 = a;//a2看做是常对象
    a2.func1();//A::func1(&a2),const A*
    //a2.func2();//A::func2(&a2),const A*

    const A* pa = &a;//pa常指针也是"常对象"
    pa->func1();
    //pa->func2();

    const A& ra = a;//ra常引用也是"常对象"
    ra.func1();
    //ra.func2();

    return 0;
}






