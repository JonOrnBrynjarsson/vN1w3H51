#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QModelIndex>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    serviceobject.servStartDatabase();
    serviceobject.servReadSqlScientists("NAME");
    serviceobject.servReadSqlComputers("NAME");
    serviceobject.servReadSqlCompTypes();


    ui->setupUi(this);
    //ui->tableView->setColumnHidden(5, true);
    printScientists();
    printComputers();
    printComputerTypes();
    ui->databaseDisplayComSci->setColumnHidden(7, true); // FELUR ID!!!!
    ui->databaseDisplayComputers->setColumnHidden(5, true); // FELUR ID!!!!



}

void MainWindow::printScientists()
{
    //serviceobject.servStartDatabase();
    //serviceobject.servReadSqlScientists("NAME");

    ui->databaseDisplayComSci->setRowCount(serviceobject.servGetSciVector().size());

    for (unsigned int i = 0; i < serviceobject.servGetSciVector().size(); i++)
    {
        QString name = QString::fromStdString(serviceobject.servGetSciVector().at(i).getName());
        ui->databaseDisplayComSci->setItem(i, 0, new QTableWidgetItem(name));

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
        ui->databaseDisplayComSci->setItem(i, 1, new QTableWidgetItem(gender));
        QString yob = QString::number(serviceobject.servGetSciVector().at(i).getYearOfBirth());
        ui->databaseDisplayComSci->setItem(i, 2, new QTableWidgetItem(yob));

        QString yod;
        if (serviceobject.servGetSciVector().at(i).getYearOfDeath() == 0)
        {
            yod = QString::null;
        }
        else
        {
            yod = QString::number(serviceobject.servGetSciVector().at(i).getYearOfDeath());
        }
        ui->databaseDisplayComSci->setItem(i, 3, new QTableWidgetItem(yod));
        QString descr = QString::fromStdString(serviceobject.servGetSciVector().at(i).getDescription());
        ui->databaseDisplayComSci->setItem(i, 4, new QTableWidgetItem(descr));
        QString link = QString::fromStdString(serviceobject.servGetSciVector().at(i).getLink());
        ui->databaseDisplayComSci->setItem(i, 5, new QTableWidgetItem(link));

        int currentID = serviceobject.servGetSciVector().at(i).getID();

        vector<computer> sciLinkedToCom = serviceobject.servGetComputersLinkedToScientists(currentID);

        //qDebug() << "doinit i is: " << " " << i+1 ;

        QString linkedComputers;
        string outoffunc;
        for (unsigned int x = 0; x < sciLinkedToCom.size(); x++)
        {
            string space = " ";
            string temp;
            temp = sciLinkedToCom.at(x).getComName();

            if (sciLinkedToCom.size() > 1)
            {
                outoffunc += temp + space;
            }
            else
            {
                outoffunc = temp;
            }
        }
        linkedComputers = QString::fromStdString(outoffunc);
        ui->databaseDisplayComSci->setItem(i, 6, new QTableWidgetItem(linkedComputers));

        QString sciID = QString::number(serviceobject.servGetSciVector().at(i).getID());
        ui->databaseDisplayComSci->setItem(i, 7, new QTableWidgetItem(sciID));
    }
}

void MainWindow::printComputers()
{

    ui->databaseDisplayComputers->setRowCount(serviceobject.servGetComVector().size());

    for (unsigned int i = 0; i < serviceobject.servGetComVector().size(); i++)
    {

        //name+ year type+ built+ description
        QString comName = QString::fromStdString(serviceobject.servGetComVector().at(i).getComName());
        ui->databaseDisplayComputers->setItem(i, 0, new QTableWidgetItem(comName));
        QString comBuilt;
        if (serviceobject.servGetComVector().at(i).getComBuilt() == true)
        {
            comBuilt = "Yes";
        }
        else if (serviceobject.servGetComVector().at(i).getComBuilt() == false)
        {
            comBuilt = "No";
        }
        ui->databaseDisplayComputers->setItem(i, 3, new QTableWidgetItem(comBuilt));

        int comTypeInt = serviceobject.servGetComVector().at(i).getComType();
        QString ComType;
        ComType = QString::fromStdString(serviceobject.servGetCompTypeVector().at(comTypeInt-1).getName());
        ui->databaseDisplayComputers->setItem(i, 2, new QTableWidgetItem(ComType));

        QString comYear = QString::number(serviceobject.servGetComVector().at(i).getComYear());
        ui->databaseDisplayComputers->setItem(i, 1, new QTableWidgetItem(comYear));

        QString comDescr = QString::fromStdString(serviceobject.servGetComVector().at(i).getComDescription());
        ui->databaseDisplayComputers->setItem(i, 4, new QTableWidgetItem(comDescr));

        QString comID = QString::number(serviceobject.servGetComVector().at(i).getId());
        ui->databaseDisplayComputers->setItem(i, 5, new QTableWidgetItem(comID));

    }
}

void MainWindow::printComputerTypes()
{
    ui->databaseDisplayComTypes->setRowCount(serviceobject.servGetCompTypeVector().size());

    for (unsigned int i = 0; i < serviceobject.servGetCompTypeVector().size(); i++)
    {
        QString comTName = QString::fromStdString(serviceobject.servGetCompTypeVector().at(i).getName());
        ui->databaseDisplayComTypes->setItem(i, 0, new QTableWidgetItem(comTName));

        QString comTDescr = QString::fromStdString(serviceobject.servGetCompTypeVector().at(i).getDesc());
        ui->databaseDisplayComTypes->setItem(i, 1, new QTableWidgetItem(comTDescr));
    }
}

vector<scientist> MainWindow::returnSciVector()
{
    serviceobject.servStartDatabase();
    return serviceobject.servGetSciVector();
    //qDebug () << "fetching...";
}

vector<computer> MainWindow::returnComVector()
{
    serviceobject.servStartDatabase();
    return serviceobject.servGetComVector();
    //qDebug () << "fetching...";
}

vector<computertype> MainWindow::returnComTypeVector()
{
    serviceobject.servStartDatabase();
    return serviceobject.servGetCompTypeVector();
    //qDebug () << "fetching...";
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
    qDebug() << "Add_New_Computer";
    //addnewcomputer newcomputer;
    //newcomputer.setModal(true);
    //newcomputer.exec();
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

void MainWindow::on_MainMenuSelection_tabBarClicked(int index)
{
    if (index == 0)
    {
        printScientists();
    }
    if (index == 1)
    {
        printComputers();
    }

}

void MainWindow::on_databaseDisplayComSci_cellClicked(int row, int column)
{

    //qDebug () << index.row();
    //qDebug () << row << column;
    bool itt = true;
    QString name = "jonson";
    //addnewcomputer newcomputer;
    //newcomputer.editcomputer(row,column, itt, name);
}

void MainWindow::on_databaseDisplayComputers_doubleClicked(const QModelIndex &index)
{
    int i = index.internalId();
    int row = ui->databaseDisplayComputers->currentRow();

    QStringList list;
    QAbstractItemModel *model = ui->databaseDisplayComputers->model();

    model->rowCount();

    for (int i = 0; i < 1; i++)
    {
        QModelIndex index = model->index(row, 5);
        qDebug () << (index.data().toString());
        qDebug () << " ";
    }


    //QString test = QString::fromStdString(serviceobject.servGetComVector().at(i).getComName());

    //qDebug () << test;

}
