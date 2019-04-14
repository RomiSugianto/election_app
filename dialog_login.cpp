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
    QString userId = ui->lineEdit_userId->text();
    QSqlQuery mysqlQuery;

    QString query = "SELECT * FROM user where szUserName = '"+userId+"'";

    mysqlQuery.exec(query);

    if(mysqlQuery.size() > 0)
    {
        ui->label->setText("Login Succeed");
        this->close();
        loginStatus=true;
    }
    else
    {
        ui->label->setText("Your ID is not recognized by this server");
        loginStatus=false;
    }

}
