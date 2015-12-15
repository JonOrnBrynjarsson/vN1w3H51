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
    //object for scientist model
    service serviceobject;
    //object for service class
    void neweditscientist(QString id, bool edit);
    //Facilitates viewing and editing of scientist information.
    ~addNewScientist();

private slots:
    /*
    ##  Triggers
    ##---------------------------------------------------------------------------------------##
    */
    bool on_lineEdit_name_editingFinished();
    //  Precondition:  User has clicked / edited the name box.
    //  Postcondition:  Returns error if name is not properly formatted.
    bool on_dateEdit_yod_editingFinished();
    //  Precondition:  User has clicked / edited the year of death box.
    //  Postcondition:  Returns error if year is not properly formatted.
    bool on_dateEdit_yob_editingFinished();
    //  Precondition:  User has clicked / year of birth the name box.
    //  Postcondition:  Returns error if year is not properly formatted.
    /*
    ##  Buttons and Boxes
    ##---------------------------------------------------------------------------------------##
    */
    void on_newOkCancel_New_accepted();
    //  Precondition:   User has inputed information for a new scientist
    //  Postcondition:  If input is accepted, it is pushed to the database.
    void on_newOkCancel_New_rejected();
    //  Precondition:   User has cancelled his input
    //  Postcondition:  Modal is closed.
    void on_newOkCancel_Edit_accepted();
    //  Precondition:   User has inputed information for editing a scientist
    //  Postcondition:  If input is accepted, it overrides excisting info in the database.
    void on_newOkCancel_Edit_rejected();
    //  Precondition:   User has cancelled his input
    //  Postcondition:  Modal is closed.
    void on_checkBox_stillAlive_toggled(bool checked);
    //  Precondition:   User can choose wether the scientist is alive or not.
    //  Postcondition:  Returns true or false.

private:
    Ui::addNewScientist *ui;
    void neweditscientistRelations(int currentID);
    //Finds relations for scientists and computers.
    void neweditscientistClickableLink(QString link);
    //Creates a clickable link for viewing scientist.
};

#endif // ADDNEWSCIENTIST_H
