#ifndef ADDNEWCOMPUTER_H
#define ADDNEWCOMPUTER_H

#include <QDialog>
//#include <QDebug>
//#include <QVariant>
#include <Services/service.h>
#include <qmessagebox.h>
//#include <QDebug>
//#include "mainwindow.h"

namespace Ui {
class addnewcomputer;
}

class addnewcomputer : public QDialog
{
    Q_OBJECT

public:
    explicit addnewcomputer(QWidget *parent = 0);
    //constructor
    void neweditcomputer(QString id, bool edit);
    //Facilitates viewing and editing of computer information.
    void neweditcomputerRelations(int currentID);
    //Finds relations for computers and scientist.
    ~addnewcomputer();

private slots:

    /*
    ##  Triggers
    ##---------------------------------------------------------------------------------------##
    */

    bool on_lineEdit_insertName_editingFinished();
    //  Precondition:   User has clicked / edited the name box.
    //  Postcondition:  Returns error if name is not properly formatted.
    bool on_dateEdit_yoc_editingFinished();
    //  Precondition:   User has clicked / edited the year box.
    //  Postcondition:  Returns error if year is not properly formatted.



    /*
    ##  Buttons and Boxes
    ##---------------------------------------------------------------------------------------##
    */
    void on_newOkCancel_New_accepted();
    //  Precondition:   User has inputed information for a new computer
    //  Postcondition:  If input is accepted, it is pushed to the database.
    void on_newOkCancel_New_rejected();
    //  Precondition:   User has cancelled his input
    //  Postcondition:  Modal is closed.
    void on_newOkCancel_Edit_accepted();
    //  Precondition:   User has inputed information for a new computer
    //  Postcondition:  If input is accepted, it is pushed to the database.
    void on_newOkCancel_Edit_rejected();
    //  Precondition:   User has cancelled his input
    //  Postcondition:  Modal is closed.


private:
    Ui::addnewcomputer *ui;
    //ui pointer
    service serviceObject;
    //object for service class
    void viewingMode(int currentID);
};

#endif // ADDNEWCOMPUTER_H
//void on_buttonBox_editComputerFinished_accepted();
//void on_buttonBox_editComputerFinished_rejected();
//bool on_lineEdit_enterYear_editingFinished();
//void on_buttonBox_addNewComputerFinished_accepted();
