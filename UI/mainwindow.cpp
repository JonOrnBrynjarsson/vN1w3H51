#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QModelIndex>
#include <math.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    serviceobject.servStartDatabase();
    serviceobject.servReadSqlScientists();
    serviceobject.servReadSqlComputers();
    serviceobject.servReadSqlCompTypes();
    serviceobject.servReadSqlRelations();


    ui->setupUi(this);
    //ui->tableView->setColumnHidden(5, true);
    printScientists();
    printComputers();
    printComputerTypes();
    displayRelations();

//    ui->databaseDisplayComSci->setColumnHidden(4, true); // FELUR auka uppl.
//    ui->databaseDisplayComSci->setColumnHidden(5, true); // FELUR auka uppl.
//    ui->databaseDisplayComSci->setColumnHidden(6, true); // FELUR auka uppl.

//    ui->databaseDisplayComSci->setColumnHidden(7, true); // FELUR ID!!!!

//    ui->databaseDisplayComputers->setColumnHidden(4, true); // // FELUR auka uppl.

//    ui->databaseDisplayComputers->setColumnHidden(5, true); // FELUR ID!!!!
//    ui->databaseDisplayComTypes->setColumnHidden(2, true);  // Hides ID column
}
void MainWindow::printScientists()
{
    //serviceobject.servStartDatabase();
    //ui->databaseDisplayComSci->clear();


    //serviceobject.servReadSqlScientists("NAME");

    ui->databaseDisplayComSci->setSortingEnabled(false);
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

        //qDebug() << "for i: " << i << " name is "  << name;

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
    QStringList sciHeader = (QStringList() << "Name" << "Gender" << "Year of birth" << "Year of death"
                             << "Description" << "Link" << "computer type" << "Scientist id");
    ui->databaseDisplayComSci->setHorizontalHeaderLabels(sciHeader);
    ui->databaseDisplayComSci->setSortingEnabled(true);
    //qDebug() << "on to the next...";
    ui->databaseDisplayComSci->setColumnHidden(4, true); // FELUR auka uppl.
    ui->databaseDisplayComSci->setColumnHidden(5, true); // FELUR auka uppl.
    ui->databaseDisplayComSci->setColumnHidden(6, true); // FELUR auka uppl.
    ui->databaseDisplayComSci->setColumnHidden(7, true); // FELUR ID!!!!


}

void MainWindow::printComputers()
{

    ui->databaseDisplayComputers->setRowCount(serviceobject.servGetComVector().size());
    ui->databaseDisplayComputers->setSortingEnabled(false); // To be able to display headers and all column data - bugfix for qt.

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
    QStringList comHeader = (QStringList() << "Name" << "Created" << "Type" << "Built" << "Description"  << "cID") ;
    ui->databaseDisplayComputers->setHorizontalHeaderLabels(comHeader);
    //ui->databaseDisplayComputers->horizontalHeader()-
    ui->databaseDisplayComputers->setSortingEnabled(true);// To be able to display headers and all column data - bugfix for qt.
    //ui->databaseDisplayComputers->setColumnHidden(5, true);  // Hides ID column
    ui->databaseDisplayComputers->setColumnHidden(4, true); // // FELUR auka uppl.
    ui->databaseDisplayComputers->setColumnHidden(5, true); // FELUR ID!!!!

}

void MainWindow::printComputerTypes()
{
    ui->databaseDisplayComSci->setSortingEnabled(false);
    ui->databaseDisplayComTypes->setRowCount(serviceobject.servGetCompTypeVector().size());

    for (unsigned int i = 0; i < serviceobject.servGetCompTypeVector().size(); i++)
    {
        QString comTName = QString::fromStdString(serviceobject.servGetCompTypeVector().at(i).getName());
        ui->databaseDisplayComTypes->setItem(i, 0, new QTableWidgetItem(comTName));

        QString comTDescr = QString::fromStdString(serviceobject.servGetCompTypeVector().at(i).getDesc());
        ui->databaseDisplayComTypes->setItem(i, 1, new QTableWidgetItem(comTDescr));

        QString comTID = QString::number(serviceobject.servGetCompTypeVector().at(i).getid());
        ui->databaseDisplayComTypes->setItem(i, 2, new QTableWidgetItem(comTID));
    }
    ui->databaseDisplayComTypes->setSortingEnabled(true);
    QStringList compTypeHeader = (QStringList() << "Name" << "Description");
    ui->databaseDisplayComTypes->setHorizontalHeaderLabels(compTypeHeader);
    ui->databaseDisplayComTypes->setColumnHidden(2, true);  // Hides ID column
}

