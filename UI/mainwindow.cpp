#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    printScientists();

}

void MainWindow::printScientists()
{
    vector<string> temp;
    temp.push_back("name1");
    temp.push_back("name2");
    serviceobject.servStartDatabase();
    serviceobject.servReadSqlScientists("NAME");
    vector<scientist> tempSci = serviceobject.servGetSciVector();
    qDebug () << "something...";

    for (int i = 0; i < tempSci.size(); i++)
    {

        ui->databasePrint->setRowCount(tempSci.size());
        QString name = QString::fromStdString(serviceobject.servGetSciVector().at(i).getName());
        ui->databasePrint->setItem(i, 0, new QTableWidgetItem(name));

        QString gender;
        if (serviceobject.servGetSciVector().at(i).getGender() == 0)
        {
            gender = "Female";
        }
        else if (serviceobject.servGetSciVector().at(i).getGender() == 1)
        {
            gender = "Male";
        }
        else if (serviceobject.servGetSciVector().at(i).getGender() == 2)
        {
            gender = "Unspecified";
        }
        ui->databasePrint->setItem(i, 1, new QTableWidgetItem(gender));
        QString yob = QString::number(serviceobject.servGetSciVector().at(i).getYearOfBirth());
        ui->databasePrint->setItem(i, 2, new QTableWidgetItem(yob));
        QString yod = QString::number(serviceobject.servGetSciVector().at(i).getYearOfDeath());
        ui->databasePrint->setItem(i, 3, new QTableWidgetItem(yod));
        QString descr = QString::fromStdString(serviceobject.servGetSciVector().at(i).getDescription());
        ui->databasePrint->setItem(i, 4, new QTableWidgetItem(descr));
        QString link = QString::fromStdString(serviceobject.servGetSciVector().at(i).getLink());
        ui->databasePrint->setItem(i, 5, new QTableWidgetItem(link));
    }
}


vector<scientist> MainWindow::returnSciVector()
{
    serviceobject.servStartDatabase();
    return serviceobject.servGetSciVector();
    qDebug () << "fetching...";
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
    ui->statusbar->showMessage("Add new scientist", 5000);


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
