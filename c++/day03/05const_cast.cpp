#include <iostream>
using namespace std;
int main(void){
    /* volatile修饰的变量表示易变的,告诉
     * 编译器每次在使用该变量时都要从内存
     * 中重新读取,不能使用之前保存在寄存
     * 器中的副本,防止编译器优化引发的错
     * 误结果 */
    volatile const int ci = 10;
    int* pci = const_cast<int*>(&ci);
    *pci = 20;
    cout << "ci=" << ci << endl;//20
    cout << "*pci=" << *pci << endl;//20
    cout << "&ci=" << (void*)&ci << endl;
    cout << "pci=" << pci << endl;

    return 0;
}
