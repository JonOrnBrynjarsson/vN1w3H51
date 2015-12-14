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
#include <QAction>

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
    QString getCurrentSciRowPos();
    QString getCurrentComRowPos();
    QString getCurrentComTypeRowPos();
    void getCurrentRelationsRowPos(int &compos, int &scipos);

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

    void on_actionHelp_triggered();

    void on_actionAbout_Computers_and_Scientists_Database_triggered();

    //void on_MainMenuSelection_tabBarClicked(int index);

    void on_pushButon_addNewCompuer_clicked();

    void on_pushButton_removeCompuer_clicked();

    void on_databaseDisplayComputers_doubleClicked();


    void on_comboBox_filterComputers_currentIndexChanged(int index);

    void on_lineEdit_filterComputers_textEdited(const QString &arg1);

    void on_pushButton_editCompuer_clicked();

    void on_databaseDisplayComSci_doubleClicked();//const QModelIndex &index);

    void on_pushButton_addnewType_clicked();

    void on_comboBox_filterRelations_currentIndexChanged(const QString &arg1);

    void on_lineEdit_filterRelations_textEdited(const QString &arg1);

    void on_comboBox_filterComputerTypes_currentIndexChanged(const QString &arg1);

    void on_lineEdit_filterComputerTypes_textEdited(const QString &arg1);

    void on_databaseDisplayComTypes_doubleClicked();//const QModelIndex &index);

    void on_comboBox_filterScientist_currentIndexChanged(const QString &arg1);

    void on_lineEdit_filterScientist_textEdited(const QString &arg1);

    void on_MainMenuSelection_currentChanged(int index);

    void setAllMainMenuSelectionDisabled();

    void on_pushButon_addNewScientist_clicked();

    void on_pushButton_editScientist_clicked();

    void on_pushButton_removeScientist_clicked();

    void on_pushButon_addNewCompuerTypes_clicked();

    void on_pushButton_editComputerTypes_clicked();

    void on_pushButton_removeCompuerTypes_clicked();


    void on_pushButon_addNewRelations_clicked();

    void on_pushButton_removeRelations_clicked();

    void on_actionView_scientist_triggered();

    void on_actionView_computer_triggered();

    void on_actionView_computer_type_triggered();

    void on_databaseDisplayComSci_customContextMenuRequested(const QPoint &pos);

    void on_databaseDisplayComputers_customContextMenuRequested(const QPoint &pos);

    void on_databaseDisplayComTypes_customContextMenuRequested(const QPoint &pos);

    void on_tableWidget_displayRelations_customContextMenuRequested(const QPoint &pos);


private:
    void displayRelations();
    //service service;
    Ui::MainWindow *ui;
    addNewScientist *anscientist;
    vector<scientist> returnSciVector();
    service serviceobject;
    vector<computer> returnComVector();
    vector<computertype> returnComTypeVector();
    bool computerTypeCanBeDeleted(int compTypeID);
    QTableWidget* m_pTableWidget;

    QStringList m_TableHeader;

};

#endif // MAINWINDOW_H
