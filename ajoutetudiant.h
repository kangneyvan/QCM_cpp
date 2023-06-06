#ifndef AJOUTETUDIANT_H
#define AJOUTETUDIANT_H

#include <QDialog>


namespace Ui {
class AjoutEtudiant;
}

class AjoutEtudiant : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutEtudiant(QWidget *parent = nullptr);
    ~AjoutEtudiant();

private slots:
    void on_ajouter_clicked();


    void on_exit_clicked();

private:
    Ui::AjoutEtudiant *ui;
    int counter_trunc=0;
};

#endif // AJOUTETUDIANT_H
