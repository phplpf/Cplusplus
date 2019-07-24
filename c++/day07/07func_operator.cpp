#include <iostream>
using namespace std;
class Func{
public:
    int operator()(int i,int j){
        return i * j;
    }
    int operator()(int i){
        return i * i;
    }
};
int main(void){
    Func func;
    //func.operator()(10,20)
    cout << func(10,20) << endl;//200
    //func.operator()(20)
    cout << func(20) << endl;//400
    return 0;
}



