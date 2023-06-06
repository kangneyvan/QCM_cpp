#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include <QMainWindow>
#include "mainwindow.h"
#include "adminpage.h"
#include "maketest.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QDialog
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void on_pushButton_log_clicked();
    void showtime();

private:
    Ui::LoginPage *ui;
    //MainWindow *m;
    MakeTest *t;


};

#endif // LOGINPAGE_H
