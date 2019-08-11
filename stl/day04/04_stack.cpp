#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>
using namespace std;
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    while(!s.empty()){
        cout << s.top() << endl;//读
        s.pop();//取
    }
    return 0;
}



