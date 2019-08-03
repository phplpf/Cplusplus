/********************************************************************************
** Form generated from reading UI file 'TimeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEDIALOG_H
#define UI_TIMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TimeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *m_label;
    QPushButton *m_button;

    void setupUi(QDialog *TimeDialog)
    {
        if (TimeDialog->objectName().isEmpty())
            TimeDialog->setObjectName(QStringLiteral("TimeDialog"));
        TimeDialog->resize(259, 285);
        QFont font;
        font.setPointSize(20);
        TimeDialog->setFont(font);
        verticalLayout = new QVBoxLayout(TimeDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_label = new QLabel(TimeDialog);
        m_label->setObjectName(QStringLiteral("m_label"));
        m_label->setFrameShape(QFrame::Panel);
        m_label->setFrameShadow(QFrame::Sunken);
        m_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(m_label);

        m_button = new QPushButton(TimeDialog);
        m_button->setObjectName(QStringLiteral("m_button"));

        verticalLayout->addWidget(m_button);


        retranslateUi(TimeDialog);

        QMetaObject::connectSlotsByName(TimeDialog);
    } // setupUi

    void retranslateUi(QDialog *TimeDialog)
    {
        TimeDialog->setWindowTitle(QApplication::translate("TimeDialog", "\346\227\266\351\227\264", 0));
        m_label->setText(QString());
        m_button->setText(QApplication::translate("TimeDialog", "\350\216\267\345\217\226\346\227\266\351\227\264", 0));
    } // retranslateUi

};

namespace Ui {
    class TimeDialog: public Ui_TimeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEDIALOG_H
