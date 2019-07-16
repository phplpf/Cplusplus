#include <iostream>
//标准名字空间指令,以后可以省略"std::"
using namespace std;
namespace ns1{
    void func(void){
        cout << "ns1的func" << endl;
    }
}
namespace ns2{
    void func(void){
        cout << "ns2的func" << endl;
    }
}
int main(void){
    using namespace ns1;//名字空间指令
    func();//ns1::func
    using namespace ns2;//名字空间指令
    //func();//歧义错误(ambiguous)
    ns2::func();
    return 0;
}





