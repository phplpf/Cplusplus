#include <iostream>
using namespace  std;
class PDFParser{
public:
    void parse(const char* pdffile){
        cout << "解析出一个图形" << endl;
        onImage();
        cout << "解析出一行文本" << endl;
        onText();
    }
private:
    virtual void onImage(void)=0;
    virtual void onText(void)=0;
};

class PDFRender:public PDFParser{
private:
    void onImage(void){
        cout << "绘制一个图形" << endl;
    }
    void onText(void){
        cout << "显示一个文本" << endl;
    }

};

int main(void){
    PDFRender render;
    render.parse("xx.pdf");
    return 0;
}





