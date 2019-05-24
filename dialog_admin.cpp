#include "dialog_admin.h"
#include "ui_dialog_admin.h"
#include "QtSql/QSql"
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlQuery"
#include "mainwindow.h"
#include "QTimer"
#include "user.h"
#include "QByteArray"
#include "QBuffer"
#include "QFileDialog"

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

void Dialog_admin::setHeaderTable()
{
    QStringList headerData;
    headerData.append("User ID");
    headerData.append("Nama");
    headerData.append("Alamat");
    headerData.append("Status");

    ui->tableWidget->setColumnCount(headerData.count());
    ui->tableWidget->setHorizontalHeaderLabels(headerData);
}

QList<UserData >Dialog_admin::GetUserData()
{
    QList<UserData> listUserData;
    UserData userData;

    QSqlQuery mysqlQuery;

    QString query = "SELECT * FROM user WHERE iLvl = 0;";

    int userId;
    QString userName;
    QString userAddress;
    int userStatus;

    mysqlQuery.exec(query); //.exec berarti mengeksekusi query tersebut

    if(mysqlQuery.size() > 0) //size() > 0 artinya, jika datanya lebih dari 0
    {
        while(mysqlQuery.next()) // jika data ada, dan diulang sebanyak data yang ada
        {
            userId = mysqlQuery.value("idNumber").toInt();  //.value ini menunjuk ke nama kolom, makanya didalemnya di isi  dengan szForbiddenWord, ditambahkan .toString();
            userName = mysqlQuery.value("szName").toString();
            userStatus = mysqlQuery.value("iStatus").toInt();
            userAddress = mysqlQuery.value("szAddress").toString();

            userData.setUserId(userId);
            userData.setName(userName);
            userData.setStatus(userStatus);
            userData.setAddress(userAddress);

            listUserData.append(userData);
        }
    }

    return listUserData;
}

void Dialog_admin::insertDataToTable(QList<UserData> listUserData)
{
    foreach (UserData userData, listUserData)
    {
        ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);

        int row = ui->tableWidget->rowCount()-1;

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(userData.getUserId())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(userData.getName()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(userData.getAddress()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(userData.getStatus())));
    }
}

void Dialog_admin::on_pushButton_show_clicked()
{
    ui->tableWidget->setRowCount(0);
    QList<UserData> listUserData = GetUserData();
    setHeaderTable();
    insertDataToTable(listUserData);

    ui->progressBar->show();
    QSqlQuery mysqlQuery;

    QString query_jp = "SELECT COUNT(choice_id) AS total  FROM settle WHERE choice_id = 1;";
    QString query_na = "SELECT COUNT(choice_id) AS total  FROM settle WHERE choice_id = 2;";
    QString query_nsy = "select count(szName) as total from `user` where iStatus = 0;";
    QString query_settle = "select count(szName) as total from `user` where iStatus = 1;";
    QString query_user = "select count(szName) as total from `user` where iLvl = 0;";

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
    ui->progressBar->setValue(100);
    if(mysqlQuery.exec(query_settle))
    {
        while(mysqlQuery.next())
        {
            total_settle = mysqlQuery.value("total").toInt();
            if(mysqlQuery.size() > 0)
            {
                ui->lcdNumber_settle->display(QString::number(total_settle));
                ui->progressBar->hide();
            }
            break;
        }
    }
    if(mysqlQuery.exec(query_user))
    {
        while(mysqlQuery.next())
        {
            total_user = mysqlQuery.value("total").toInt();
            if(mysqlQuery.size() > 0)
            {

            }
            break;
        }
     }

}

void Dialog_admin::on_pushButton_pic_jp_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open Image", // title dialognya
                                                    "C:/", //default path
                                                    "(*.JPG);;(*.PNG);;(*;;JPEG);;(*.BMP)");  //filter type file (extension)

    QPixmap img(fileName);

    QPixmap imgResize = img.scaled(
                                   ui->label_pic_jp->width(),
                                   ui->label_pic_jp->height(),
                                   Qt::KeepAspectRatio,
                                   Qt::FastTransformation);

    ui->label_pic_jp->setPixmap(imgResize);

    saveImage(imgResize);

//    QPixmap imgLoad = loadImage();

//    ui->label_pic_jp->setPixmap(imgLoad);
}

void Dialog_admin::on_pushButton_pic_na_clicked()
{

}

void Dialog_admin::saveImage(QPixmap pixImg)
{
    QByteArray byteImg;
    QBuffer buffImage(&byteImg);

    buffImage.open(QBuffer::WriteOnly);

    QImage img = pixImg.toImage();

    QPixmap::fromImage(img).save(&buffImage, "JPG");

    QString queryInsert =
            "UPDATE image SET imgData=:imgData WHERE iOwn=1";
    QSqlQuery query;

    query.prepare(queryInsert);
    query.bindValue(":imgData", byteImg);
    if(query.exec())
    {
        ui->label_status_pic->setText("Berhasil Input");

    }
    else
    {
        ui->label_status_pic->setText("Gagal Input");
    }
}
