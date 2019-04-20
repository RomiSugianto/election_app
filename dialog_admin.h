#ifndef DIALOG_ADMIN_H
#define DIALOG_ADMIN_H

#include <QDialog>

namespace Ui {
class Dialog_admin;
}

class Dialog_admin : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_admin(QWidget *parent = nullptr);
    ~Dialog_admin();

private:
    Ui::Dialog_admin *ui;
};

#endif // DIALOG_ADMIN_H
