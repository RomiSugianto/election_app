#ifndef DIALOG_COMPLETE_H
#define DIALOG_COMPLETE_H

#include <QDialog>

namespace Ui {
class Dialog_complete;
}

class Dialog_complete : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_complete(QWidget *parent = nullptr);
    ~Dialog_complete();

private:
    Ui::Dialog_complete *ui;
};

#endif // DIALOG_COMPLETE_H
