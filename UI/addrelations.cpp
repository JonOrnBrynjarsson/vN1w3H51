#include "addrelations.h"
#include "ui_addrelations.h"

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
QString addrelations::getCurrentSciRowPos(QString &name)
{
    int row = ui->tableWidget_chooseScientist->currentRow();

    //qDebug () <<  row;

    QStringList list;
    QAbstractItemModel *model = ui->tableWidget_chooseScientist->model();

    model->rowCount();
    QString returnID;
    for (int i = 0; i < 1; i++)
    {
        QModelIndex index = model->index(row, 1);
        //qDebug () << "index " << index;
        returnID = index.data().toString();
        //qDebug () << "return id is " << returnID;
        QModelIndex indexName = model->index(row, 0);
        //qDebug () << "index " << index;
        name = indexName.data().toString();
        //qDebug () << "return id is " << returnID;
    }

    return returnID;
}

QString addrelations::getCurrentComRowPos(QString &name)
{
    int row = ui->tableWidget_chooseComputer->currentRow();

    QStringList list;
    QAbstractItemModel *model = ui->tableWidget_chooseComputer->model();

    model->rowCount();
    QString returnID;
    for (int i = 0; i < 1; i++)
    {
        QModelIndex index = model->index(row, 1);
        returnID = index.data().toString();
        QModelIndex indexName = model->index(row, 0);
        name = indexName.data().toString();
    }

    return returnID;
}


void addrelations::printScientists()
{
    ui->tableWidget_chooseScientist->setSortingEnabled(false);
    ui->tableWidget_chooseScientist->setRowCount(serviceobject.servGetSciVector().size());

    for (unsigned int i = 0; i < serviceobject.servGetSciVector().size(); i++)
    {
        QString name = QString::fromStdString(serviceobject.servGetSciVector().at(i).getName());
        ui->tableWidget_chooseScientist->setItem(i, 0, new QTableWidgetItem(name));

        //int currentID = serviceobject.servGetSciVector().at(i).getID();

        QString sciID = QString::number(serviceobject.servGetSciVector().at(i).getID());
        ui->tableWidget_chooseScientist->setItem(i, 1, new QTableWidgetItem(sciID));
    }
    QStringList sciHeader = (QStringList() << "Name" << "Scientist id");
    ui->tableWidget_chooseScientist->setHorizontalHeaderLabels(sciHeader);
    ui->tableWidget_chooseScientist->setSortingEnabled(true);

    ui->tableWidget_chooseScientist->setColumnHidden(1, true); // FELUR ID!!!!

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
    ui->tableWidget_chooseComputer->setColumnHidden(1, true); // FELUR ID!!!!
}

void addrelations::on_buttonBox_accepted()
{
    QString sciName, comName;

    int scipos = getCurrentSciRowPos(sciName).toInt();
    int compos = getCurrentComRowPos(comName).toInt();

    QString comformtext = "Are you sure you want to add relations "
                          "between " + sciName + " and " + comName + " ? ";

    int toAdd = QMessageBox::question(this,"Adding relations",
                                         comformtext,0x00400000, 0x00000400);

    if(toAdd == 1024)
    {
        serviceobject.servAddRelationSciComp(scipos,compos);
    }
    else
    {
        QMessageBox::information(this,"Adding relations","Cancelled",0);
    }
}

void addrelations::on_lineEdit_filterScieentistAddRelation_textEdited(const QString &arg1)
{
    bool isFound = false;
    string filterText = arg1.toStdString();
    serviceobject.servSearchScientistByName(filterText, isFound);

    if(isFound)
    {
        ui->tableWidget_chooseScientist->clear();
        printScientists();
    }
}

void addrelations::on_lineEdit_filteComputersAddRelation_textEdited(const QString &arg1)
{
    bool isFound = false;
    string filterText = arg1.toStdString();

    serviceobject.servSearchComputerByName(filterText, isFound);
    if(isFound)
    {
        ui->tableWidget_chooseComputer->clear();
        printComputers();
    }
}
