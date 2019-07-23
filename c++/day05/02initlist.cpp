#include <iostream>
#include <cstring>
using namespace std;
class Dummy{
public:
    Dummy(const char* str)
        //:m_str(str),m_len(m_str.size()){}
        :m_str(str?str:""),
         m_len(strlen(str?str:"")){}
    size_t m_len;
    string m_str;
};
int main(void){
    //Dummy d("hello world!");
    Dummy d(NULL);
    cout << d.m_str << ',' << d.m_len << endl;
    return 0;
}