QString MainWindow::getCurrentSciRowPos()
{
    int row = ui->databaseDisplayComSci->currentRow();

    QStringList list;
    QAbstractItemModel *model = ui->databaseDisplayComSci->model();



    model->rowCount();
    QString returnID;
    for (int i = 0; i < 1; i++)
    {
        QModelIndex index = model->index(row, 7);
        QString temp = (index.data().toString());
        returnID = index.data().toString();
    }

    return returnID;
}

QString MainWindow::getCurrentComRowPos()
{
    int row = ui->databaseDisplayComputers->currentRow();

    QStringList list;
    QAbstractItemModel *model = ui->databaseDisplayComputers->model();

    model->rowCount();
    QString returnID;
    for (int i = 0; i < 1; i++)
    {
        QModelIndex index = model->index(row, 5);
        qDebug () << (index.data().toString());
        qDebug () << " ";
        QString temp = (index.data().toString());
        returnID = index.data().toString();
    }

    return returnID;
}

QString MainWindow::getCurrentComTypeRowPos()
{
    int row = ui->databaseDisplayComTypes->currentRow();
    QStringList list;
    QAbstractItemModel *model = ui->databaseDisplayComTypes->model();

    model->rowCount();
    QString returnID;
    for (int i = 0; i < 1; i++)
    {
        QModelIndex index = model->index(row, 2);
        qDebug () << (index.data().toString());
        qDebug () << " ";
        QString temp = (index.data().toString());
        returnID = index.data().toString();

    }

    return returnID;
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
    ui->databaseDisplayComSci->clear();
    serviceobject.servReadSqlScientists();
}

void MainWindow::on_actionAdd_New_Computer_triggered()
{
    qDebug() << "Add_New_Computer";
    addnewcomputer newcomputer;
    newcomputer.setModal(true);
    newcomputer.exec();
    ui->databaseDisplayComputers->clear();
    serviceobject.servReadSqlComputers();
    printComputers();

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
    addNewScientist newscientist;
    newscientist.neweditscientist(getCurrentSciRowPos(), true);
    qDebug () << "getCurrentSciRowPos is : " << getCurrentSciRowPos();
    serviceobject.servReadSqlScientists("NAME");
    printScientists();
}

void MainWindow::on_actionEdit_a_Computer_triggered()
{
    addnewcomputer newcomputer;
    newcomputer.neweditcomputer(getCurrentComRowPos(), true);
    serviceobject.servReadSqlComputers("NAME");
    printComputers();
}

void MainWindow::on_actionEdit_a_Computer_Type_triggered()
{
    addnewcomputertype newcomputertype;
    newcomputertype.neweditcomputertype(getCurrentComTypeRowPos(), true);
    serviceobject.servReadSqlCompTypes();
    printComputerTypes();
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
        qDebug () << "index selected !";
    }
    if (index == 1)
    {
        printComputers();
    }
    if (index == 2)
    {
        printComputerTypes();
    }

}

void MainWindow::on_databaseDisplayComSci_cellClicked(int row, int column)
{

}



void MainWindow::on_pushButon_addNewCompuer_clicked()
{
    qDebug () << "addnnewcomputerclicked";
    addnewcomputer newcomputer;
    newcomputer.setModal(true);
    newcomputer.exec();
    serviceobject.servReadSqlComputers();
    printComputers();
}



void MainWindow::on_pushButton_removeCompuer_clicked()
{
        qDebug () << "on_pushButton_removeCompuer_clicked";
    int currentComputer = ui->databaseDisplayComputers->currentIndex().row();


    computer selctedComputer = serviceobject.servGetComVector().at(currentComputer);
    int toDelete = QMessageBox::critical(this,"About to delete", "Are you sure you want to delete this computer?",0x00400000, 0x00000400);

    if(toDelete == 1024)
    {
        serviceobject.servDeleteComputer(selctedComputer.getId());
        QMessageBox::information(this, QString::fromStdString(selctedComputer.getComName()), "deleted!");

        ui->databaseDisplayComputers->clear();
        serviceobject.servReadSqlComputers();
        printComputers();
    }
    else
    {
        QMessageBox::information(this, QString::fromStdString(selctedComputer.getComName()), "Still here!");
        ui->databaseDisplayComputers->clear();
        serviceobject.servReadSqlComputers();
        printComputers();
    }
}

