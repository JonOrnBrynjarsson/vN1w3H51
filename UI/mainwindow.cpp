#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    setAllMainMenuSelectionDisabled();
    on_MainMenuSelection_currentChanged(ui->MainMenuSelection->currentIndex());
}
MainWindow::~MainWindow()
{
    delete ui;
}
//void MainWindow::setAllMainMenuSelectionDisabled()
//{
//    ui->actionAdd_New_Computer->setDisabled(true);
//    ui->actionAdd_New_Computer_Scientist->setDisabled(true);
//    ui->actionAdd_New_Computer_Type->setDisabled(true);
//    ui->actionAdd_Relations->setDisabled(true);
//    ui->actionEdit_a_Computer->setDisabled(true);
//    ui->actionEdit_a_Computer_Scientist->setDisabled(true);
//    ui->actionEdit_a_Computer_Type->setDisabled(true);
//    ui->actionRemove_a_Computer->setDisabled(true);
//    ui->actionRemove_a_Computer_Scientist->setDisabled(true);
//    ui->actionRemove_a_Computer_Type->setDisabled(true);
//    ui->actionRemove_Relations->setDisabled(true);
//    ui->actionView_computer->setDisabled(true);
//    ui->actionView_computer_type->setDisabled(true);
//    ui->actionView_scientist->setDisabled(true);
//}
//void MainWindow::on_pushButon_addNewRelations_clicked()
//{
//    on_actionAdd_Relations_triggered();
//}

/*
##  Scientists Slots
##---------------------------------------------------------------------------------------##
*/
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
    ui->databaseDisplayComSci->clear();
    if(!isFound)
    {
        ui->statusbar->showMessage("Nothing found", 2000);
    }
    printScientists();
}
void MainWindow::on_actionView_scientist_triggered()
{
    on_databaseDisplayComSci_doubleClicked();
}
void MainWindow::on_databaseDisplayComSci_doubleClicked()
{
    if (getCurrentSciRowPos().toInt() == 0)
    {
        ui->statusbar->showMessage("Nothing selected...", 2000);
    }
    else
    {
        addNewScientist newscientist;
        newscientist.neweditscientist(getCurrentSciRowPos(), false);
        serviceobject.servReadSqlScientists();
        printScientists();
    }
}
void MainWindow::on_databaseDisplayComSci_customContextMenuRequested(const QPoint &pos)
{
    QMenu scientistMenu;
    scientistMenu.addAction(ui->actionView_scientist);
    scientistMenu.addSeparator();
    scientistMenu.addAction(ui->actionAdd_New_Computer_Scientist);
    scientistMenu.addAction(ui->actionEdit_a_Computer_Scientist);
    scientistMenu.addAction(ui->actionRemove_a_Computer_Scientist);
    scientistMenu.exec(ui->databaseDisplayComSci->viewport()->mapToGlobal(pos));
}

/*
##  Scientists Slots##Action Bar
##---------------------------------------------------------------------------------------##
*/
void MainWindow::on_actionAdd_New_Computer_Scientist_triggered()
{
    addNewScientist newscientist;
    newscientist.setModal(true);
    newscientist.exec();
    ui->statusbar->showMessage("Add new scientist", 5000);
    ui->databaseDisplayComSci->clear();
    serviceobject.servReadSqlScientists();
    printScientists();
}
void MainWindow::on_actionEdit_a_Computer_Scientist_triggered()
{
    addNewScientist newscientist;

    if (getCurrentSciRowPos().length() > 0)
    {
        newscientist.neweditscientist(getCurrentSciRowPos(), true);
        serviceobject.servReadSqlScientists("NAME");
        printScientists();
    }
}
void MainWindow::on_actionRemove_a_Computer_Scientist_triggered()
{
    QString pos = getCurrentSciRowPos();

    if (pos.length() == 0)
    {
        ui->statusbar->showMessage("Nothing selected...", 2000);
    }
    else
    {
        int toDelete = QMessageBox::critical(this,"About to delete",
                                             "Are you sure you want to delete this Scientist?",0x00400000, 0x00000400);

        if(toDelete == 1024)
        {
            serviceobject.servDeleteScientist(pos.toUInt());
            ui->statusbar->showMessage("Scientist deleted", 2000);
            ui->databaseDisplayComSci->clear();
            serviceobject.servReadSqlScientists();
            printScientists();
        }
        else
        {
            ui->statusbar->showMessage("Canceled", 2000);
            ui->databaseDisplayComSci->clear();
            serviceobject.servReadSqlScientists();
            printScientists();
        }
    }
}

