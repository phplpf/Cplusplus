#include <iostream>
using namespace std;
class A{
public:
    void func(void){
        throw -1;
    }
    ~A(void){
        throw -2;
    }
};
int main(void){
    try{
        A a;
        a.func();//throw -1
    }//throw -2
    catch(int ex){
        cout << "捕获到异常:" << ex << endl;
    }
    return 0;
}








