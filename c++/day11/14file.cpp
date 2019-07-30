#include <iostream>
#include <fstream>
using namespace std;

int main(void){
    ofstream ofs("file.txt");
    ofs << 1234 << ' ' << 56.78 << ' ' << 
        "C++" << endl;
    ofs.close();//关闭文件

    ifstream ifs("file.txt");
    int i;
    double d;
    string s;
    ifs >> i >> d >> s;
    cout << "读到:" << i << ',' << d << ','
        << s << endl;
    ifs.close();

    return 0;
}





