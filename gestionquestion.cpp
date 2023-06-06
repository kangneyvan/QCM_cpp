include "gestionquestion.h"
#include "ui_gestionquestion.h"

GestionQuestion::GestionQuestion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionQuestion)
{
    ui->setupUi(this);
}

GestionQuestion::~GestionQuestion()
{
    delete ui;
}
