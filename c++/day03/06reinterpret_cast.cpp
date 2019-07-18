#include <iostream>
using namespace std;

int main(void){
    //"\000"->'\0'
    char buf[] = 
        "0001\00012345678\000123456";
    struct Http{
        char type[5];
        char id[9];
        char passwd[7];
    };
    Http* ph = 
        reinterpret_cast<Http*>(buf);
    cout << ph->type << endl;//0001
    cout << ph->id << endl;//12345678
    cout << ph->passwd << endl;//123456

    return 0;
}



