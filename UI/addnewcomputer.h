#ifndef ADDNEWCOMPUTER_H
#define ADDNEWCOMPUTER_H

#include <QDialog>

namespace Ui {
class addnewcomputer;
}

class addnewcomputer : public QDialog
{
    Q_OBJECT

public:
    explicit addnewcomputer(QWidget *parent = 0);
    ~addnewcomputer();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addnewcomputer *ui;
};

#endif // ADDNEWCOMPUTER_H
