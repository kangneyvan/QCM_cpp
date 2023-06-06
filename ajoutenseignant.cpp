#include "ajoutenseignant.h"
#include "ui_ajoutenseignant.h"
#include <fstream>
#include <iostream>
#include <QString>
#include <QMessageBox>
using namespace std;

ajoutenseignant::ajoutenseignant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajoutenseignant)
{
    ui->setupUi(this);
}

ajoutenseignant::~ajoutenseignant()
{
    delete ui;
}

void ajoutenseignant::on_ajouter_clicked()
{
    QString name=ui->name_edit->text();
    string name_trs=name.toStdString();

    QString pass=ui->pass_edit->text();
    string pass_trs=pass.toStdString();

    ofstream quest_file;

     if(counter_trunc==0)
     {
        quest_file.open("enseignants.txt",ios::trunc);
     } else{ quest_file.open("enseignants.txt",ios::app);}

     if(name_trs=="" || pass_trs==""){
         QMessageBox::information(this,"WARNING!!","Vous avez oubliez d'ajouter un enseignant");
     }
     else{
         quest_file<<"*"+name_trs<<endl;
         quest_file<<"{"+pass_trs<<endl;
         ui->name_edit->setText("");
         ui->pass_edit->setText("");
         QMessageBox::information(this,"saved","teacher has been saved");
          ++counter_trunc;
     }
     quest_file.close();
}


void ajoutenseignant::on_exit_clicked()
{
    string question_rep="enseignants.txt";
    ifstream myfile(question_rep);
    string buffer;
    getline(myfile,buffer);

    if(buffer=="")
    {
        QMessageBox::information(this,"DANGER DANGER!!!","Not a single teacher has been added");
    }else
    {
        close();
        QMessageBox::information(this,"DANGER DANGER!!!","ALL teachers are saved.\n No more modifications are allowed!!!");
    }
    myfile.close();
}

