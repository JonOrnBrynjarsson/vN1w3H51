#include "addrelations.h"
#include "ui_addrelations.h"
#include "mainwindow.h"
#include <vector>
//FORCE UPDATE!

addrelations::addrelations(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addrelations)
{
    serviceobject.servReadSqlScientists();
    serviceobject.servReadSqlComputers();
    ui->setupUi(this);
    printScientists();
    printComputers();
}

addrelations::~addrelations()
{
    delete ui;
}
void addrelations::printScientists()
{
    ui->tableWidget_chooseScientist->setSortingEnabled(false);
    ui->tableWidget_chooseScientist->setRowCount(serviceobject.servGetSciVector().size());

    for (unsigned int i = 0; i < serviceobject.servGetSciVector().size(); i++)
    {
        QString name = QString::fromStdString(serviceobject.servGetSciVector().at(i).getName());
        ui->tableWidget_chooseScientist->setItem(i, 0, new QTableWidgetItem(name));

        int currentID = serviceobject.servGetSciVector().at(i).getID();

        QString sciID = QString::number(serviceobject.servGetSciVector().at(i).getID());
        ui->tableWidget_chooseScientist->setItem(i, 1, new QTableWidgetItem(sciID));
    }
    QStringList sciHeader = (QStringList() << "Name" << "Scientist id");
    ui->tableWidget_chooseScientist->setHorizontalHeaderLabels(sciHeader);
    ui->tableWidget_chooseScientist->setSortingEnabled(true);
    //qDebug() << "on to the next...";

//    ui->tableWidget_chooseScientist->setColumnHidden(1, true); // FELUR ID!!!!
}

void addrelations::printComputers()
{

    ui->tableWidget_chooseComputer->setRowCount(serviceobject.servGetComVector().size());
    ui->tableWidget_chooseComputer->setSortingEnabled(false); // To be able to display headers and all column data - bugfix for qt.

    for (unsigned int i = 0; i < serviceobject.servGetComVector().size(); i++)
    {

        //name
        QString comName = QString::fromStdString(serviceobject.servGetComVector().at(i).getComName());
        ui->tableWidget_chooseComputer->setItem(i, 0, new QTableWidgetItem(comName));

        QString comID = QString::number(serviceobject.servGetComVector().at(i).getId());
        ui->tableWidget_chooseComputer->setItem(i, 1, new QTableWidgetItem(comID));
    }
    QStringList comHeader = (QStringList() << "Name" << "cID") ;
    ui->tableWidget_chooseComputer->setHorizontalHeaderLabels(comHeader);
    //ui->databaseDisplayComputers->horizontalHeader()-
    ui->tableWidget_chooseComputer->setSortingEnabled(true);// To be able to display headers and all column data - bugfix for qt.
    //ui->databaseDisplayComputers->setColumnHidden(1, true);  // Hides ID column
 //   ui->tableWidget_chooseComputer->setColumnHidden(1, true); // FELUR ID!!!!
}
