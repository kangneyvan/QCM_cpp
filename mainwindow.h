#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "question.h"
#include "reponse.h"
#include "note.h"
#include "users.h"
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void set_name(const string& name);
    ~MainWindow();



private slots:
    void on_valider_clicked();
    void showtime_t();


private:
    Ui::MainWindow *ui;
    string name_etudiant;
    void showQuestion(size_t i);

    std::vector<Question> questions;
    size_t counter;
    double note=0;




};
#endif // MAINWINDOW_H
