#include "mainwindow.h"
#include "loginpage.h"
#include <QApplication>


//jean_yves youssef 182422
//michel khoury  182053
//michel haddad  180617

//please note to access the adminstraor page : name:admin    password:admin
//please note to take the quiz, students must be added in the "ajouter etudiants button"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginPage l;
    l.show();
    return a.exec();
}
