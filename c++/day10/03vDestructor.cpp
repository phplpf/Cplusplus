#include <iostream>
using namespace std;
class Base{
public:
    Base(void){
        cout << "积累动态资源分配" << endl;
    }
    virtual ~Base(void){
        cout << "基类动态资源清理" << endl;
    }

};

class Derived:public Base{
public:
    Derived(void){
        cout << "子类动态资源分配" << endl;
    }
    ~Derived(void){ //自动变成虚函数
        cout << "子类动态资源清理" << endl;
    }

};

int main(void){
    Base *pb = new Derived;
    //1)pb->析构函数
    //2)释放内存
    delete pb;
    return 0;
}


