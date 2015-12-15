#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMenu>
#include <QMouseEvent>
#include "aboutcreators.h"
#include "addnewscientist.h"
#include "addnewcomputer.h"
#include "addnewcomputertype.h"
#include "addrelations.h"
//#include "editcomputer.h"
#include "Services/service.h"
#include "help.h"
#include <QModelIndex>
#include <math.h>
#include <QTableWidget>
#include <QAction>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    /*
    ##  Scientists Slots
    ##---------------------------------------------------------------------------------------##
    */
    void on_lineEdit_filterScientist_textEdited(const QString &arg1);
    //  Precondition:   User is about to filter scientist list
    //  Postcondition:  List has been filtered.
    void on_actionView_scientist_triggered();
    //  Postcondition:  Displays more detail about scientist
    void on_databaseDisplayComSci_doubleClicked();//const QModelIndex &index);
    //  Postcondition:  Displays more detail about scientist
    void on_databaseDisplayComSci_customContextMenuRequested(const QPoint &pos);
    //  Postcondition:  Provides context menu for scientist.



    /*
    ##  Scientists Slots##Action Bar
    ##---------------------------------------------------------------------------------------##
    */
    void on_actionAdd_New_Computer_Scientist_triggered();
    //  Postcondition:  Add new scientist menu is displayed.
    void on_actionEdit_a_Computer_Scientist_triggered();
    //  Postcondition:  Edit a scientist menu is displayed.
    void on_actionRemove_a_Computer_Scientist_triggered();
    //  Postcondition:  Remove a scientist is presented.

    /*
    ##  Scientists Slots##Buttons and Boxes
    ##---------------------------------------------------------------------------------------##
    */
    void on_comboBox_filterScientist_currentIndexChanged(const QString &arg1);
    //  Postcondition:  The filter box is cleared
    void on_pushButon_addNewScientist_clicked();
    //  Postcondition:  Add new scientist menu is displayed.
    void on_pushButton_editScientist_clicked();
    //  Postcondition:  Edit a scientist menu is displayed.
    void on_pushButton_removeScientist_clicked();
    //  Postcondition:  Remove a scientist is presented.

    /*
    ##  Computers Slots
    ##---------------------------------------------------------------------------------------##
    */
    void on_databaseDisplayComputers_doubleClicked();
    //  Postcondition:  Displays more detail about the computer
    void on_lineEdit_filterComputers_textEdited(const QString &arg1);
    //  Precondition:   User is about to filter computers list
    //  Postcondition:  List has been filtered.
    void on_actionView_computer_triggered();
    //  Postcondition:  Displays more detail about computer
    void on_databaseDisplayComputers_customContextMenuRequested(const QPoint &pos);
    //  Postcondition:  Provides context menu for computer.

    /*
    ##  Computers Slots##Action Bar
    ##---------------------------------------------------------------------------------------##
    */
    void on_actionAdd_New_Computer_triggered();
    //  Postcondition:  Add new computer menu is displayed.
    void on_actionEdit_a_Computer_triggered();
    //  Postcondition:  Edit a computer menu is displayed.
    void on_actionRemove_a_Computer_triggered();
    //  Postcondition:  Remove a computer is presented.

    /*
    ##  Computers Slots##Buttons and Boxes
    ##---------------------------------------------------------------------------------------##
    */
    void on_comboBox_filterComputers_currentIndexChanged(int index);
    //  Postcondition:  The filter box is cleared
    void on_pushButon_addNewCompuer_clicked();
    //  Postcondition:  Add new computer menu is displayed.
    void on_pushButton_editCompuer_clicked();
    //  Postcondition:  Edit a computer menu is displayed.
    void on_pushButton_removeCompuer_clicked();
    //  Postcondition:  Remove a computer is presented.

    /*
    ##  Computer Types Slots
    ##---------------------------------------------------------------------------------------##
    */
    void on_actionView_computer_type_triggered();
    //  Postcondition:  Displays more detail about computer
    void on_lineEdit_filterComputerTypes_textEdited(const QString &arg1);
    //  Precondition:   User is about to filter computer types list
    //  Postcondition:  List has been filtered.
    void on_databaseDisplayComTypes_doubleClicked();//const QModelIndex &index);
    //  Postcondition:  Displays more detail about the computer type.
    void on_databaseDisplayComTypes_customContextMenuRequested(const QPoint &pos);
    //  Postcondition:  Provides context menu for computer type.

    /*
    ##  Computer Types Slots##Action Bar
    ##---------------------------------------------------------------------------------------##
    */
    void on_actionAdd_New_Computer_Type_triggered();
    //  Postcondition:  Add new computer type menu is displayed.
    void on_actionEdit_a_Computer_Type_triggered();
    //  Postcondition:  Edit a computer type menu is displayed.
    void on_actionRemove_a_Computer_Type_triggered();
    //  Postcondition:  Remove a computer type is presented.

    /*
    ##  Computer Types Slots##Buttons and Boxes
    ##---------------------------------------------------------------------------------------##
    */
    void on_comboBox_filterComputerTypes_currentIndexChanged(const QString &arg1);
    //  Postcondition:  The filter box is cleared
    void on_pushButton_editComputerTypes_clicked();
    //  Postcondition:  Edit a computer type menu is displayed.
    void on_pushButon_addNewCompuerTypes_clicked();
    //  Postcondition:  Add a a computer type menu is displayed.
    void on_pushButton_removeCompuerTypes_clicked();
    //  Postcondition:  Remove a computer type is presented.


    /*
    ##  Relations Slots
    ##---------------------------------------------------------------------------------------##
    */
    void on_lineEdit_filterRelations_textEdited(const QString &arg1);
    //  Precondition:   User is about to filter relations list
    //  Postcondition:  List has been filtered.
    void on_tableWidget_displayRelations_customContextMenuRequested(const QPoint &pos);
    //  Postcondition:  Provides context menu for relations.


    /*
    ##  Relations Slots##Action Bar
    ##---------------------------------------------------------------------------------------##
    */
    void on_actionAdd_Relations_triggered();
    //  Postcondition:  Add new relations menu is displayed.
    void on_actionRemove_Relations_triggered();
    //  Postcondition:  remove relations menu is displayed.


    /*
    ##  Relations Slots##Buttons and Boxes
    ##---------------------------------------------------------------------------------------##
    */
    void on_comboBox_filterRelations_currentIndexChanged(const QString &arg1);
    //  Postcondition:  The filter box is cleared
    void on_pushButon_addNewRelations_clicked();
    //  Postcondition:  Add relations menu is displayed.
    void on_pushButton_removeRelations_clicked();
    //  Postcondition:  Remove relations is presented.


    /*
    ##  Miscellaneous
    ##---------------------------------------------------------------------------------------##
    */

    void on_actionHelp_triggered();
    //  Postcondition:  displays help.
    void on_actionAbout_Computers_and_Scientists_Database_triggered();
    //  Postcondition:  displays about.
    void setAllMainMenuSelectionDisabled();
    //  Postcondition:  sets all toolbar selections as disabled by default.
    void on_MainMenuSelection_currentChanged(int index);
    //  Precondition:  main window tab is about to be changed.
    //  Postcondition:  enables toolbars and prints for selected tab.

