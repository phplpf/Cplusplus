#include <iostream>
#include <map>
using namespace std;
//候选人的类
class Candidate{
public:
    Candidate(const string& name=""):
                m_name(name),m_vote(0){}
    string GetName(){
        return m_name;
    }
    int GetVote(){
        return m_vote;
    }
    void SetVote(){
        ++m_vote;
    }
private:
    string m_name;
    int m_vote;
};
void print(map<char,Candidate>& m){
    typedef map<char,Candidate>::iterator IT;
    for(IT it=m.begin(); it!=m.end(); ++it){
        cout << "(" << (*it).first << ")"
             << (*it).second.GetName() << ' ';
    }
    cout << endl;
}
int main(){
    map<char,Candidate> m;
    m.insert(
        pair<char,Candidate>('A',Candidate("张飞")));
    m.insert(make_pair('B',Candidate("赵云")));
    m['C'] = Candidate("关羽");
    m['D'] = Candidate("马超");
    m['E'] = Candidate("黄忠");
    typedef map<char,Candidate>::iterator IT;
    for(int i=0; i<10; i++){
        print(m);
        char ch;
        cin >> ch;
        IT fit = m.find(ch);
        if(fit==m.end()){
            cout << "废票" << endl;
            continue;
        }
        (*fit).second.SetVote();
    }
    IT win = m.begin();//暂定胜利者
    for(IT it=m.begin(); it!=m.end(); ++it){
        cout << (*it).second.GetName() << ":"
             << (*it).second.GetVote() << endl;
        if((*win).second.GetVote()<
                    (*it).second.GetVote()){
            win =  it;
        }
    }
    cout << "恭喜:" << (*win).second.GetName()
         << "成功当选****" << endl;
    return 0;
}







