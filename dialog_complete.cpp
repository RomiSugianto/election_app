#include "dialog_complete.h"
#include "ui_dialog_complete.h"

Dialog_complete::Dialog_complete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_complete)
{
    ui->setupUi(this);
}

Dialog_complete::~Dialog_complete()
{
    delete ui;
}
