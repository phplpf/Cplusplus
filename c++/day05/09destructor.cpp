#include <iostream>
using namespace std;
class Integer{
public:
    Integer(int i=0):m_pi(new int(i)){
        //m_pi = new int(i);
        cout << "Integer构造函数" << endl;
    }
    void print(void) const {
        cout << *m_pi << endl;
    }
    ~Integer(void){
        cout << "Integer析构函数" << endl;
        delete m_pi;
    }
private:
    int* m_pi;
};
int main(void){
    if(1){
        Integer i(123);
        i.print();//123
        cout << "test1" << endl;
        Integer* pi = new Integer(321);
        pi->print();//321
        delete pi;//->析构函数
        cout << "test3" << endl;
    }//->析构函数
    cout << "test2" << endl;
    return 0;
}






