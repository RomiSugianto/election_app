#include "dialog_admin.h"
#include "ui_dialog_admin.h"
#include "QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "mainwindow.h"

Dialog_admin::Dialog_admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_admin)
{
    ui->setupUi(this);
    ui->progressBar->hide();
}

Dialog_admin::~Dialog_admin()
{
    delete ui;
}

void Dialog_admin::on_pushButton_show_clicked()
{
    ui->progressBar->show();
    QSqlQuery mysqlQuery;

    QString query_jp = "SELECT COUNT(choice_id) AS total  FROM settle WHERE choice_id = 1;";
    QString query_na = "SELECT COUNT(choice_id) AS total  FROM settle WHERE choice_id = 2;";
    QString query_nsy = "select count(szName) as total from `user` where iStatus = 0;";
    QString query_settle = "select count(szName) as total from `user` where iStatus = 1;";

//    mysqlQuery.exec(query_jp);
//    mysqlQuery.exec(query_na);
//    mysqlQuery.exec(query_nsy);
//    mysqlQuery.exec(query_settle);

//    while(mysqlQuery.next())
//    {
//        total_jp = mysqlQuery.value("total").toInt();
//        if(mysqlQuery.size() > 0)
//        {
//            ui->lcdNumber_jp->display(QString::number(total_jp));
//        }
//        break;
//    }

//    while(mysqlQuery.next())
//    {
//        total_jp = mysqlQuery.value("total").toInt();
//        if(mysqlQuery.size() > 0)
//        {
//            ui->lcdNumber_na->display(QString::number(total_jp));
//        }
//        break;
//    }

//    while(mysqlQuery.next())
//    {
//        total_nsy = mysqlQuery.value("total").toInt();
//        if(mysqlQuery.size() > 0)
//        {
//            ui->lcdNumber_nsy->display(QString::number(total_nsy));
//        }
//        break;
//    }

//    while(mysqlQuery.next())
//    {
//        total_settle = mysqlQuery.value("total").toInt();
//        if(mysqlQuery.size() > 0)
//        {
//            ui->lcdNumber_settle->display(QString::number(total_settle));
//        }
//        break;
//    }

    if(mysqlQuery.exec(query_jp))
    {
        while(mysqlQuery.next())
        {
            total_jp = mysqlQuery.value("total").toInt();
            if(mysqlQuery.size() > 0)
            {
                ui->lcdNumber_jp->display(QString::number(total_jp));
                ui->progressBar->setValue(25);
            }
            break;
        }
    }
    if(mysqlQuery.exec(query_na))
    {
        while(mysqlQuery.next())
        {
            total_jp = mysqlQuery.value("total").toInt();
            if(mysqlQuery.size() > 0)
            {
                ui->lcdNumber_na->display(QString::number(total_jp));
                ui->progressBar->setValue(50);
            }
            break;
        }
    }
    if(mysqlQuery.exec(query_nsy))
    {
        while(mysqlQuery.next())
        {
            total_nsy = mysqlQuery.value("total").toInt();
            if(mysqlQuery.size() > 0)
            {
                ui->lcdNumber_nsy->display(QString::number(total_nsy));
                ui->progressBar->setValue(75);
            }
            break;
        }
    }
    if(mysqlQuery.exec(query_settle))
    {
        while(mysqlQuery.next())
        {
            total_settle = mysqlQuery.value("total").toInt();
            if(mysqlQuery.size() > 0)
            {
                ui->lcdNumber_settle->display(QString::number(total_settle));
                ui->progressBar->setValue(100);
                ui->progressBar->hide();
            }
            break;
        }
     }

}
