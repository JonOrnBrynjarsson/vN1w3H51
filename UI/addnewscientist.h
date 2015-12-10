#ifndef ADDNEWSCIENTIST_H
#define ADDNEWSCIENTIST_H

#include <QDialog>
#include <string>
#include <QMessageBox>
#include <QTextStream>
#include "models/scientist.h"
#include "Services/service.h"
#include "Services/scientistserviceclass.h"

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

    void on_lineEdit_name_editingFinished();

    void on_lineEdit_name_textChanged(const QString &arg1);

    void on_buttonBox_rejected();

    void on_lineEdit_name_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_name_selectionChanged();

private:
    Ui::addNewScientist *ui;
    void addScientistToDatabase(scientist &s);
    void addScientistErrorCorrection(scientist &s);
};

#endif // ADDNEWSCIENTIST_H
