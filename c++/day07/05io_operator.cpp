#include <iostream>
using namespace std;
class Complex{
public:
    Complex(int r,int i):m_r(r),m_i(i){}
    friend ostream& operator<<(
        ostream& os,const Complex& c){
        os << c.m_r << '+' << c.m_i << 'i';
        return os;
    }
    friend istream& operator>>(
        istream& is,Complex& c){
        cout << "输入实部:";
        is >> c.m_r;
        cout << "输入虚部:";
        is >> c.m_i;
        return is;
    }
private:
    int m_r;//实部
    int m_i;//虚部
};
int main(void){
    Complex c1(1,2);
    Complex c2(3,4);
    //operator<<(cout,c1)
    cout << c1 << endl;
    cout << c1 << ',' << c2 << endl;

    Complex c3(0,0);
    //operator>>(cin,c3)
    cin >> c3;
    cout << c3 << endl;

    return 0;
}






