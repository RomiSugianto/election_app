/********************************************************************************
** Form generated from reading UI file 'dialog_login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_LOGIN_H
#define UI_DIALOG_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_login
{
public:
    QPushButton *pushButton_login;
    QLabel *label_login_status;
    QLineEdit *lineEdit_userid;
    QLabel *label;

    void setupUi(QDialog *Dialog_login)
    {
        if (Dialog_login->objectName().isEmpty())
            Dialog_login->setObjectName(QString::fromUtf8("Dialog_login"));
        Dialog_login->resize(282, 128);
        pushButton_login = new QPushButton(Dialog_login);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(100, 70, 75, 23));
        label_login_status = new QLabel(Dialog_login);
        label_login_status->setObjectName(QString::fromUtf8("label_login_status"));
        label_login_status->setGeometry(QRect(40, 100, 191, 20));
        lineEdit_userid = new QLineEdit(Dialog_login);
        lineEdit_userid->setObjectName(QString::fromUtf8("lineEdit_userid"));
        lineEdit_userid->setGeometry(QRect(80, 40, 113, 20));
        label = new QLabel(Dialog_login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 10, 71, 20));

        retranslateUi(Dialog_login);

        QMetaObject::connectSlotsByName(Dialog_login);
    } // setupUi

    void retranslateUi(QDialog *Dialog_login)
    {
        Dialog_login->setWindowTitle(QApplication::translate("Dialog_login", "Dialog", nullptr));
        pushButton_login->setText(QApplication::translate("Dialog_login", "Login", nullptr));
        label_login_status->setText(QString());
        label->setText(QApplication::translate("Dialog_login", "Input Your ID", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_login: public Ui_Dialog_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_LOGIN_H
