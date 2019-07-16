#include <iostream>
using namespace std;

int main(void){
    enum Color{RED=10,GREEN,BLUE,YELLOW};
    cout << RED << ',' << GREEN << ','
        << BLUE << ',' << YELLOW << endl;
    Color c;
    //c = BLUE;
    c = 12;//C:ok,C++:error
    cout << c << endl;//12
    return 0;
}
