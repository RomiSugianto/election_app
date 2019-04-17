#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "dialog_login.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectToDatabase();

    Dialog_login loginPage;
    loginPage.exec();
    cekLogin(loginPage.loginStatus);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cekLogin(bool loginStatus)
{
    if (loginStatus==false)
    {

        close();
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
    if(ui->radioButton_jp->isChecked())
    {
        QSqlQuery mysqlQuery;

        QString query = "INSERT INTO settle(choice_id) VALUES (1);";

        mysqlQuery.exec(query);

    }
    else if (ui->radioButton_na->isChecked())
    {
        QSqlQuery mysqlQuery;

        QString query = "INSERT INTO settle(choice_id) VALUES (2);";

        mysqlQuery.exec(query);
    }
    else
    {
        ui->statusBar->showMessage("you still haven't chosen anything");
    }
}
