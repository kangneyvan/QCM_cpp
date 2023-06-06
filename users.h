#ifndef USERS_H
#define USERS_H

#include <QDialog>
#include <QMainWindow>
#include "loginpage.h"
#include "note.h"

namespace Ui {
class Users;
}

class Users : public QDialog
{
    Q_OBJECT

public:
    explicit Users(QWidget *parent = nullptr);
    ~Users();

private slots:
    void on_yes_btn_clicked();

    void on_no_btn_clicked();

private:
    Ui::Users *ui;
    //LoginPage* login;
    NOTE* note;
};

#endif // USERS_H
