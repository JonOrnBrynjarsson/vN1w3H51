#ifndef ADDRELATIONS_H
#define ADDRELATIONS_H

//#include <QDialog>
#include <vector>
#include "Services/service.h"
//#include <QDebug>
//#include <QMenu>
//#include <QMouseEvent>
//#include "DataLayer/workingclass.h"
//#include "addnewscientist.h"
//#include "addnewcomputer.h"
//#include "addnewcomputertype.h"
//#include "addrelations.h"
#include "mainwindow.h"
//#include <vector>
//#include <QTableWidget>
//#include <QActionGroup>

using namespace std;

namespace Ui {
class addrelations;
}

class addrelations : public QDialog
{
    Q_OBJECT

public:
    explicit addrelations(QWidget *parent = 0);
    QString getCurrentSciRowPos(QString &name);
    //  Postcondition:  Returns the real ID number of selected scientist type.
    QString getCurrentComRowPos(QString &name);
    //  Postcondition:  Returns the real ID number of selected computer type.
    ~addrelations();

private slots:
   // void on_actionDisplay_a_List_of_Computers_triggered();
    void on_buttonBox_accepted();
    //  Precondition:   User has selected relations to add.
    //  Postcondition:  If relations are accepted, they are pushed to the database.
    void on_lineEdit_filterScieentistAddRelation_textEdited(const QString &arg1);
    //  Precondition:   User is about to filter scientist list
    //  Postcondition:  List has been filtered.
    void on_lineEdit_filteComputersAddRelation_textEdited(const QString &arg1);
    //  Precondition:   User is about to filter computers list
    //  Postcondition:  List has been filtered.

private:
    //void displayAllScientists();
    void printScientists();//(std::vector<scientist> returnSciVector());
    //  Precondition:  User is about to view list of scientists
    //  Postcondition:  Reads scientists from SQL database and prints it on screen.
    void printComputers();
    //  Precondition:  User is about to view list of computers
    //  Postcondition:  Reads computers from SQL database and prints it on screen.
    Ui::addrelations *ui;
    //ui pointer
    service serviceobject;
    //Object for serviceclass.
};

#endif // ADDRELATIONS_H

