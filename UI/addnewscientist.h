#ifndef ADDNEWSCIENTIST_H
#define ADDNEWSCIENTIST_H

#include <QDialog>
#include <string>
#include <QMessageBox>
#include <QTextStream>
#include "models/scientist.h"
#include "Services/service.h"
#include "scientistuiclass.h"

namespace Ui {
class addNewScientist;
}

class addNewScientist : public QDialog
{
    Q_OBJECT

public:
    explicit addNewScientist(QWidget *parent = 0);
    scientist s;
    service serviceobject;
    int inputNumberToFunction(string input);

    ~addNewScientist();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addNewScientist *ui;
    void addScientistToDatabase(scientist &s);
    void addScientistErrorCorrection(scientist &s);
};

#endif // ADDNEWSCIENTIST_H
