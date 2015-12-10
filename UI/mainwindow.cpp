#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_New_Computer_Scientist_triggered()
{
    //qDebug() << "Add_New_Computer_Scientist";
    addNewScientist newscientist;
    newscientist.setModal(true);
    newscientist.exec();
    newscientist.

}

void MainWindow::on_actionAdd_New_Computer_triggered()
{
    //qDebug() << "Add_New_Computer";
    addnewcomputer newcomputer;
    newcomputer.setModal(true);
    newcomputer.exec();
}

void MainWindow::on_actionAdd_New_Computer_Type_triggered()
{
    //qDebug() << "Add_New_Computer";
    addnewcomputertype computerype;
    computerype.setModal(true);
    computerype.exec();

}

void MainWindow::on_actionAdd_Relations_triggered()
{
    //qDebug() << "Add New Relations";
    addrelations relations;
    relations.setModal(true);
    relations.exec();
}

void MainWindow::on_actionEdit_a_Computer_Scientist_triggered()
{
    qDebug() << "Edit_a_Computer_Scientist";
}

void MainWindow::on_actionEdit_a_Computer_triggered()
{
    qDebug() << "Edit_a_Computer";
}

void MainWindow::on_actionEdit_a_Computer_Type_triggered()
{
    qDebug() << "Edit_a_Computer_Type";
}

void MainWindow::on_actionRemove_a_Computer_Scientist_triggered()
{
    qDebug() << "Remove_a_Computer_Scientist";
}

void MainWindow::on_actionRemove_a_Computer_triggered()
{
    qDebug() << "Remove_a_Computer";
}

void MainWindow::on_actionRemove_a_Computer_Type_triggered()
{
    qDebug() << "Remove_a_Computer_Type";
}

void MainWindow::on_actionRemove_Relations_triggered()
{
    qDebug() << "Remove_Relations";
}

void MainWindow::on_actionDisplay_a_List_of_Computer_Scientists_triggered()
{
    qDebug() << "Display_a_List_of_Computer_Scientists";
}

void MainWindow::on_actionDisplay_a_List_of_Computers_triggered()
{
    qDebug() << "Display_a_List_of_Computers";
}

void MainWindow::on_actionDisplay_a_List_of_Computer_Types_triggered()
{
    qDebug() << "Display_a_List_of_Computer_Types";
}

void MainWindow::on_actionHelp_triggered()
{
    qDebug() << "Help";
}

void MainWindow::on_actionAbout_Computers_and_Scientists_Database_triggered()
{
    qDebug() << "About_Computers_and_Scientists_Database";
}