void MainWindow::displayRelations()
{

    ui-> tableWidget_displayRelations->setRowCount(serviceobject.servGetRelationshipVector().size());
    ui->tableWidget_displayRelations->setSortingEnabled(false); // To be able to display headers and all column data - bugfix for qt.

    for (unsigned int i = 0; i < serviceobject.servGetRelationshipVector().size(); i++)
    {
        QString sciID = QString::number(serviceobject.servGetRelationshipVector().at(i).scientistID);
        QString compID = QString::number(serviceobject.servGetRelationshipVector().at(i).computerID);
        QString sciName = QString::fromStdString(serviceobject.servGetRelationshipVector().at(i).scientistName);
        QString compName = QString::fromStdString(serviceobject.servGetRelationshipVector().at(i).computerName);
        ui->tableWidget_displayRelations->setItem(i, 0, new QTableWidgetItem(sciID));
        ui->tableWidget_displayRelations->setItem(i, 1, new QTableWidgetItem(sciName));
        ui->tableWidget_displayRelations->setItem(i, 2, new QTableWidgetItem(compID));
        ui->tableWidget_displayRelations->setItem(i, 3, new QTableWidgetItem(compName));
    }
    ui->tableWidget_displayRelations->setSortingEnabled(true);// To be able to display headers and all column data - bugfix for qt.
    ui->tableWidget_displayRelations->setColumnHidden(0, true);  // Hides ID column
    ui->tableWidget_displayRelations->setColumnHidden(2, true);  // Hides ID column
    QStringList relHeader = (QStringList() << ""<< "Scientist" << ""<< "Computer");
    ui->tableWidget_displayRelations->setHorizontalHeaderLabels(relHeader);
}


void MainWindow::on_databaseDisplayComputers_doubleClicked(const QModelIndex &index)
{
    qDebug () << "in display computers double click: " << getCurrentComTypeRowPos();
    addnewcomputer newcomputer;
    newcomputer.neweditcomputer(getCurrentComRowPos(), false);
    serviceobject.servReadSqlComputers("NAME");
    printComputers();

}

void MainWindow::on_pushButton_editCompuer_clicked()
{
    on_actionEdit_a_Computer_triggered();
}


void MainWindow::on_databaseDisplayComSci_doubleClicked(const QModelIndex &index)
{
    qDebug () << "column is : " << index.row();
    addNewScientist newscientist;
    qDebug () << "getCurrentSciRowPos is : " << getCurrentSciRowPos();
    newscientist.neweditscientist(getCurrentSciRowPos(), false);
}

void MainWindow::on_pushButton_addnewType_clicked()
{
       qDebug () << "addnnewcomputertypeclicked";
       addnewcomputertype newtype;
       newtype.setModal(true);
       newtype.exec();
       serviceobject.servReadSqlCompTypes();
       printComputerTypes();
}


void MainWindow::on_pushButton_RemoveType_clicked()
{
    qDebug () << "on_pushButton_removeComptype_clicked";
    int currentType = ui->databaseDisplayComTypes->currentIndex().row();


    computertype selctedType = serviceobject.servGetCompTypeVector().at(currentType);
    int toDelete = QMessageBox::critical(this,"About to delete", "Are you sure you want to delete this computer type?",0x00400000, 0x00000400);

    if(toDelete == 1024)
    {
       serviceobject.servDeleteComputerType(selctedType.getid());
       QMessageBox::information(this, QString::fromStdString(selctedType.getName()), "deleted!");

       ui->databaseDisplayComTypes->clear();
       serviceobject.servReadSqlCompTypes();
       printComputerTypes();
    }
    else
    {
        QMessageBox::information(this, QString::fromStdString(selctedType.getName()), "Still here!");
        ui->databaseDisplayComTypes->clear();
        serviceobject.servReadSqlCompTypes();
        printComputerTypes();
    }
}


void MainWindow::on_comboBox_filterComputers_currentIndexChanged(int index)

{
    ui->lineEdit_filterComputers->setText("");
    serviceobject.servReadSqlComputers();
    printComputers();

}

void MainWindow::on_lineEdit_filterComputers_textEdited(const QString &arg1)

