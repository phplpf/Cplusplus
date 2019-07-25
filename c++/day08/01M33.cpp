#include <iostream>
using namespace std;
class M33{
public:
    M33(void){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                m_a[i][j] = 0;
    }
    M33(int a[][3]){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                m_a[i][j] = a[i][j];
    }
    //<<
    friend ostream& operator<<(
            ostream& os,const M33& m){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                os << m.m_a[i][j] << '\t';
            }
            cout << endl;
        }
        return os;
    }
    //+ - *
    const M33 operator+(const M33& m)const{
        int a[3][3] = {0};
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                a[i][j] = 
                    m_a[i][j] + m.m_a[i][j];
        M33 res(a);
        return res;
    }
    const M33 operator-(const M33& m)const{
        int a[3][3] = {0};
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                a[i][j] = 
                    m_a[i][j] - m.m_a[i][j];
        M33 res(a);
        return res;
    }
    const M33 operator*(const M33& m)const{
        int a[3][3] = {0};
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                a[i][j] += 
                    m_a[i][k] * m.m_a[k][j];
        M33 res(a);
        return res;
    }
    //+= -= *=
    //m1 += m2 ==> m1.operator+=(m2)
    M33& operator+=(const M33& m){
        //m1 = m1+m2
        *this = *this + m;
        return *this;
    }
    M33& operator-=(const M33& m){
        *this = *this - m;
        return *this;
    }
    M33& operator*=(const M33& m){
        *this = *this * m;
        return *this;
    }
    //-(负)
    const M33 operator-(void)const{
        M33 m;
        return (m - *this);
    }
    //前++,--
    M33& operator++(void){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                ++m_a[i][j];
        return *this;
    }
    M33& operator--(void){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                --m_a[i][j];
        return *this;
    }
    //后++,--
    const M33 operator++(int){
        M33 old = *this;
        ++*this;
        return old;
    }
    const M33 operator--(int){
        M33 old = *this;
        --*this;
        return old;
    }
private:
    int m_a[3][3];
};
int main(void){
    int a1[3][3]={1,2,3,4,5,6,7,8,9};
    int a2[3][3]={9,8,7,6,5,4,3,2,1};
    M33 m1(a1);
    M33 m2(a2);
    cout << m1 << endl;
    cout << m2 << endl;

    cout << "m1+m2:" << endl;
    cout << m1+m2 << endl;
    cout << "m1-m2:" << endl;
    cout << m1-m2 << endl;
    cout << "m1*m2:" << endl;
    cout << m1*m2 << endl;
    
    cout << "m1+=m2:" << endl;
    cout << (m1+=m2) << endl;
    cout << m1 << endl;
    cout << "m1-=m2:" << endl;
    cout << (m1-=m2) << endl;
    cout << m1 << endl;
    cout << "m1*=m2:" << endl;
    cout << (m1*=m2) << endl;
    cout << m1 << endl;

    cout << "-m2:" << endl;
    cout << -m2 << endl;

    cout << "++m2:" << endl;
    cout << ++m2 << endl;
    cout << m2 << endl;
    cout << "--m2:" << endl;
    cout << --m2 << endl;
    cout << m2 << endl;

    cout << "m2++:" << endl;
    cout << m2++ << endl;
    cout << m2 << endl;
    cout << "m2--:" << endl;
    cout << m2-- << endl;
    return 0;
}










