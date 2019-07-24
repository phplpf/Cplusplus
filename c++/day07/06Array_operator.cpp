#include <iostream>
using namespace std;
//容器:能够保存若干个int数据
class Array{
public:
    Array(size_t size){
        m_arr = new int[size];
    }
    ~Array(void){
        delete[] m_arr;
        m_arr = NULL;
    }
    //适用左值对象,返回左值
    int& operator[](size_t i){
        return m_arr[i];
    }
    //适用常对象,返回右值
    const int& operator[](size_t i)const{
        return m_arr[i];
    }
private:
    int* m_arr;
};
int main(void){
    Array arr(10);
    arr[0] = 100;//arr.operator[](0) = 100
    const Array& carr = arr;
    //carr[0] = 100;//应该error
    cout << carr[0] << endl;//ok
    return 0;
}




