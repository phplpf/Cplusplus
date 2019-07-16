#include <iostream>
using namespace std;
int main(void){
    string str;
    //cin >> str;//碰到空白符结束
    getline(cin,str);//碰到"\n"结束
    int count = 0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='A' || str[i]=='a'){
            ++count;
        }
    }
    cout << count << endl;
    return 0;
}
