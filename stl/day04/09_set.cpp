#include <iostream>
#include <set>
using namespace std;

int main(){//IT fit = s.find('a');
    set<char> s;
    s.insert('a');
    s.insert('b');
    s.insert('c');
    s.insert('a');
    s.insert('b');
    s.insert('c');
    cout << "节点个数:" << s.size() << endl;
    typedef set<char>::iterator IT;
    for(IT it=s.begin(); it!=s.end(); ++it)
        cout << *it << ' ';
    cout << endl;
    return 0;
}