/*
##  Scientists Slots##Buttons and Boxes
##---------------------------------------------------------------------------------------##
*/
void MainWindow::on_comboBox_filterScientist_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_filterScientist->setText("");
    serviceobject.servReadSqlScientists();
    printScientists();
}
void MainWindow::on_pushButon_addNewScientist_clicked()
{
    on_actionAdd_New_Computer_Scientist_triggered();
}
void MainWindow::on_pushButton_editScientist_clicked()
{
    on_actionEdit_a_Computer_Scientist_triggered();
}
void MainWindow::on_pushButton_removeScientist_clicked()
{
    on_actionRemove_a_Computer_Scientist_triggered();
}

/*
##  Computers Slots
##---------------------------------------------------------------------------------------##
*/
void MainWindow::on_databaseDisplayComputers_doubleClicked()
{
    if (getCurrentComRowPos().toInt() == 0)
    {
        ui->statusbar->showMessage("Nothing selected...", 2000);
    }
    else
    {
        addnewcomputer newcomputer;
        newcomputer.neweditcomputer(getCurrentComRowPos(), false);
        serviceobject.servReadSqlComputers("NAME");
        printComputers();
    }
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
    ui->databaseDisplayComputers->clear();
    if(isFound)
    {
        ui->statusbar->showMessage("Nothing found", 2000);

    }
    printComputers();
}
void MainWindow::on_actionView_computer_triggered()
{
    on_databaseDisplayComputers_doubleClicked();
}
void MainWindow::on_databaseDisplayComputers_customContextMenuRequested(const QPoint &pos)
{
    QMenu computerMenu;
    computerMenu.addAction(ui->actionView_computer);
    computerMenu.addSeparator();
    computerMenu.addAction(ui->actionAdd_New_Computer);
    computerMenu.addAction(ui->actionEdit_a_Computer);
    computerMenu.addAction(ui->actionRemove_a_Computer);
    computerMenu.exec(ui->databaseDisplayComputers->viewport()->mapToGlobal(pos));

}

/*
##  Computers Slots##Action Bar
##---------------------------------------------------------------------------------------##
*/
void MainWindow::on_actionAdd_New_Computer_triggered()
{
    addnewcomputer newcomputer;
    newcomputer.setModal(true);
    newcomputer.exec();
    ui->databaseDisplayComputers->clear();
    serviceobject.servReadSqlComputers();
    printComputers();
}
void MainWindow::on_actionEdit_a_Computer_triggered()
{
    addnewcomputer newcomputer;

    if (getCurrentComRowPos().length() > 0)
    {
        newcomputer.neweditcomputer(getCurrentComRowPos(), true);
        serviceobject.servReadSqlComputers("NAME");
        printComputers();
    }
}
void MainWindow::on_actionRemove_a_Computer_triggered()
{

    QString pos = getCurrentComRowPos();

    if (pos.length() == 0)
    {
        ui->statusbar->showMessage("Nothing selected...", 2000);
    }
    else
    {
        int toDelete = QMessageBox::critical(this,"About to delete",
                                             "Are you sure you want to delete this computer?",0x00400000, 0x00000400);

        if(toDelete == 1024)
        {
            serviceobject.servDeleteComputer(pos.toUInt());
            ui->statusbar->showMessage("Computer deleted", 2000);
            ui->databaseDisplayComputers->clear();
            serviceobject.servReadSqlComputers();
            printComputers();
        }
        else
        {
            ui->statusbar->showMessage("Canceled", 2000);
            ui->databaseDisplayComputers->clear();
            serviceobject.servReadSqlComputers();
            printComputers();
        }
    }
}

/*
##  Computers Slots##Buttons and Boxes
##---------------------------------------------------------------------------------------##
*/
void MainWindow::on_comboBox_filterComputers_currentIndexChanged(int index)
{
    ui->lineEdit_filterComputers->setText("");
    serviceobject.servReadSqlComputers();
    printComputers();
}
void MainWindow::on_pushButon_addNewCompuer_clicked()
{
    on_actionAdd_New_Computer_triggered();
}
void MainWindow::on_pushButton_editCompuer_clicked()
{
    on_actionEdit_a_Computer_triggered();
}
void MainWindow::on_pushButton_removeCompuer_clicked()
{
    on_actionRemove_a_Computer_triggered();
}

