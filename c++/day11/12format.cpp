#include <iostream>
#include <iomanip>//流控制符
using namespace std;
int main(void){
    int num = 12345;
#if 0
    //格式化函数
    cout << '[';
    cout.width(10);//设置域宽
    cout.fill('$');//用"$"填充空白位置
    cout.setf(ios::showpos);//显示正号
    //设置数据对齐方式:数据右对齐,符号左对齐
    cout.setf(ios::internal);
    cout << num << ']' << endl;
#endif
    //流控制符
    cout << '[' << setw(10) << setfill('$')
        << showpos << internal << num <<
        ']' << endl;

    return 0;
}




