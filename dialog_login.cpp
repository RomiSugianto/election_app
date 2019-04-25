#include "dialog_login.h"
#include "ui_dialog_login.h"
#include "QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"

Dialog_login::Dialog_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_login)
{
    ui->setupUi(this);
}

Dialog_login::~Dialog_login()
{
    delete ui;
}

void Dialog_login::on_pushButton_login_clicked()
{
    QString userId = ui->lineEdit_userid->text();
    QSqlQuery mysqlQuery;
    QString query = "SELECT * FROM user where idNumber = "+userId+"";

    mysqlQuery.exec(query);

    while(mysqlQuery.next())
    {
        name = mysqlQuery.value("szName").toString();
        lvl = mysqlQuery.value("iLvl").toInt();
        status = mysqlQuery.value("iStatus").toInt();
        break;
    }

    if(mysqlQuery.size() > 0)
    {
        ui->label_login_status->setText("Login Succeed");
        this->close();
        loginStatus=true;
    }
    else
    {
        ui->label_login_status->setText("Your ID is not recognized by this server");
    }
}
