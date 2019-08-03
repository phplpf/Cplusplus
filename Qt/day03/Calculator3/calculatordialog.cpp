#include "calculatordialog.h"
#include "ui_calculatordialog.h"

CalculatorDialog::CalculatorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CalculatorDialog)
{
    ui->setupUi(this);
    ui->m_editX->setValidator(
        new QDoubleValidator(this));
    ui->m_editY->setValidator(
        new QDoubleValidator(this));
    connect(
      ui->m_editX,SIGNAL(textChanged(QString)),
      this,SLOT(enableButton(void)));
    connect(
      ui->m_editY,SIGNAL(textChanged(QString)),
      this,SLOT(enableButton(void)));
    connect(
      ui->m_button,SIGNAL(clicked(void)),
      this,SLOT(calcClicked(void)));
}

CalculatorDialog::~CalculatorDialog()
{
    delete ui;
}
void CalculatorDialog::enableButton(void)
{
    bool bXOk,bYOk;
    ui->m_editX->text().toDouble(&bXOk);
    ui->m_editY->text().toDouble(&bYOk);
    ui->m_button->setEnabled(bXOk && bYOk);
}
void CalculatorDialog::calcClicked(void)
{
    double res = ui->m_editX->text().toDouble()
            + ui->m_editY->text().toDouble();
    QString str = QString::number(res);
    ui->m_editZ->setText(str);
}




