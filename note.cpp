#include "note.h"
#include "ui_note.h"
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
#include <QDate>
using namespace std;

NOTE::NOTE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NOTE)
{
    ui->setupUi(this);
    string question_rep="Note.txt";
    ifstream myfile(question_rep);
    string buffer;
    string cumulative_string;
    try {
      if(myfile.is_open())
      {
          int counter(1);
          while(myfile.good())
          {
              string t=to_string(counter);
            getline(myfile,buffer);

             if (buffer=="@#!")
                {
                    continue;
                }else{
                    cumulative_string+=buffer+"\n";
             }
            }
          myfile.close();
        }else{
              throw string("the path or the file is incorect");
          }
       }

      catch(const string & msg){
          cerr<<msg<<endl;
      }
    QString label_note=QString::fromStdString(cumulative_string);
    ui->note_text->setText(label_note);

    QDateTime datetime=QDateTime::currentDateTime();
    QString datetime_text=datetime.toString();

    ui->label_date->setText(datetime_text);

}


NOTE::~NOTE()
{
    delete ui;
}

void NOTE::on_EXIT_clicked()
{
   /* ofstream quest_file;
    quest_file.open("Note.txt",ios::trunc);
    quest_file.close();*/
    QMessageBox::information(this,"FIN QCM","BONNE VACANCES!!!");
    exit(0);
}
