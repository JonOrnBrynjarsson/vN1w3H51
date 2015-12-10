#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
