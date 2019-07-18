#include <iostream>
using namespace std;
int main(void){
    //动态分配数组
    int* parr = new int[10];
    for(int i=0;i<10;i++){
        //*(parr+i)
        parr[i] = i+1;
        cout << parr[i] << ' ';
    }
    cout << endl;
    delete[] parr;
    parr = NULL;

    //new数组直接初始化(C++11)
    int* parr2 = 
       new int[10]{1,2,3,4,5,6,7,8,9,10};
    for(int i=0;i<10;i++){
        cout << parr2[i] << ' ';
    }
    cout << endl;
    delete[] parr2;
    parr2 = NULL;

    return 0;
}




