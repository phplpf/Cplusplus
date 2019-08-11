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
public:
//
//非常迭代类
//
    class iterator{
    public:
        iterator(node*start=NULL,
            node*cur=NULL,node*end=NULL):
            m_start(start),m_cur(cur),
            m_end(end){}
        T& operator*(){
            if(m_cur==NULL)
              throw underflow_error("null");
            return m_cur->m_data;
        }
        iterator& operator++(){
            if(m_cur==NULL)
                m_cur = m_start;
            else
                m_cur = m_cur->m_next;
            return *this;
        }
        iterator& operator--(){
            if(m_cur==NULL)
                m_cur = m_end;
            else
                m_cur = m_cur->m_prev;
            return *this;
        }
        bool operator==(
                const iterator& that)const{
            return m_start==that.m_start &&
                   m_cur==that.m_cur && 
                   m_end==that.m_end;
        }
        bool operator!=(
                const iterator& that)const{
            return !(*this==that);
        }
    private:
        node* m_start;//开始指向
        node* m_cur;//当前指向
        node* m_end;//终止指向
        friend class list;
    };
//
//获取起始迭代器(遍历)
//
    iterator begin(){
      return iterator(m_head,m_head,m_tail);
    }
//
//获取终止迭代器(结束标志)
//
    iterator end(){
        return iterator(m_head,NULL,m_tail);
    }
//
//在迭代器指向的位置添加节点
//
    iterator insert(const iterator& loc,
                        const T& data){
        if(loc==end()){
            push_back(data);
            return iterator(
                    m_head,m_tail,m_tail);
        }else{
            node* pnode = new node(loc.m_cur->m_prev,
                            data, loc.m_cur);
            if(pnode->m_prev)
                pnode->m_prev->m_next = pnode;
            else
                m_head = pnode;            
            pnode->m_next->m_prev = pnode;
            return iterator(m_head,pnode,m_tail);
        }
    }
//
//删除迭代器指向的节点
//
    iterator erase(const iterator& loc){
        if(loc==end())
            throw underflow_error("null node");
        node* pdel = loc.m_cur;
        node* pnext = pdel->m_next;
        if(pdel->m_prev)
            pdel->m_prev->m_next = pdel->m_next;
        else
            m_head = pdel->m_next;
        if(pdel->m_next)
            pdel->m_next->m_prev = pdel->m_prev;
        else
            m_tail = pdel->m_prev;
        delete pdel;
        return iterator(m_head,pnext,m_tail);
    }
    //
    //常迭代类
    //
    class const_iterator{
    public:
        const_iterator(const iterator& it):
                m_it(it){}
        const T& operator*(){
            return *m_it;
        }
        const_iterator& operator++(){
            ++m_it;
            return *this;
        }
        const_iterator& operator--(){
            --m_it;
            return *this;
        }
        bool operator==(
                const const_iterator& that)const{
            return m_it==that.m_it;
        }
        bool operator!=(
                const const_iterator& that)const{
            return !(*this==that);
        }
    private:
        iterator m_it;
    };
//
//获取常起始迭代器
//
    const_iterator begin()const{
        return iterator(m_head,m_head,m_tail);
    }
//
//获取常终止迭代器
//
    const_iterator end()const{
        return iterator(m_head,NULL,m_tail);
    }
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
//
//匹配查找("==")
//
template<class IT,class T>IT find(
        const IT& begin, const IT& end, const T& data){
    for(IT it=begin; it!=end; ++it){
        if(*it==data)
            return it;
    }    
    return end;
}
//利用"<"实现快速排序
template<class IT>void sort(
            const IT& begin, const IT& end){
    IT p = begin;
    IT last = end;
    --last;
    for(IT i=begin, j=last; i!=j; ){
        while(i!=p && *i<*p)
            ++i;
        if(i!=p){
            swap(*i,*p);
            p = i;
        }
        while(j!=p && *p<*j)
            --j;
        if(j!=p){
            swap(*p,*j);
            p = j;
        }
    }
    IT it=begin;
    ++it;
    if(p!=begin && p!=it)
        sort(begin,p);
    it=p;
    ++it;
    if(it!=end && it!=last)
        sort(it,end);
}
//利用"比较器"实现快速排序
template<class IT,class CMP>void sort(
            const IT& begin, const IT& end,CMP cmp){
    IT p = begin;
    IT last = end;
    --last;
    for(IT i=begin, j=last; i!=j; ){
        while(i!=p && cmp(*i,*p))//*i<*p)
            ++i;
        if(i!=p){
            swap(*i,*p);
            p = i;
        }
        while(j!=p && cmp(*p,*j))//*p<*j)
            --j;
        if(j!=p){
            swap(*p,*j);
            p = j;
        }
    }
    IT it=begin;
    ++it;
    if(p!=begin && p!=it)
        sort(begin,p,cmp);
    it=p;
    ++it;
    if(it!=end && it!=last)
        sort(it,end,cmp);
}
//以上代码是在模拟STL模板库
//--------------------------
//以下代码是在模拟"傻瓜"用户
void print(const string& str, list<int>& l){
    cout << str << endl;
    typedef list<int>::iterator IT;
    for(IT it=l.begin(); it!=l.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl << "--------------"<<endl;
}
//
//比较类
//
class ZJW{
public:
    bool operator()(const int& a, const int& b)const{
        return a > b;
    }
};
int main(){
    list<int> ls;
    for(int i=0; i<5; i++)
        ls.push_front(10+i);
    for(int i=0; i<5; i++)
        ls.push_back(100+i);
    print("添加节点后:", ls);

    ls.pop_back();
    ls.pop_front();
    print("删除头尾节点后:", ls);

    ls.insert(++ls.begin(),2000);//增
    print("在迭代器指向的位置添加节点后:", ls);

    ls.erase(--ls.end());//删
    print("删除迭代器指向的节点后:", ls);

    typedef list<int>::iterator IT;
    IT it = ls.begin();
    *it = 125;          //改
    print("更改迭代器指向的节点后:", ls);
                   
    IT fit = find(ls.begin(),ls.end(),125);
    if(fit != ls.end())
        ls.erase(fit);
    print("找到125并删除后:", ls);

//  sort(ls.begin(),ls.end());
    ZJW zjw;//比较器
    sort(ls.begin(),ls.end(),zjw);
    print("排序后:", ls);
/*
    const list<int> cls(ls);
    typedef list<int>::const_iterator CIT;
    for(CIT cit=cls.begin(); cit!=cls.end(); ++cit)
        cout << *cit << ' ';
    cout << endl << "-----------" << endl;

    CIT cit = cls.begin();
//  *cit = 12000;
*/
    return 0;
}






