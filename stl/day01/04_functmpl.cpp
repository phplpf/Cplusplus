#include <iostream>
using namespace std;
class Integer{
public:
    Integer(const int& i):m_i(i){}
    bool operator>(const Integer& that)const
    {
        return m_i > that.m_i;
    }
private:
    int m_i;
    friend ostream& operator<<(
        ostream& os, const Integer& that);
};
ostream& operator<<(
        ostream& os,const Integer& that){
    return os << that.m_i;
}
//函数模板
template<class T>T Max(T x, T y){
    return x > y ? x : y;
}
//int Max(int x, int y){...}
//double Max(double x, double y){...}
//string Max(string x, string y){...}
//Integer Max(Integer x, Integer y){
//  return x > y ? x : y;
//}
int main(){
    int nx=10, ny=20;
    cout << Max<int>(nx,ny) << endl;
            //Max(nx,ny)
    double dx=12.3, dy=45.6;
    cout << Max<double>(dx,dy) << endl;
            //Max(dx,dy)
    string sx="world", sy="hello";
    cout << Max<string>(sx,sy) << endl;

    Integer ix=100, iy=200;
    cout << Max<Integer>(ix,iy) << endl;
    return 0;
}




