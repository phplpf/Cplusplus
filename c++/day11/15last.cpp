#include <iostream>
#include <fstream>
using namespace std;
int main(void){
    ofstream ofs("last.txt");
    char wbuf[] = "C++终于结束了!";
    ofs.write(wbuf,sizeof(wbuf));
    ofs.close();

    ifstream ifs("last.txt");
    char rbuf[100] = {0};
    ifs.read(rbuf,sizeof(rbuf));
    cout << "读到:" << rbuf << endl;
    ifs.close();

    return 0;
}





