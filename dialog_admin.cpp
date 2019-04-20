#include "dialog_admin.h"
#include "ui_dialog_admin.h"

Dialog_admin::Dialog_admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_admin)
{
    ui->setupUi(this);
}

Dialog_admin::~Dialog_admin()
{
    delete ui;
}
