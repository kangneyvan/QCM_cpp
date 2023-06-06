#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "question.h"

#include <QObject>
#include <QString>
#include <QCheckBox>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <string>
#include <QTimer>
#include <QDateTime>
#include <thread>
#include <chrono>

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    string question_rep="quest_rep.txt";
    ifstream myfile(question_rep);
    string buffer;

    try {
        if(myfile.is_open()){
            while(myfile.good()){

                getline(myfile,buffer);
                if (buffer=="@#!"){
                    continue;
                }
                Question q(buffer);
                for(size_t i(0);i<5;++i){
                    bool t=false;
                    getline(myfile,buffer);
                    if (buffer=="")
                    {
                        continue;
                    }
                    if(buffer[0]=='-' && buffer[1]=='>')
                    {
                        t=true;
                        buffer.erase(0,2);
                    }
                    q.ajouter(Reponse(buffer,t));
                }
                questions.push_back(q);
            }
            myfile.close();
        }else{
            throw string("the path or the file is incorect");
        }
    }
    catch(const string & msg){
        cerr<<msg<<endl;
    }

    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showtime_t()));
    timer->start();


    string note_tex="please note that ids go from 1->...  \n if you are the first person your id is 1 and ...";
    QString note_qs=QString::fromStdString(note_tex);
    QMessageBox::information(this,"WARNING!!",note_qs);

    counter = 0;
    showQuestion(counter);


    // Démarrage d'une nouvelle thread pour la temporisation
    MainWindow mainW;



}

void stopTime(){
    std::this_thread::sleep_for(std::chrono::seconds(8));
    MainWindow mainW;
}

void MainWindow::set_name(const string &name)
{
    name_etudiant=name;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showQuestion(size_t i)
{
    Question q = questions[i];

    ui->question->setText(QString::fromStdString(q.getTexte()));
    QList<QCheckBox*> checks=centralWidget()->findChildren<QCheckBox*>();

    size_t itr(0);
    foreach (QCheckBox* c, checks)
    {
        if(itr<q.getSize())
        {
            c->setText(QString::fromStdString(q[itr].getTexte()));
            c->setChecked(false);
        }else{c->hide();}
        ++itr;
    }
}


void MainWindow::on_valider_clicked()
{    QString counter_qs=ui->lineEdit_id->text();
     if(counter_qs==""){
         QMessageBox::information(this,"Warning !","you have forgot to enter an ID");

     }else{
         Question q = questions[counter];
         QList<QCheckBox*> checks=centralWidget()->findChildren<QCheckBox*>();
         size_t itr(0);
         vector<bool> Cbox_correcte;
         vector<bool> Cbox_test;
         int verifier_correcte=0;
         int verifier_checked=0;
         foreach (QCheckBox* c, checks)
         {
             if(itr<q.getSize())
             {
                 if (c->isChecked()){
                     ++verifier_checked;
                 }
                 if(q[itr].isCorrect()){
                     ++verifier_correcte;
                 }
                 Cbox_test.push_back(c->isChecked());
                 Cbox_correcte.push_back(q[itr].isCorrect());
             }else{c->show();}
             ++itr;
         }


         size_t ss(Cbox_correcte.size());
         double note_cumulative;
         if (verifier_correcte==0){
             note_cumulative=0;
         }else{
             note_cumulative=1.0/verifier_correcte;
         }

         if (verifier_checked<=verifier_correcte){

             for (size_t i(0);i<ss;++i)
             {
                 if(Cbox_test[i] && Cbox_correcte[i])
                 {
                     note+=(note_cumulative);
                 }else if(Cbox_test[i] && !Cbox_correcte[i])
                 {
                     note-=(note_cumulative/2.0);
                 }
                 if(note<0)
                 {
                     note=0;
                 }
             }
         }
         ++counter;
         if (counter < questions.size()-1)
         {
             showQuestion(counter);
         } else {
             hide();
             string note_total;
             string note_n=to_string(note);
             string note_trasnformee="";
             bool avant_virgule=true;
             for(size_t i(0);i<note_n.size();++i){
                 if(note_n[i]!='.' && avant_virgule ){
                     note_trasnformee+=note_n[i];
                 }else if(note_n[i]=='.'){
                     note_trasnformee+=note_n[i];
                     avant_virgule=false;
                     if(note_n[i+1]=='0'){
                         note_trasnformee=note_n[i-1];
                         break;
                     }
                 }else if(note_n[i]!='0'){
                     note_trasnformee+=note_n[i];
                 }else{
                     break;
                 }
             }
             note_n=note_trasnformee;
             note_total=note_trasnformee+"/"+to_string(counter);
             QString counter_qs=ui->lineEdit_id->text();

             int counter_trunc=counter_qs.toInt()-1;

             ofstream quest_file;
             if(counter_trunc==0){
                 quest_file.open("Note.txt",ios::trunc);
             }else{ quest_file.open("Note.txt",ios::app);}


             quest_file<<name_etudiant+" : "<<note_total<<endl;
             quest_file<<"@#!"<<endl;

             quest_file.close();
             Users* users=new Users(this);
             users->show();

         }

     }
}
void MainWindow::showtime_t()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");

    if((time.second() % 2)==0)
    {
        time_text[3]=' ';
        time_text[8]=' ';
    }

}
