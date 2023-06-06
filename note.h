#ifndef NOTE_H
#define NOTE_H

#include <QDialog>

namespace Ui {
class NOTE;
}

class NOTE : public QDialog
{
    Q_OBJECT

public:
    explicit NOTE(QWidget *parent = nullptr);
    ~NOTE();

private slots:
    void on_EXIT_clicked();

private:
    Ui::NOTE *ui;

};

#endif // NOTE_H
