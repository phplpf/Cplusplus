#include <iostream>
using namespace std;
int main(void){
    string str;
    cin >> str;
    //"hello"->"olleh"
    //"abcdef"->"fedcba"
    //"1234567"->"7654321"
    int len=str.size();
    for(int i=0;i<len/2;i++){
        str[i] = str[i]^str[len-i-1];
        str[len-i-1]=str[i]^str[len-i-1];
        str[i] = str[i]^str[len-i-1];
    }
    cout << str << endl;
    return 0;
}


