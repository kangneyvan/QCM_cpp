#include "loginpage.h"
#include "ui_loginpage.h"

#include <QObject>
#include <QString>
#include <QCheckBox>
#include <QMessageBox>
#include "mainwindow.h"
#include <QApplication>
#include <fstream>
#include <iostream>
#include <QTimer>
#include <QDateTime>


LoginPage::LoginPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showtime()));
    timer->start();

    QDateTime datetime=QDateTime::currentDateTime();
    QString datetime_text=datetime.toString();

    ui->Date_ed->setText(datetime_text);
}


LoginPage::~LoginPage()
{
    delete ui;
}

bool trouver_etudiant(const char& para,const string& check){
    string fic="etudiants.txt";
    ifstream myfile(fic);
    string buffer;
    bool check_np= false;
    try{
        if(myfile.is_open()){
            while(myfile.good()){
                getline(myfile,buffer);
                if(buffer[0]==para){
                    buffer.erase(0,1);
                }if(buffer==check){
                    check_np=true;
                    break;
                }
            }
        }else
        {
            throw string("the path or the file is incorect in login page");
        }

    } catch(const string & msg){
        cerr<<msg<<endl;
}
    return check_np;
}


bool trouver_enseignant(const char& para,const string& check){
    string fic="enseignants.txt";
    ifstream myfile(fic);
    string buffer;
    bool check_np= false;
    try{
        if(myfile.is_open()){
            while(myfile.good()){
                getline(myfile,buffer);
                if(buffer[0]==para){
                    buffer.erase(0,1);
                }if(buffer==check){
                    check_np=true;
                    break;
                }
            }
        }else
        {
            throw string("the path or the file is incorect in login page");
        }

    } catch(const string & msg){
        cerr<<msg<<endl;
}
    return check_np;
}




void LoginPage::on_pushButton_log_clicked()
{
    QString user_name= ui->lineEdit_U->text();
    QString user_pass= ui->lineEdit_P->text();

    if(user_name=="" && user_pass==""){
        QMessageBox::information(this,"WARNING!","please enter a correct id");
    }
    else if(user_name == "admin" && user_pass =="admin"){
        ui->lineEdit_U->setText("");
        ui->lineEdit_P->setText("");
        AdminPage *a=new AdminPage;
        a->show();

   }else{
        bool check_name_etudiant=trouver_etudiant('*',user_name.toStdString());
        bool check_pass_etudiant=trouver_etudiant('{',user_pass.toStdString());
        bool check_name_enseignant=trouver_enseignant('*',user_name.toStdString());
        bool check_pass_enseignant=trouver_enseignant('{',user_pass.toStdString());
        if (check_name_etudiant && check_pass_etudiant)
        {
             QMessageBox::information(this,"Login","Good luck!");
             close();

             MainWindow * m = new MainWindow(this);
             m->set_name(user_name.toStdString());
             m->show();
        }else if (check_name_enseignant && check_pass_enseignant){
            QMessageBox::information(this,"Login","Good luck!");
            close();

            MakeTest* t= new MakeTest(this);
//            t->set_name(user_name.toStdString());
             t->show();

        } else {
            QMessageBox::information(this,"oops","make sure you have entered the right parameters");
        }
    }
}

void LoginPage::showtime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");

    if((time.second() % 2)==0){
        time_text[3]=' ';
        time_text[8]=' ';
    }

    ui->digital_clock->setText(time_text);
}