{
    bool isFound = false;
    string filterText = arg1.toStdString();

    if(ui->comboBox_filterComputers->currentIndex() == 0) //name
    {
         serviceobject.servSearchComputerByName(filterText, isFound);
    }
    else if(ui->comboBox_filterComputers->currentIndex() == 1) //type
    {
        serviceobject.servSearchComputerByType(filterText, isFound);
    }
    else if(ui->comboBox_filterComputers->currentIndex() == 2)
    {
        int yr = arg1.toUInt();
        qDebug() << yr;
        if(yr != 0)
        {
            serviceobject.servSearchComputerByYear(yr, isFound);
        }
        else
        {
            serviceobject.servReadSqlComputers();
            printComputers();
        }
    }
    if(isFound)
    {
        ui->databaseDisplayComputers->clear();
        printComputers();
    }
    else
    {
        if(ui->comboBox_filterComputers->currentIndex() != 2)
        {
            ui->statusbar->showMessage("Nothing found", 2000);
        }
    }
}


void MainWindow::on_databaseDisplayComTypes_doubleClicked(const QModelIndex &index)
{
    qDebug () << "on_databaseDisplayComTypes_doubleClicked" << index;
    qDebug () << "getCurrentComTypeRowPos() is " << getCurrentComTypeRowPos();
    addnewcomputertype newcomputertype;
    newcomputertype.neweditcomputertype(getCurrentComTypeRowPos(), false);
}
void MainWindow::on_comboBox_filterRelations_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_filterRelations->setText("");
    serviceobject.servReadSqlRelations();
    displayRelations();

}

void MainWindow::on_lineEdit_filterRelations_textEdited(const QString &arg1)
{
    bool isFound = false;
    string filterText = arg1.toStdString();
    serviceobject.servSearchRelations(ui->comboBox_filterRelations
                                          ->currentIndex(), filterText, isFound);
    if(isFound)
    {
        ui->tableWidget_displayRelations->clear();
        displayRelations();
    }
    else
    {
        if(ui->comboBox_filterRelations->currentIndex() < 2)
        {
            ui->statusbar->showMessage("Nothing found", 2000);
        }
        displayRelations();
    }
}
void MainWindow::on_comboBox_filterComputerTypes_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_filterComputerTypes->setText("");
    serviceobject.servReadSqlCompTypes();
    printComputerTypes();
}

void MainWindow::on_lineEdit_filterComputerTypes_textEdited(const QString &arg1)
{
    {
        bool isFound = false;
        string filterText = arg1.toStdString();
        serviceobject.servSearchComputerTypes(ui->comboBox_filterRelations
                                              ->currentIndex(), filterText, isFound);
        if(isFound)
        {
            ui->databaseDisplayComTypes->clear();
            printComputerTypes();
        }
        else
        {
            if(ui->comboBox_filterComputerTypes->currentIndex() < 2)
            {
                ui->statusbar->showMessage("Nothing found", 2000);
            }
            printComputerTypes();
        }
    }
}



void MainWindow::on_comboBox_filterScientist_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_filterScientist->setText("");
    serviceobject.servReadSqlScientists();
    printScientists();
}



void MainWindow::on_lineEdit_filterScientist_textEdited(const QString &arg1)
{
    bool isFound = false;
    string filterText = arg1.toStdString();

    if(ui->comboBox_filterScientist->currentIndex() == 0) //name
    {
         serviceobject.servSearchScientistByName(filterText, isFound);
    }
    else if(ui->comboBox_filterScientist->currentIndex() == 1) //gender
    {
        int gender = serviceobject.genderCorrection(filterText);
        serviceobject.servSearchScientistByGender(gender, isFound);
    }
    else if(ui->comboBox_filterScientist->currentIndex() == 2       //yob
            || ui->comboBox_filterScientist->currentIndex() == 3)  // yod
    {
        int yr = arg1.toUInt();
        char bord;
        if(ui->comboBox_filterScientist->currentIndex() == 2)
        {
            bord = 'b';
        }
        else
        {
            bord = 'd';
        }
        qDebug() << yr;
        if(yr != 0)
        {
            serviceobject.servSearchScientistByYear(yr, bord, isFound);
        }
        else
        {
            serviceobject.servReadSqlScientists();
            printScientists();
        }
    }
//    else if(ui->comboBox_filterScientist->currentIndex() == 3)  // yod
//    {
//        int yr = arg1.toUInt();
//        if(yr != 0)
//        {
//            serviceobject.servSearchScientistByYear(yr,'b' isFound);
//        }
//        else
//        {
//            serviceobject.servReadSqlScientists();
//            printScientists();
//        }
//    }

    if(isFound)
    {
        ui->databaseDisplayComSci->clear();
        printScientists();
    }
    else
    {
        if(ui->comboBox_filterScientist->currentIndex() < 2)
        {
            ui->statusbar->showMessage("Nothing found", 2000);
            printScientists();
        }
    }
}
