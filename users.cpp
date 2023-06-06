#include "users.h"
#include "ui_users.h"
#include <QString>
#include <QMessageBox>

Users::Users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Users)
{
    ui->setupUi(this);
}

Users::~Users()
{
    delete ui;
}

void Users::on_yes_btn_clicked()
{
    QString id_msg=ui->lineEdit_user->text();
    if(id_msg==""){
        QMessageBox::information(this,"DANGER !","please enter your id");
    }else{
    close();
    LoginPage* login=new LoginPage(this);
    login->show();
    }
}

void Users::on_no_btn_clicked()
{
    close();
    note=new NOTE(this);
    note->show();
}
