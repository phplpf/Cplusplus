#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

template<class T>void print(
         const string& str,deque<T>& d){
    
    cout << str << endl;
    typedef typename deque<T>::iterator IT;
    for(IT it=d.begin();it!=d.end();++it)
        cout << *it << ' ';
    cout << endl << "-----------" << endl;
}
int main(){
    deque<int> di;
    for(int i=0; i<5; i++)
        di.push_front(10+i);
    for(int i=0; i<5; i++)
        di.push_back(100+i);
    print("添加节点后:",di);
    di.pop_front();
    di.pop_back();
    print("删除头尾节点后:", di);

    di.insert(di.begin(),500);
    print("迭代器指向位置添加节点后:",di);

    di.erase(--di.end());
    print("删除迭代器指向的节点后:", di);

    typedef deque<int>::iterator IT;
    IT it=++di.begin();
    *it = 1000;
    print("更改迭代器指向的节点后:",di);

    IT fit=find(di.begin(),di.end(),1000);
    if(fit!=di.end())
        di.erase(fit);
    print("找到1000并删除后:", di);

    sort(di.begin(),di.end());//"<"
    print("排序后:",di);
    return 0;
}