private:
    void displayRelations();
    Ui::MainWindow *ui;

    service serviceobject;

    /*
    ##  Display
    ##---------------------------------------------------------------------------------------##
    */
    void printScientists();
    //  Precondition:  User is about to view list of scientists
    //  Postcondition:  Reads scientists from SQL database and prints it on screen.
    void printComputers();
    //  Precondition:  User is about to view list of computers
    //  Postcondition:  Reads computers from SQL database and prints it on screen.
    void printComputerTypes();
    //  Precondition:  User is about to view list of computer types
    //  Postcondition:  Reads computer types from SQL database and prints it on screen.

    /*
    ##  Miscellaneous
    ##---------------------------------------------------------------------------------------##
    */

    QString getCurrentSciRowPos();
    //  Postcondition:  Returns the real ID number of selected scientist.
    QString getCurrentComRowPos();
    //  Postcondition:  Returns the real ID number of selected computer.
    QString getCurrentComTypeRowPos();
    //  Postcondition:  Returns the real ID number of selected computer type.
    void getCurrentRelationsRowPos(int &compos, int &scipos);
    //  Postcondition:  Computer id and Science id is returned as a variable.
    bool computerTypeCanBeDeleted(int compTypeID);
    //  Precondition:  Computer type is about to be deleted.
    //  Postcondition:  Returns if computer is in use or not, and could therefor
    //                  be deleted.
};

#endif // MAINWINDOW_H

//void on_MainMenuSelection_tabBarClicked(int index);
//void on_pushButton_addnewType_clicked();
//service service;
//addNewScientist *anscientist;
//vector<scientist> returnSciVector();
//vector<computer> returnComVector();
//vector<computertype> returnComTypeVector();

//QTableWidget* m_pTableWidget;
//QStringList m_TableHeader;
