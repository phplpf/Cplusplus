#include <iostream>
using namespace std;
class ErrorBase{};
class ErrorDerived:public ErrorBase{};
void func(void){
    if("error"){
        throw ErrorBase();
        //throw ErrorDerived();
    }
}
int main(void){
    try{
        func();
    }
    catch(ErrorDerived& ex){
        cout << "针对子类异常处理" << endl;
    }
    catch(ErrorBase& ex){
        cout << "针对基类异常处理" << endl;
    }
    return 0;
}


