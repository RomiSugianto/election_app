#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString chooser;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void connectToDatabase();
    void cekLogin(bool loginStatus);
    void on_pushButton_settle_clicked();
    void cekStatus(bool settleStatus);
    void cekLvl(bool lvl);
    void loadImage();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
