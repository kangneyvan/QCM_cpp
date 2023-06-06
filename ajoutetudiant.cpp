#include "ajoutetudiant.h"
#include "ui_ajoutetudiant.h"
#include <fstream>
#include <iostream>
#include <QString>
#include <QMessageBox>
using namespace std;

AjoutEtudiant::AjoutEtudiant(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutEtudiant)
{
    ui->setupUi(this);
}

AjoutEtudiant::~AjoutEtudiant()
{
    delete ui;
}

void AjoutEtudiant::on_ajouter_clicked()
{
    QString name=ui->name_edit->text();
    string name_trs=name.toStdString();

    QString pass=ui->pass_edit->text();
    string pass_trs=pass.toStdString();

    ofstream quest_file;

     if(counter_trunc==0)
     {
        quest_file.open("etudiants.txt",ios::trunc);
     } else{ quest_file.open("etudiants.txt",ios::app);}

     if(name_trs=="" || pass_trs==""){
         QMessageBox::information(this,"WARNING!!","Vous avez oubliez d'ajouter un etudiant");
     }
     else{
         quest_file<<"*"+name_trs<<endl;
         quest_file<<"{"+pass_trs<<endl;
         ui->name_edit->setText("");
         ui->pass_edit->setText("");
         QMessageBox::information(this,"saved","student has been saved");
          ++counter_trunc;
     }
     quest_file.close();
}


void AjoutEtudiant::on_exit_clicked()
{
    string question_rep="etudiants.txt";
    ifstream myfile(question_rep);
    string buffer;
    getline(myfile,buffer);

    if(buffer=="")
    {
        QMessageBox::information(this,"DANGER DANGER!!!","Not a single student has been added");
    }else
    {
        close();
        QMessageBox::information(this,"DANGER DANGER!!!","ALL Students are saved.\n No more modifications are allowed!!!");
    }
    myfile.close();
}

