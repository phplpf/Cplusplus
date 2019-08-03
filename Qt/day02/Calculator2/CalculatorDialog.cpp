#include "CalculatorDialog.h"
//构造函数
CalculatorDialog::CalculatorDialog(void){
    //界面初始化
    setupUi(this);
    
    //设置窗口标题
    //setWindowTitle("计算器");
    //设置窗口字体大小
    //QFont font;
    //font.setPointSize(20);
    //setFont(font);
    //左操作数
    //this指向父窗口对象,即父窗口对象指针
    //m_editX = new QLineEdit(this);
    //设置文本对齐方式:右对齐
    //m_editX->setAlignment(Qt::AlignRight);
    //设置数字验证器:只能输入数字形式内容
    m_editX->setValidator(
        new QDoubleValidator(this));
    //右操作数
    //m_editY = new QLineEdit(this);
    //m_editY->setAlignment(Qt::AlignRight);
    m_editY->setValidator(
        new QDoubleValidator(this));
    //显示结果
    //m_editZ = new QLineEdit(this);
    //m_editZ->setAlignment(Qt::AlignRight);
    //m_editZ->setReadOnly(true);//设置只读

    //"+"
    //m_label = new QLabel("+",this);
    
    //"="
    //m_button = new QPushButton("=",this);
    //m_button->setEnabled(false);//禁用

    //创建水平布局器
    //QHBoxLayout* layout = 
    //    new QHBoxLayout(this);
    //将控件按水平方向依次添加到布局器中
    //layout->addWidget(m_editX);
    //layout->addWidget(m_label);
    //layout->addWidget(m_editY);
    //layout->addWidget(m_button);
    //layout->addWidget(m_editZ);
    //设置布局器
    //setLayout(layout);

    //信号和槽函数
    //当左右操作数文本改变时,发送信号:
    //textChanged(QString)
    //注:如果要连接的槽函数是在当前父窗口类
    //中自定义的,那么第三个参数一定是this.
    connect(
      m_editX,SIGNAL(textChanged(QString)),
      this,SLOT(enableButton(void)));
    connect(
      m_editY,SIGNAL(textChanged(QString)),
      this,SLOT(enableButton(void)));
    //点击等号按钮,发送信号:clicked()
    connect(m_button,SIGNAL(clicked(void)),
      this,SLOT(calcClicked(void)));
}
//恢复等号按钮状态的槽函数
void CalculatorDialog::enableButton(void){
    bool bXOk;
    bool bYOk;
    //text():获取输入文本(QString)
    //toDouble():QString转换为double,参数
    //保存转换是否成功的结果
    m_editX->text().toDouble(&bXOk);
    m_editY->text().toDouble(&bYOk);
    //如果左右操作数都输入了有效数据,则恢复
    //按钮正常状态,否则设置为禁用
    m_button->setEnabled(bXOk && bYOk);
}
//计算和显示结果的槽函数
void CalculatorDialog::calcClicked(void){
    //计算左右操作数相加结果
    double res = m_editX->text().toDouble()
            + m_editY->text().toDouble();
    //将计算结果转换为字符串
    //number():将double转换为字符串
    QString str = QString::number(res);
    //将字符串形式结果显示到界面
    //setText():设置控件要显示的文本
    m_editZ->setText(str);
}






