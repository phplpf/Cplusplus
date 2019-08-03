/********************************************************************************
** Form generated from reading UI file 'calculatordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORDIALOG_H
#define UI_CALCULATORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CalculatorDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *m_editX;
    QLabel *m_label;
    QLineEdit *m_editY;
    QPushButton *m_button;
    QLineEdit *m_editZ;

    void setupUi(QDialog *CalculatorDialog)
    {
        if (CalculatorDialog->objectName().isEmpty())
            CalculatorDialog->setObjectName(QStringLiteral("CalculatorDialog"));
        CalculatorDialog->resize(446, 149);
        QFont font;
        font.setPointSize(20);
        CalculatorDialog->setFont(font);
        horizontalLayout = new QHBoxLayout(CalculatorDialog);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_editX = new QLineEdit(CalculatorDialog);
        m_editX->setObjectName(QStringLiteral("m_editX"));
        m_editX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(m_editX);

        m_label = new QLabel(CalculatorDialog);
        m_label->setObjectName(QStringLiteral("m_label"));

        horizontalLayout->addWidget(m_label);

        m_editY = new QLineEdit(CalculatorDialog);
        m_editY->setObjectName(QStringLiteral("m_editY"));
        m_editY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(m_editY);

        m_button = new QPushButton(CalculatorDialog);
        m_button->setObjectName(QStringLiteral("m_button"));
        m_button->setEnabled(false);

        horizontalLayout->addWidget(m_button);

        m_editZ = new QLineEdit(CalculatorDialog);
        m_editZ->setObjectName(QStringLiteral("m_editZ"));
        m_editZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        m_editZ->setReadOnly(true);

        horizontalLayout->addWidget(m_editZ);


        retranslateUi(CalculatorDialog);

        QMetaObject::connectSlotsByName(CalculatorDialog);
    } // setupUi

    void retranslateUi(QDialog *CalculatorDialog)
    {
        CalculatorDialog->setWindowTitle(QApplication::translate("CalculatorDialog", "\350\256\241\347\256\227\345\231\250", 0));
        m_label->setText(QApplication::translate("CalculatorDialog", "+", 0));
        m_button->setText(QApplication::translate("CalculatorDialog", "=", 0));
    } // retranslateUi

};

namespace Ui {
    class CalculatorDialog: public Ui_CalculatorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORDIALOG_H