/*
##  Computer Types Slots
##---------------------------------------------------------------------------------------##
*/
void MainWindow::on_actionView_computer_type_triggered()
{
    on_databaseDisplayComTypes_doubleClicked();
}
void MainWindow::on_lineEdit_filterComputerTypes_textEdited(const QString &arg1)
{
        bool isFound = false;
        string filterText = arg1.toStdString();
        serviceobject.servSearchComputerTypes(ui->comboBox_filterComputerTypes
                                              ->currentIndex(), filterText, isFound);
        ui->databaseDisplayComTypes->clear();
        if(!isFound)
        {
            ui->statusbar->showMessage("Nothing found", 2000);
            printComputerTypes();
        }
        printComputerTypes();
}
void MainWindow::on_databaseDisplayComTypes_doubleClicked()
{
    if (getCurrentComTypeRowPos().toInt() == 0)
    {
        ui->statusbar->showMessage("Nothing selected...", 2000);
    }
    else
    {
        addnewcomputertype newcomputertype;
        newcomputertype.neweditcomputertype(getCurrentComTypeRowPos(), false);
        serviceobject.servReadSqlCompTypes();
        printRelations();
    }
}
void MainWindow::on_databaseDisplayComTypes_customContextMenuRequested(const QPoint &pos)
{
    QMenu compTypeMenu;
    compTypeMenu.addAction(ui->actionView_computer_type);
    compTypeMenu.addSeparator();
    compTypeMenu.addAction(ui->actionAdd_New_Computer_Type);
    compTypeMenu.addAction(ui->actionEdit_a_Computer_Type);
    compTypeMenu.addAction(ui->actionRemove_a_Computer_Type);
    compTypeMenu.exec(ui->databaseDisplayComTypes->viewport()->mapToGlobal(pos));
}

/*
##  Computer Types Slots##Action Bar
##---------------------------------------------------------------------------------------##
*/
void MainWindow::on_actionAdd_New_Computer_Type_triggered()
{
    addnewcomputertype newcomptype;
    newcomptype.setModal(true);
    newcomptype.exec();
    serviceobject.servReadSqlCompTypes();
    printComputerTypes();
}
void MainWindow::on_actionEdit_a_Computer_Type_triggered()
{
    addnewcomputertype newcomputertype;
    if (getCurrentComTypeRowPos().length() > 0)
    {
        newcomputertype.neweditcomputertype(getCurrentComTypeRowPos(), true);
        serviceobject.servReadSqlCompTypes();
        printComputerTypes();
    }
}
void MainWindow::on_actionRemove_a_Computer_Type_triggered()
{
    QString pos = getCurrentComTypeRowPos();

    if (pos.length() == 0)
    {
        ui->statusbar->showMessage("Nothing selected...", 2000);
    }
    else
    {
        if (computerTypeCanBeDeleted(pos.toUInt()))
        {
            int toDelete = QMessageBox::critical(this,"About to delete",
                                                 "Are you sure you want to delete this computer type?",0x00400000, 0x00000400);

            if(toDelete == 1024)
            {
                serviceobject.servDeleteComputerType(pos.toUInt());
                ui->statusbar->showMessage("Computer Type deleted", 2000);
                ui->databaseDisplayComTypes->clear();
                serviceobject.servReadSqlCompTypes();
                printComputerTypes();
            }
            else
            {
                ui->statusbar->showMessage("Canceled", 2000);
                ui->databaseDisplayComTypes->clear();
                serviceobject.servReadSqlCompTypes();
                printComputerTypes();
            }
        }
        else
        {
            ui->statusbar->showMessage("Computer type in use!", 2000);
        }
    }
}

/*
##  Computer Types Slots##Buttons and Boxes
##---------------------------------------------------------------------------------------##
*/
void MainWindow::on_comboBox_filterComputerTypes_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_filterComputerTypes->setText("");
    serviceobject.servReadSqlCompTypes();
    printComputerTypes();
}
void MainWindow::on_pushButton_editComputerTypes_clicked()
{
    on_actionEdit_a_Computer_Type_triggered();
}
void MainWindow::on_pushButon_addNewCompuerTypes_clicked()
{
    on_actionAdd_New_Computer_Type_triggered();
}
void MainWindow::on_pushButton_removeCompuerTypes_clicked()
{
    on_actionRemove_a_Computer_Type_triggered();
}

