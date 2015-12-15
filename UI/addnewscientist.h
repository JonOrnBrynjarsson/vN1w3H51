#ifndef ADDNEWSCIENTIST_H
#define ADDNEWSCIENTIST_H

#include <QDialog>
#include <string>
#include <QMessageBox>
#include <QTextStream>
#include "models/scientist.h"
#include "Services/service.h"

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
    void neweditscientist(QString id, bool edit);
    //int inputNumberToFunction(string input);
    //void addScientistToDatabase(scientist &sc);
    ~addNewScientist();

private slots:
    //void on_buttonBox_accepted();
    //void on_buttonBox_editScientist_accepted();
    //void on_buttonBox_editScientist_rejected();
    bool on_lineEdit_name_editingFinished();
    //bool on_lineEdit_yob_editingFinished();
    //bool on_lineEdit_yod_editingFinished();
    bool on_dateEdit_yod_editingFinished();
    void on_newOkCancel_New_accepted();
    void on_newOkCancel_New_rejected();
    void on_newOkCancel_Edit_accepted();
    void on_newOkCancel_Edit_rejected();
    void on_checkBox_stillAlive_toggled(bool checked);

    bool on_dateEdit_yob_editingFinished();

private:
    Ui::addNewScientist *ui;
    void neweditscientistRelations(int currentID);
    void neweditscientistClickableLink(QString link);
    //void addScientistErrorCorrection(scientist &s);
};

#endif // ADDNEWSCIENTIST_H
