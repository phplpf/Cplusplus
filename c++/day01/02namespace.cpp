#include <iostream>
namespace ns1{
    void func(void){
        std::cout << "ns1的func" << 
            std::endl;
    }
}
namespace ns2{
    void func(void){
        std::cout << "ns2的func" <<
            std::endl;
    }
}
int main(void)
{
    //名字空间成员不能直接访问
    //可以通过如下“空间名::”来访问
    ns1::func();
    ns2::func();
    return 0;
}