/*
##  Relations Slots
##---------------------------------------------------------------------------------------##
*/
void MainWindow::on_lineEdit_filterRelations_textEdited(const QString &arg1)
{
    bool isFound = false;
    string filterText = arg1.toStdString();
    serviceobject.servSearchRelations(ui->comboBox_filterComputerTypes
                                          ->currentIndex(), filterText, isFound);
    ui->tableWidget_displayRelations->clear();
    if(!isFound)
    {
        ui->statusbar->showMessage("Nothing found", 2000);
    }
    printRelations();
}
void MainWindow::on_tableWidget_displayRelations_customContextMenuRequested(const QPoint &pos)
{
    QMenu relationsMenu;
    relationsMenu.addAction(ui->actionAdd_Relations);
    relationsMenu.addAction(ui->actionRemove_Relations);
    relationsMenu.exec(ui->tableWidget_displayRelations->viewport()->mapToGlobal(pos));
}

/*
##  Relations Slots##Action Bar
##---------------------------------------------------------------------------------------##
*/
void MainWindow::on_actionAdd_Relations_triggered()
{
    addrelations relations;
    relations.setModal(true);
    relations.exec();
    serviceobject.servReadSqlRelations();
    printRelations();
}
void MainWindow::on_actionRemove_Relations_triggered()
{
    int compos, scipos;
    getCurrentRelationsRowPos(compos, scipos);

    if (compos == 0&&scipos == 0)
    {
        ui->statusbar->showMessage("Nothing selected...", 2000);
    }
    else
    {
        int toDelete = QMessageBox::critical(this,"About to delete",
                                             "Are you sure you want to delete these Relations?",0x00400000, 0x00000400);

        if(toDelete == 1024)
        {
            serviceobject.servDeleteRelationSciComp(scipos,compos);
            ui->statusbar->showMessage("Relations deleted", 2000);
        }
        else
        {
            ui->statusbar->showMessage("Canceled", 2000);
        }
        serviceobject.servReadSqlRelations();
        printRelations();
    }
}

/*
##  Relations Slots##Buttons and Boxes
##---------------------------------------------------------------------------------------##
*/
void MainWindow::on_comboBox_filterRelations_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_filterRelations->setText("");
    serviceobject.servReadSqlRelations();
    printRelations();
}
void MainWindow::on_pushButon_addNewRelations_clicked()
{
    on_actionAdd_Relations_triggered();
}
void MainWindow::on_pushButton_removeRelations_clicked()
{
    on_actionRemove_Relations_triggered();
}

/*
##  Miscellaneous
##---------------------------------------------------------------------------------------##
*/
void MainWindow::on_actionHelp_triggered()
{
    help helpwindow;
    helpwindow.run();
}
void MainWindow::on_actionAbout_Computers_and_Scientists_Database_triggered()
{
   AboutCreators showCreators;
   showCreators.exec();
}
void MainWindow::setAllMainMenuSelectionDisabled()
{
    ui->actionAdd_New_Computer->setDisabled(true);
    ui->actionAdd_New_Computer_Scientist->setDisabled(true);
    ui->actionAdd_New_Computer_Type->setDisabled(true);
    ui->actionAdd_Relations->setDisabled(true);
    ui->actionEdit_a_Computer->setDisabled(true);
    ui->actionEdit_a_Computer_Scientist->setDisabled(true);
    ui->actionEdit_a_Computer_Type->setDisabled(true);
    ui->actionRemove_a_Computer->setDisabled(true);
    ui->actionRemove_a_Computer_Scientist->setDisabled(true);
    ui->actionRemove_a_Computer_Type->setDisabled(true);
    ui->actionRemove_Relations->setDisabled(true);
    ui->actionView_computer->setDisabled(true);
    ui->actionView_computer_type->setDisabled(true);
    ui->actionView_scientist->setDisabled(true);
}
void MainWindow::on_MainMenuSelection_currentChanged(int index)
{
    setAllMainMenuSelectionDisabled();
    if(index == 0)  // Scientists
    {
        ui->actionAdd_New_Computer_Scientist->setEnabled(true);
        ui->actionEdit_a_Computer_Scientist->setEnabled(true);
        ui->actionRemove_a_Computer_Scientist->setEnabled(true);
        ui->actionView_scientist->setEnabled(true);
        ui->lineEdit_filterScientist->setText("");
        serviceobject.servReadSqlScientists();
        printScientists();
    }
    else if(index == 1) // Computers
    {
        ui->actionAdd_New_Computer->setEnabled(true);
        ui->actionEdit_a_Computer->setEnabled(true);
        ui->actionRemove_a_Computer->setEnabled(true);
        ui->actionView_computer->setEnabled(true);
        ui->lineEdit_filterComputers->setText("");
        serviceobject.servReadSqlCompTypes();
        serviceobject.servReadSqlComputers();
        printComputers();
    }
    else if(index == 2) //  Computer types
    {
        ui->actionAdd_New_Computer_Type->setEnabled(true);
        ui->actionEdit_a_Computer_Type->setEnabled(true);
        ui->actionRemove_a_Computer_Type->setEnabled(true);
        ui->actionView_computer_type->setEnabled(true);
        ui->lineEdit_filterComputerTypes->setText("");
        serviceobject.servReadSqlCompTypes();
        printComputerTypes();
    }
    else if(index == 3) //  Relations
    {
        ui->actionAdd_Relations->setEnabled(true);
        ui->actionRemove_Relations->setEnabled(true);
        ui->lineEdit_filterRelations->setText("");
        serviceobject.servReadSqlRelations();
        printRelations();
    }
}

