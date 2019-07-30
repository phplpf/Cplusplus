#include <iostream>
using namespace std;
class FileError{};
class MemoryError{};
//函数声明
void func(void)throw(MemoryError,FileError);
//函数定义
void func(void)throw(FileError,MemoryError){
    throw FileError();
    //throw MemoryError();
    //throw -1;
}
int main(void){
    try{
        func();
    }
    catch(FileError& ex){
        cout << "针对文件错误处理" << endl;
    }
    catch(MemoryError& ex){
        cout << "针对内存错误处理" << endl;
    }
    catch(int ex){
        cout << "针对int错误处理" << endl;
    }
    return 0;
}



