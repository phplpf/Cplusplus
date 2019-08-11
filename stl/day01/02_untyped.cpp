#include <iostream>
using namespace std;

#define Max(x,y) (x>y?x:y)

int main(){
    int nx=10, ny=20;
    cout << Max(nx,ny) << endl;
          //(nx>ny?nx:ny)
    double dx=12.3, dy=45.6;
    cout << Max(dx,dy) << endl;
          //(dx>dy?dx:dy)
    string sx="world", sy="hello";
    cout << Max(sx,sy) << endl;
          //(sx>sy?sx:sy)
    char cx[256]="world", cy[256]="hello";
    cout << Max(cx,cy) << endl;
          //(cx>cy?cx:cy)
    return 0;
}




