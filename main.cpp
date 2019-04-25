#include "mainwindow.h"
#include <QApplication>
#include "QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "dialog_login.h"
#include "dialog_complete.h"
#include "dialog_admin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Dialog_admin adminPage;
    Dialog_login loginPage;

    w.show();

    return a.exec();
}
