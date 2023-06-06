#include "matiere.h"
#include "ui_matiere.h"
#include <fstream>
#include <iostream>
#include <QString>
#include <QMessageBox>
using namespace std;

Matiere::Matiere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Matiere)
{
    ui->setupUi(this);
}

int idMatiere = 1;

Matiere::~Matiere()
{
    delete ui;
}

void Matiere::on_pushButton_clicked()
{

    QString name= ui->EditMatiere->text();
    string matiere=name.toStdString();

        ofstream quest_file;

        if(counter_trunc==0)
        {
            quest_file.open("matiere.txt",ios::trunc);
        } else{ quest_file.open("matiere.txt",ios::app);}

        if(matiere==""){
            QMessageBox::information(this,"WARNING!!","Vous avez oubliez d'ajouter une matière");
        }
        else{
            idMatiere++;
            quest_file<<matiere<<endl;
            ui->EditMatiere->setText("");
            QMessageBox::information(this,"saved","Subjet has been saved");
            ++counter_trunc;
        }
        quest_file.close();
}



void Matiere::on_exitMatiere_clicked()
{
    string question_rep="matiere.txt";
        ifstream myfile(question_rep);
        string buffer;
        getline(myfile,buffer);

        if(buffer=="")
        {
            QMessageBox::information(this,"DANGER DANGER!!!","Not a single Subjet has been added");
        }else
        {
            close();
            QMessageBox::information(this,"DANGER DANGER!!!","ALL Subjets are saved.\n No more modifications are allowed!!!");
        }
        myfile.close();
}

