#ifndef GESTIONQUESTION_H
#define GESTIONQUESTION_H

#include <QDialog>

namespace Ui {
class GestionQuestion;
}

class GestionQuestion : public QDialog
{
    Q_OBJECT

public:
    explicit GestionQuestion(QWidget *parent = nullptr);
    ~GestionQuestion();

private:
    Ui::GestionQuestion *ui;
};

#endif // GESTIONQUESTION_H