/*
##  Display
##---------------------------------------------------------------------------------------##
*/
void MainWindow::printScientists()
{
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
    ui->databaseDisplayComSci->setColumnHidden(4, true);
    ui->databaseDisplayComSci->setColumnHidden(5, true);
    ui->databaseDisplayComSci->setColumnHidden(6, true);
    ui->databaseDisplayComSci->setColumnHidden(7, true);
    ui->databaseDisplayComSci->setColumnWidth(0, 170);
    ui->databaseDisplayComSci->setSortingEnabled(true);
}
void MainWindow::printComputers()
{

    ui->databaseDisplayComputers->setRowCount(serviceobject.servGetComVector().size());
    ui->databaseDisplayComputers->setSortingEnabled(false);

    for (unsigned int i = 0; i < serviceobject.servGetComVector().size(); i++)
    {
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
    ui->databaseDisplayComputers->setColumnHidden(4, true);
    ui->databaseDisplayComputers->setColumnHidden(5, true);
    ui->databaseDisplayComputers->setColumnWidth(0, 200);
    ui->databaseDisplayComputers->setSortingEnabled(true);
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
void MainWindow::printRelations()
{

    ui-> tableWidget_displayRelations->setRowCount(serviceobject.servGetRelationshipVector().size());
    ui->tableWidget_displayRelations->setSortingEnabled(false);

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
    ui->tableWidget_displayRelations->setSortingEnabled(true);
    ui->tableWidget_displayRelations->setColumnHidden(0, true);  // Hides ID column
    ui->tableWidget_displayRelations->setColumnHidden(2, true);  // Hides ID column
    QStringList relHeader = (QStringList() << ""<< "Scientist" << ""<< "Computer");
    ui->tableWidget_displayRelations->setHorizontalHeaderLabels(relHeader);
    ui->tableWidget_displayRelations->setColumnWidth(1, 200);
    ui->tableWidget_displayRelations->setColumnWidth(3, 200);
}

/*
##  Miscellaneous
##---------------------------------------------------------------------------------------##
*/
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
        returnID = index.data().toString();
    }
    return returnID;
}
void MainWindow::getCurrentRelationsRowPos(int &compos, int &scipos)
{
    int row = ui->tableWidget_displayRelations->currentRow();
    QStringList list;
    QAbstractItemModel *model = ui->tableWidget_displayRelations->model();

    model->rowCount();
    QString returnID;
    for (int i = 0; i < 1; i++)
    {
        QModelIndex indexSci = model->index(row, 0);
        scipos = indexSci.data().toInt();
        QModelIndex indexCom = model->index(row, 2);
        compos = indexCom.data().toInt();
    }
}
bool MainWindow::computerTypeCanBeDeleted(int compTypeID)
{
    serviceobject.servReadSqlComputers();

    for(unsigned int i = 0; i < serviceobject.servGetComVector().size(); i++)
    {
        if (compTypeID == serviceobject.servGetComVector().at(i).getComType())
        {
            return false;
        }
    }
    return true;
}


