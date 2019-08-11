#include <iostream>
#include <list>
using namespace std;
template<class T>
void print(const string& str, list<T>& l){
    cout << str << endl;
    typedef typename list<T>::iterator IT;
    for(IT it=l.begin(); it!=l.end(); ++it)
        cout << *it << ' ';
    cout << endl << "------------" << endl;
}
class CMP{
public:
    bool operator()(
            const int& a, const int&b)const{
        return a > b;
    }
};
int main(){
    list<int> ls;
    for(int i=0; i<5; i++)
        ls.push_back(10-i);
    for(int i=0; i<5; i++)
        ls.push_front(10+i);
    print("添加节点后:", ls);

    ls.unique();
    print("唯一化后:", ls);

//  ls.sort();
    CMP cmp;//比较器
    ls.sort(cmp);
    print("排序后:", ls);

    list<int> lst;//参数列表
    lst.push_back(1000);
    lst.push_back(2000);
    lst.push_back(3000);
    lst.push_back(4000);
//  ls.splice(++ls.begin(),lst);
//  ls.splice(ls.begin(),lst,lst.begin());
    
    ls.splice(ls.begin(),lst,
                ++lst.begin(),--lst.end());

    print("ls:", ls);
    print("lst:", lst);
    return 0;
}




