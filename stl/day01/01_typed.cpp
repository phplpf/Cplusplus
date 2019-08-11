#include <iostream>
using namespace std;

int max_int(int x, int y){
    return x > y ? x : y;
}
double max_double(double x, double y){
    return x > y ? x : y;
}
string max_string(string x, string y){
    return x > y ? x : y;
}
int main(){
    int nx=10, ny=20;
    cout << max_int(nx,ny) << endl;
    double dx=12.3, dy=45.6;
    cout << max_double(dx,dy) << endl;
    string sx="world", sy="hello";
    cout << max_string(sx,sy) << endl;
    return 0;
}






