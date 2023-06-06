#ifndef MAKETEST_H
#define MAKETEST_H

#include <QDialog>
#include "question.h"


namespace Ui {
class MakeTest;
}

class MakeTest : public QDialog
{
    Q_OBJECT

public:
    explicit MakeTest(QWidget *parent = nullptr);

    ~MakeTest();

private slots:
    void on_pushButton_add_clicked();

    void on_pushButton_exit_clicked();

    void showtime_m();


    void on_comboBoxMatiere_activated(const QString &arg1);

private:
    Ui::MakeTest *ui;
    int counter_trunc=0;

};

#endif // MAKETEST_H
