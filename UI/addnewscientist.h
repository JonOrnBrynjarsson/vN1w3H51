#ifndef ADDNEWSCIENTIST_H
#define ADDNEWSCIENTIST_H

#include <QDialog>

namespace Ui {
class addNewScientist;
}

class addNewScientist : public QDialog
{
    Q_OBJECT

public:
    explicit addNewScientist(QWidget *parent = 0);
    ~addNewScientist();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addNewScientist *ui;
};

#endif // ADDNEWSCIENTIST_H
