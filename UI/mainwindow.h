#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMenu>
#include <QMouseEvent>
#include "addnewscientist.h"
#include "addnewcomputer.h"
#include "addnewcomputertype.h"
#include "addrelations.h"
#include "editcomputer.h"
#include "Services/service.h"

#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void printScientists();
    void printComputers();
    void printComputerTypes();
    QString getCurrentRowPos();
    ~MainWindow();

private slots:
    void on_actionAdd_New_Computer_Scientist_triggered();

    void on_actionAdd_New_Computer_triggered();

    void on_actionAdd_New_Computer_Type_triggered();

    void on_actionAdd_Relations_triggered();

    void on_actionEdit_a_Computer_Scientist_triggered();

    void on_actionEdit_a_Computer_triggered();

    void on_actionEdit_a_Computer_Type_triggered();

    void on_actionRemove_a_Computer_Scientist_triggered();

    void on_actionRemove_a_Computer_triggered();

    void on_actionRemove_a_Computer_Type_triggered();

    void on_actionRemove_Relations_triggered();

    void on_actionDisplay_a_List_of_Computer_Scientists_triggered();

    void on_actionDisplay_a_List_of_Computers_triggered();

    void on_actionDisplay_a_List_of_Computer_Types_triggered();

    void on_actionHelp_triggered();

    void on_actionAbout_Computers_and_Scientists_Database_triggered();

    void on_MainMenuSelection_tabBarClicked(int index);

    void on_databaseDisplayComSci_cellClicked(int row, int column);


    void on_pushButon_addNewCompuer_clicked();

    void on_pushButton_removeCompuer_clicked();

    void on_databaseDisplayComputers_doubleClicked(const QModelIndex &index);

    void on_pushButton_editCompuer_clicked();

private:
    void displayRelations();
    //service service;
    Ui::MainWindow *ui;
    addNewScientist *anscientist;
    vector<scientist> returnSciVector();
    service serviceobject;
    vector<computer> returnComVector();
    vector<computertype> returnComTypeVector();

    QTableWidget* m_pTableWidget;

    QStringList m_TableHeader;

};

#endif // MAINWINDOW_H
