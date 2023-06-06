#include "maketest.h"
#include "ui_maketest.h"
#include "question.h"
#include <QObject>
#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <iostream>
#include <QTimer>
#include <QDateTime>
using namespace std;


MakeTest::MakeTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MakeTest)
{
    ui->setupUi(this);

    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showtime_m()));
    timer->start();

    ofstream quest_file;
    quest_file.open("quest_rep.txt",ios::trunc);


    QDateTime datetime=QDateTime::currentDateTime();
    QString datetime_text=datetime.toString();


    QFile file("matiere.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        QString str(line);
        ui->comboBoxMatiere->addItem(str);
    }
}


MakeTest::~MakeTest()
{
    delete ui;
}

void MakeTest::on_pushButton_add_clicked()
{

    QString qst=ui->lineEdit_q->text();
    Question q(qst.toStdString());
    QList<QLineEdit*> reponses_=ui->widget->findChildren<QLineEdit*>();

    ofstream quest_file;

     if(counter_trunc==0)
     {
        quest_file.open("quest_rep.txt",ios::trunc);
     } else{ quest_file.open("quest_rep.txt",ios::app);}

     int verifier_reponse=0;
     foreach (QLineEdit* c, reponses_)
     {
         string verif=(c->text().toStdString());
         if(verif=="")
         {
            ++ verifier_reponse;
         }
     }
     if (q.getTexte()==""|| verifier_reponse>=4)
     {
         if(q.getTexte()=="")
         {
             QMessageBox::information(this,"WARNING!","you have forgot to enter a question");
         }
         else{QMessageBox::information(this,"WARNING! ","please enter 2 to 5 possibilities");}
     }
     else
     {
        quest_file<<q.getTexte()<<endl;
        ui->lineEdit_q->clear();
        foreach (QLineEdit* c, reponses_)
        {
            quest_file<<(c->text()).toStdString()<<endl;
            c->clear();
        }
            quest_file<<"@#!"<<endl;
            QMessageBox::information(this,"Saved "," The question has been saved");
             ++counter_trunc;
     }
     quest_file.close();
}

void MakeTest::on_pushButton_exit_clicked()
{
    string question_rep="quest_rep.txt";
    ifstream myfile(question_rep);
    string buffer;
    getline(myfile,buffer);

    if(buffer=="")
    {
        QMessageBox::information(this,"DANGER DANGER!!!","Not a single question has been saved");
    }else
    {
        close();
        QMessageBox::information(this,"DANGER DANGER!!!","ALL Questions have been saved.\n No more modifications are allowed!!!");
    }
    myfile.close();
}

void MakeTest::showtime_m()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");

    if((time.second() % 2)==0)
    {
        time_text[3]=' ';
        time_text[8]=' ';
    }
}



void MakeTest::on_comboBoxMatiere_activated(const QString &arg1)
{
    list<string> listMatiere;
    QString data=ui->comboBoxMatiere->currentText();
    string matSelected = data.toStdString();


    QFile file("matiere.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        string u = line.toStdString();
        listMatiere.push_back(u);

    }
}

