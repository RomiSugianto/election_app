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

    }
}

//Database Area
void MainWindow::connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("qt_database_2017");

    if(db.open())
    {
        ui->statusBar->showMessage("Database Terkoneksi");
    }
    else
    {
        ui->statusBar->showMessage("Database Tidak Terkoneksi");
    }
}

