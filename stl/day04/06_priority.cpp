#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;
class CMP{
public:
    bool operator()(
            const int& a,const int& b)const{
        return a > b;
    }
};
int main(){
    priority_queue<int,vector<int>,CMP> pq;
    pq.push(3);
    pq.push(9);
    pq.push(4);
    pq.push(8);
    pq.push(2);
    pq.push(7);
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}



