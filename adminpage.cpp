#include "adminpage.h"
#include "ui_adminpage.h"
#include <fstream>
#include <iostream>
#include <QString>
#include <QMessageBox>
using namespace std;


AdminPage::AdminPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);
}

AdminPage::~AdminPage()
{
    delete ui;
}


void AdminPage::on_add_etudiant_clicked()
{
    AjoutEtudiant* admin= new AjoutEtudiant(this);
    admin->show();
}

void AdminPage::on_exit_clicked()
{
    close();

}

void AdminPage::on_add_enseignant_clicked()
{
    ajoutenseignant* admin = new ajoutenseignant(this);
    admin->show();
}



void AdminPage::on_createMatiere_clicked()
{
    Matiere* mat = new Matiere(this);
    mat->show();
}

