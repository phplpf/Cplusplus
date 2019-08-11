#include <iostream>
#include <vector>
#include <algorithm> //find / sort
using namespace std;

class Student{
public:
    Student(const string& name="",
                const int& age=0):
                m_name(name),m_age(age){}
    bool operator==(
            const Student& that)const{
        return m_name==that.m_name &&
                m_age==that.m_age;
    }
    bool operator<(const Student& that)const
    {
        return m_age > that.m_age;
    }
    friend ostream& operator<<(
            ostream& os, const Student& s){
        return os<<s.m_name<<":"<<s.m_age;
    }
private:
    string m_name;
    int m_age;
};

template<class T>void print(
        const string& str, vector<T>& v){

    cout << str << endl;
    typedef typename vector<T>::iterator IT;
    for(IT it=v.begin(); it!=v.end(); ++it)
        cout << *it << ' ';
    cout << endl << "-------------" << endl;
}
class CMP{
public:
    bool operator()(
            const int& a, const int&b)const{
        return a > b;
    }
};
int main(){
    vector<Student> vs;
    vs.push_back(Student("张飞",22));
    vs.push_back(Student("赵云",20));
    vs.push_back(Student("关羽",25));
    vs.push_back(Student("马超",28));
    vs.push_back(Student("黄忠",44));
    print("添加节点后:", vs);
    vs.insert(
            vs.begin(),Student("杨健",45));
    print("迭代器指向位置添加节点后:",vs);
    vs.erase(--vs.end());
    print("删除迭代器指向的节点后:",vs);

    typedef vector<Student>::iterator IT;
    IT it = --vs.end();
    *it = Student("王建立",44);
    print("更改迭代器指向的节点后:",vs);

    IT fit = find(vs.begin(),vs.end(),//==
                    Student("赵云",20));
    if(fit!=vs.end())
        vs.erase(fit);
    print("找到赵云并删除后:", vs);

    sort(vs.begin(),vs.end());//"<"
    print("排序后:",vs);
/*
    vector<int> vi;
    for(int i=0; i<10; i++)
        vi.push_back(10-i);
    print("添加节点后:", vi);

    vi.insert(++vi.begin(),500);
    print("在迭代器指向位置添加节点后:",vi);

    vi.erase(--vi.end());
    print("删除迭代器指向的节点后:",vi);

    typedef vector<int>::iterator IT;
    IT it = vi.begin();
    *it = 1;
    print("更改迭代器指向的节点后:", vi);

    IT fit=find(vi.begin(),vi.end(),5);//==
    if(fit!=vi.end())
        vi.erase(fit);
    print("找到元素5并删除后:", vi);

//  sort(vi.begin(),vi.end());//"<"
    CMP cmp;
    sort(vi.begin(),vi.end(),cmp);
    print("排序后:", vi);*/
    return 0;
}





