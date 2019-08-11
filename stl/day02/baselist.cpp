#include <iostream>
#include <stdexcept>
using namespace std;

template<class T>class list{
public:
//
//缺省构造
//
    list():m_head(NULL),m_tail(NULL){}
//
//拷贝构造
//
    list(const list& that):m_head(NULL),
            m_tail(NULL){
        for(node* pnode=that.m_head;
                pnode; pnode=pnode->m_next){
            push_back(pnode->m_data);
        }
    }
//
//析构
//
    ~list(){
        clear();
    }
//
//链表判空
//
    bool empty(){
        return m_head==NULL && m_tail==NULL;
    }
//
//添加头节点
//
    void push_front(const T& data){
        m_head = new node(NULL,data,m_head);
        if(m_head->m_next)
            m_head->m_next->m_prev = m_head;
        else
            m_tail = m_head;
    }
//
//删除头节点
//
    void pop_front(){
        if(empty())
            return;
        node* pnode = m_head->m_next;
        delete m_head;
        if(pnode)
            pnode->m_prev = NULL;
        else
            m_tail = NULL;
        m_head = pnode;
    }
//
//获取头节点数据
//
    T& front(){
        if(empty())
            throw underflow_error("null");
        return m_head->m_data;
    }
    const T& front()const{
        return 
         const_cast<list*>(this)->front();
    }
//
//添加尾节点
//
    void push_back(const T& data){
        m_tail = new node(m_tail,data,NULL);
        if(m_tail->m_prev)
            m_tail->m_prev->m_next = m_tail;
        else
            m_head = m_tail;
    }
//
//删除尾节点
//
    void pop_back(){
        if(empty())
            return;
        node* pnode = m_tail->m_prev;
        delete m_tail;
        if(pnode)
            pnode->m_next = NULL;
        else
            m_head = NULL;
        m_tail = pnode;    
    }
//
//获取尾节点数据
//
    T& back(){
        if(empty())
            throw underflow_error("null");
        return m_tail->m_data;
    }
    const T& back()const{
        return 
            const_cast<list*>(this)->back();
    }
//
//清空链表
//
    void clear(){
        while(!empty())
            pop_front();
    }
//
//获取节点个数(大小)
//
    size_t size(){
        size_t i=0;
        for(node*pnode=m_head; pnode;
                    pnode=pnode->m_next){
            i++;
        }
        return i;
    }
private:
//
//节点类
//
    class node{
    public:
        node(node*prev,
            const T& data, node*next):
            m_prev(prev),m_data(data),
            m_next(next){}
        node* m_prev;//前指针
        T m_data;
        node* m_next;//后指针
    };
    node* m_head;//头
    node* m_tail;//尾
    friend ostream& operator<<(ostream& os,
                    const list& l){
        for(node*pnode=l.m_head; pnode;
                pnode=pnode->m_next){
            os << pnode->m_data << ' ';
        }
        return os;
    }
};

int main(){
    list<int> ls;
    for(int i=0; i<5; i++)
        ls.push_front(10+i);
    for(int i=0; i<5; i++)
        ls.push_back(100+i);
    cout << ls << endl;

    ls.pop_back();
    ls.pop_front();
    cout << ls << endl;
    return 0;
}






