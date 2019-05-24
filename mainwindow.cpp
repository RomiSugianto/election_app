#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "dialog_login.h"
#include "dialog_complete.h"
#include "dialog_admin.h"
#include "QByteArray"
#include "QBuffer"
#include "QFileDialog"
#include "function.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectToDatabase();

    Dialog_login loginPage;
    Dialog_admin adminPage;
    loginPage.exec();
    cekLvl(loginPage.lvl);
    cekLogin(loginPage.loginStatus);
    cekStatus(loginPage.status);
    chooser = loginPage.name;
    this->close();
    loadImage();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cekLvl(bool lvl)
{
    Dialog_admin adminPage;
    if (lvl == 1 )
    {
        adminPage.exec();
    }
}

void MainWindow::cekStatus(bool settleStatus)
{
    if (settleStatus==true)
    {
        ui->pushButton_settle->hide();
        ui->statusBar->showMessage("you've already choose");
        MainWindow::close();
    }
}

void MainWindow::cekLogin(bool loginStatus)
{
    if (loginStatus==false)
    {
        ui->pushButton_settle->hide();
        ui->statusBar->showMessage("You're not login yet");
    }
}

//Database Area
void MainWindow::connectToDatabase()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("remotemysql.com");
    db.setUserName("NA3pFq0MOb");
    db.setPassword("BCGCKzepho");
    db.setDatabaseName("NA3pFq0MOb");
//    db.setHostName("127.0.0.1");
//    db.setUserName("user");
//    db.setPassword("user");
//    db.setDatabaseName("qt_database_2017");


    if(db.open())
    {
        ui->statusBar->showMessage("Database Connected");
    }
    else
    {
        ui->statusBar->showMessage("Database is not Connected");
    }
}


void MainWindow::on_pushButton_settle_clicked()
{
    Dialog_complete complete;
    Dialog_login login;
    if(ui->radioButton_jp->isChecked())
    {
        QSqlQuery mysqlQuery;

        QString settle = "INSERT INTO settle(choice_id) VALUES (1);";
        QString status = "update user set iStatus = 1 where szName = '"+chooser+"';";

        mysqlQuery.exec(settle);
        mysqlQuery.exec(status);
        this->close();
        complete.exec();

    }
    else if (ui->radioButton_na->isChecked())
    {
        QSqlQuery mysqlQuery;

        QString settle = "INSERT INTO settle(choice_id) VALUES (2);";
        QString status = "update user set iStatus = 1 where szName = '"+chooser+"';";

        mysqlQuery.exec(settle);
        mysqlQuery.exec(status);
        this->close();
        complete.exec();
    }
    else
    {
        ui->statusBar->showMessage("you still haven't chosen anything");
    }
}

void MainWindow::loadImage()
{
    Function function;
    QPixmap imgLoadJp = function.getImageJp();
    QPixmap imgLoadNa = function.getImageNa();

    ui->label_jp->setPixmap(imgLoadJp);
    ui->label_na->setPixmap(imgLoadNa);

}
