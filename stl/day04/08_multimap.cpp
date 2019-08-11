#include <iostream>
#include <map>
using namespace std;

int main(){
    multimap<string, int> m;
    m.insert(make_pair("张飞",80));
    m.insert(make_pair("赵云",70));
    m.insert(make_pair("关羽",60));
    m.insert(make_pair("张飞",50));
    m.insert(make_pair("赵云",40));
    m.insert(make_pair("关羽",30));

    typedef multimap<string,int>::iterator IT;
    for(IT it=m.begin(); it!=m.end(); ++it){
        cout<<(*it).first<<":"<<(*it).second<<' ';
    }
    cout << endl;
    return 0;
}







