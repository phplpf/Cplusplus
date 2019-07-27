#include <iostream>
using namespace std;
class Phone{//电话基类
public:
    Phone(const string& num):m_num(num){}
    void call(const string& num){
        cout << m_num << "打给" << num 
            << endl;
    }
private:
    string m_num;
};
class Player{//播放器基类
public:
    Player(const string& media)
        :m_media(media){}
    void play(const string& music){
        cout << m_media << "播放器播放" <<
            music << endl;
    }
private:
    string m_media;
};
class Computer{//计算机基类
public:
    Computer(const string& os):m_os(os){}
    void run(const string& app){
        cout << "在" << m_os << "系统上运行"
            << app << endl;
    }
private:
    string m_os;
};
//智能手机子类
class SmartPhone:public Phone,
                 public Player,
                 public Computer{
public:    
    SmartPhone(const string& num,
               const string& media,
               const string& os)
                    :Phone(num),
                     Player(media),
                     Computer(os){}
};
int main(void){
    SmartPhone iphoneXs(
        "18866668888","MP4","Android");
    iphoneXs.call("12315");
    iphoneXs.play("最炫小苹果");
    iphoneXs.run("绝地求生");
    
    SmartPhone* p1 = &iphoneXs;
    Phone* p2 = p1;
    Player* p3 = p1;//+24
    Computer* p4 = p1;//+48

    cout << "p1=" << p1 << endl;
    cout << "p2=" << p2 << endl;
    cout << "p3=" << p3 << endl;
    cout << "p4=" << p4 << endl;

    cout << "sizeof(string):" << 
        sizeof(string) << endl;

    return 0;
}













