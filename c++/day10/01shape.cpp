#include <iostream>
using namespace  std;
class Shape{//图形基类 (抽象类)
public:
    Shape(int x=0,int y=0):m_x(x),m_y(y){}
    virtual void draw(void)=0; //纯虚函数

protected:    
    int m_x;//x坐标
    int m_y;//y坐标
};

class Rect:public Shape{//矩形子类
public:
    Rect(int x,int y,int w,int h):Shape(x,y),m_w(w),m_h(h){}
    void draw(void){ //自动变成虚函数
        cout << "绘制矩形" << m_x << ',' << m_y << ',' << m_w << ',' << m_h
            << endl;
    }
private:
    int m_w;//宽
    int m_h;//高
};

class Circle:public Shape{//原型子类
public:
    Circle(int x,int y,int r):Shape(x,y),m_r(r){}
    void draw(void){ //自动变成虚函数
        cout << "绘制圆形:" << m_x << ',' << m_y << ',' << m_r << endl;
    }
private:
    int m_r;//半径
};

void render(Shape* buf[]){
    /* 正常通过指针调用成员函数,
     * 根据指针的类型调用相应的成员函数
     *
     * 如果通过指针调用的成员函数是虚函数
     * ,这时不再根据指针本身类型,而会根据
     * 指针所指向的目标对象类型去调用
     */
    for(int i=0;buf[i]!=NULL;i++){
        buf[i]->draw();
    }
}

int main(void){
    Shape* buf[1024]={NULL};
    buf[0]=new Rect(1,2,3,4);
    buf[1]=new Circle(3,4,6);
    buf[2]=new Rect(5,6,7,8);
    buf[3]=new Rect(10,11,8,9);
    buf[4]=new Circle(20,10,11);
    buf[5]=new Circle(10,15,21);
    render(buf);
    //Shape s; //error;
    return 0;
}













