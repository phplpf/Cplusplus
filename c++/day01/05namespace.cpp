#include <iostream>
using namespace std;
namespace ns1{
    int num = 100;
}
namespace ns2{
    int num = 200;
}
//int num = 300;
namespace{//无名名字空间
    int num = 300;
}
int main(void){
    cout << num << endl;//300
    using ns1::num;//名字空间声明
    cout << num << endl;//100
    cout << ns2::num << endl;//200
    cout << ::num << endl;//300

    return 0;
}



