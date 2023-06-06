#ifndef AJOUTENSEIGNANT_H
#define AJOUTENSEIGNANT_H

#include <QDialog>

namespace Ui {
class ajoutenseignant;
}

class ajoutenseignant : public QDialog
{
    Q_OBJECT

public:
    explicit ajoutenseignant(QWidget *parent = nullptr);
    ~ajoutenseignant();

private slots:
    void on_ajouter_clicked();

    void on_exit_clicked();

private:
    Ui::ajoutenseignant *ui;
    int counter_trunc=0;
};

#endif // AJOUTENSEIGNANT_H
