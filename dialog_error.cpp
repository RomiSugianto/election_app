#include "dialog_error.h"
#include "ui_dialog_error.h"

Dialog_error::Dialog_error(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_error)
{
    ui->setupUi(this);
}

Dialog_error::~Dialog_error()
{
    delete ui;
}
