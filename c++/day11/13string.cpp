#include <iostream>
#include <sstream>
using namespace std;

int main(void){
    istringstream iss;
    iss.str("123 4.56 hello");
    int i;
    double d;
    string s;
    iss >> i >> d >> s;
    cout << i << ","<< d << ","<< s << endl;

    ostringstream oss;
    int i2 = 321;
    double d2 = 6.54;
    string s2 = "world";
    oss << i2 << ' ' << d2 << ' ' << s2;
    cout << oss.str() << endl;

    return 0;
}




