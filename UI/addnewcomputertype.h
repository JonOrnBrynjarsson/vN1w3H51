#ifndef ADDNEWCOMPUTERTYPE_H
#define ADDNEWCOMPUTERTYPE_H

#include <QDialog>
//#include <string>
#include <QMessageBox>
//#include <QTextStream>
//#include "models/computertype.h"
#include "Services/service.h"
//#include "computertypeuiclass.h"

namespace Ui
{
    class addnewcomputertype;
}

class addnewcomputertype : public QDialog
{
    Q_OBJECT

public:
    explicit addnewcomputertype(QWidget *parent = 0);
    //constructor
    void neweditcomputertype(QString id, bool edit);
    //Facilitates viewing and editing of computer information.

    ~addnewcomputertype();

private slots:

    /*
    ##  Triggers
    ##---------------------------------------------------------------------------------------##
    */
    bool on_lineEdit_name_editingFinished();
    //  Precondition:   User has clicked / edited the name box.
    //  Postcondition:  Returns error if name is not properly formatted.

    /*
    ##  Buttons and Boxes
    ##---------------------------------------------------------------------------------------##
    */
    void on_newOkCancel_New_accepted();
    //  Precondition:   User has inputed information for a new computer type
    //  Postcondition:  If input is accepted, it is pushed to the database.
    void on_newOkCancel_New_rejected();
    //  Precondition:   User has cancelled his input
    //  Postcondition:  Modal is closed.
    void on_newOkCancel_Edit_accepted();
    //  Precondition:   User has inputed information for editing a computer type
    //  Postcondition:  If input is accepted, it overrides excisting info in the database.
    void on_newOkCancel_Edit_rejected();
    //  Precondition:   User has cancelled his input
    //  Postcondition:  Modal is closed.

private:
    Ui::addnewcomputertype *ui;
    //ui pointer
    computertype ct;
    //object for computertype model
    service serviceObject;
    //object for service class
    void viewingMode();

};

#endif // ADDNEWCOMPUTERTYPE_H
//int inputNumberToFunction(string input);
//void addCompTypetoDB(computertype &ct);
//void addCompTypeErrCorr(computertype &ct);
//void on_buttonBox_Editcomtype_rejected();
//void on_buttonBox_accepted();
//void on_buttonBox_Editcomtype_accepted();
