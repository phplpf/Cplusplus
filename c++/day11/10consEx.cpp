#include <iostream>
using namespace std;
class A{
public:
    A(void){
        cout << "动态资源分配" << endl;
        if("error"){
            cout << "动态资源释放" << endl;
            throw -1;
        }
        cout << "构造函数正常结束" << endl;
    }
    ~A(void){
        cout << "动态资源释放" << endl;
    }
};
int main(void){
    try{
        A a;
    }
    catch(int ex){
        cout << "捕获到异常:" << ex << endl;
    }
    return 0;
}






