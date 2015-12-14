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
    void addScientistToDatabase(scientist &sc);
    void neweditscientist(QString id, bool edit);
    void neweditscientistRelations(int currentID);
    void neweditscientistClickableLink(QString link);
    ~addNewScientist();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_editScientist_accepted();

    void on_buttonBox_editScientist_rejected();

private:
    Ui::addNewScientist *ui;

    void addScientistErrorCorrection(scientist &s);
};

#endif // ADDNEWSCIENTIST_H
