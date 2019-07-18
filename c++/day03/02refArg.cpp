#include <iostream>
using namespace std;
struct Teacher{
    char name[100];
    int age;
    double salary;
};
void print(const Teacher& t){
    cout << t.name << ',' << t.age/*++*/ 
        << ',' << t.salary << endl;
}
int main(void){
    const Teacher wangjl
        = {"王建立",45,800.5};
    print(wangjl);
    print(wangjl);
    return 0;
}




