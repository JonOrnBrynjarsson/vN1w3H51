#include "addnewcomputer.h"
#include "ui_addnewcomputer.h"
#include <QDebug>
#include "mainwindow.h"

//FORCE UPDATE!

addnewcomputer::addnewcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addnewcomputer)
{

    ui->setupUi(this);
    ui->buttonBox_editComputerFinished->setHidden(true);
    ui->label_computerID->setHidden(true);
    ui->label_relations->setHidden(true);
    ui->textBrowser_relations->setHidden(true);
    ui->errorInName->setHidden(true);
    //ui->errorInYear->setHidden(true);

    serviceObject.servReadSqlCompTypes();

    for( unsigned int row = 0; row < serviceObject.servGetCompTypeVector().size(); row++)
    {
        ui->comboBox_type->insertItem(row+1, QString::fromStdString(
                                        serviceObject.servGetCompTypeVector().at(row).getName()), 0);
    }


}

void addnewcomputer::neweditcomputer(QString id, bool edit)
{
    //qDebug () << "neweditcomputer, crash 0";
    int n = id.toInt(0,10);
    serviceObject.servReadSqlCompTypes();
    serviceObject.servReadSqlComputers("NAME");
    int currentID = 0;
    QString name, descr, comid, yoc;
    bool built;
    int type;
    //qDebug () << "neweditcomputer, crash 1";

    for (unsigned int i = 0; i  < serviceObject.servGetComVector().size(); i++)
    {
        if(serviceObject.servGetComVector().at(i).getId() == n)
        {
            //qDebug () << "neweditcomputer, crash 2";

            name = QString::fromStdString(serviceObject.servGetComVector().at(i).getComName());
            yoc = QString::number(serviceObject.servGetComVector().at(i).getComYear());
            type = serviceObject.servGetComVector().at(i).getComType();
            built = serviceObject.servGetComVector().at(i).getComBuilt();
            descr = QString::fromStdString(serviceObject.servGetComVector().at(i).getComDescription());
            comid = QString::number(serviceObject.servGetComVector().at(i).getId());
            currentID = serviceObject.servGetComVector().at(i).getId();
            //qDebug () << name;
            //qDebug () << "neweditcomputer, crash 3";

        }
    }
    //qDebug () << "neweditcomputer, crash 4";

    QDate dYoc;

    dYoc.setDate(yoc.toInt(),1,1);

    ui->lineEdit_insertName->setText(name);
    //ui->lineEdit_enterYear->setText(dYoc);
    ui->dateEdit_yoc->setDate(dYoc);
    ui->comboBox_type->setCurrentIndex(type-1);
    ui->checkBox_built->setChecked(built);
    ui->textEdit_insertDescription->setText(descr);
    ui->label_computerID->setText(comid);
    //qDebug () << "neweditcomputer, crash 5";

    this->setWindowTitle("Edit Computer in the Database");
    ui->buttonBox_editComputerFinished->setHidden(false);
    ui->buttonBox_addNewComputerFinished->setHidden(true);
    //qDebug () << "neweditcomputer, crash 6";

    if (edit == false)
    {
        this->setWindowTitle("More information about the Computer");
        ui->buttonBox_editComputerFinished->setHidden(true);

        ui->label_enterName->setText("Name: ");
        ui->lineEdit_insertName->setReadOnly(true);
        ui->label_enterYear->setText("Year: ");
        //ui->lineEdit_enterYear->setReadOnly(true);
        ui->dateEdit_yoc->setReadOnly(true);
        ui->label_chooseType->setText("Type:");
        ui->comboBox_type->setEnabled(false);
        ui->label_chooseBuilt->setText("Built: ");
        ui->checkBox_built->setEnabled(false);
        ui->label_enterDescription->setText("Description:");
        ui->textEdit_insertDescription->setReadOnly(true);

        neweditcomputerRelations(currentID);

    }
    //qDebug () << "neweditcomputer, crash 7";

    setModal(true);
    exec();
    //qDebug () << "neweditcomputer, crash 8";


}

void addnewcomputer::neweditcomputerRelations(int currentID)
{
    vector<scientist> comLinkedToSci = serviceObject.servGetScientistsLinkedToComputer(currentID);

    if (comLinkedToSci.size() > 0)
    {
        ui->label_relations->setHidden(false);
        ui->textBrowser_relations->setHidden(false);
        QString linkedScientists;
        string outoffunc;
        for (unsigned int x = 0; x < comLinkedToSci.size(); x++)
        {
            string space = "\n";
            string temp;
            temp = comLinkedToSci.at(x).getName();

            if (comLinkedToSci.size() > 1)
            {
                outoffunc += temp + space;
            }
            else
            {
                outoffunc = temp;
            }
        }

        linkedScientists = QString::fromStdString(outoffunc);
        ui->textBrowser_relations->setText(linkedScientists);
    }
}
addnewcomputer::~addnewcomputer()
{

}


void addnewcomputer::on_buttonBox_addNewComputerFinished_accepted()
{

    bool goodInput = false;

    if (on_lineEdit_insertName_editingFinished() == false)
    {
        goodInput = true;
    }

    string name = ui->lineEdit_insertName->text().toStdString();
    //int year = ui->lineEdit_enterYear->text().toInt();
    int year = ui->dateEdit_yoc->date().year();
    int type = ui->comboBox_type->currentIndex();
    type = serviceObject.servGetCompTypeVector().at(type).getid();
    bool built = ui->checkBox_built->checkState();
    string descr = ui->textEdit_insertDescription->document()->toPlainText().toStdString();

    if(goodInput)
    {
        computer c(name, year, type, built, descr);
        serviceObject.servAddcomputer(c);
        serviceObject.servReadSqlComputers();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Name is too short. Try again!");
    }
}


void addnewcomputer::on_dateEdit_year_userDateChanged()//const QDate &date)
{
    //QString year = ui->lineEdit_enterYear->text();
//    QString year = QString::number(ui->dateEdit_yoc->date().year());
//    int yearint = year.toInt();

    int yearint = ui->dateEdit_yoc->date().year();

    //qDebug () << ui->dateEdit_year->date();
    if (yearint > CURRENTYEAR)
    {

        QMessageBox::information(this,"Wrong year","It is not possible to enter a futuristic computer",0);

    }
}

void addnewcomputer::on_buttonBox_editComputerFinished_accepted()
{
    string name = ui->lineEdit_insertName->text().toStdString();
    //int year = ui->lineEdit_enterYear->text().toInt();
    int year = ui->dateEdit_yoc->date().year();
    int type = ui->comboBox_type->currentIndex();
    type = serviceObject.servGetCompTypeVector().at(type).getid();
    bool built = ui->checkBox_built->checkState();
    string descr = ui->textEdit_insertDescription->document()->toPlainText().toStdString();
    int id = ui->label_computerID->text().toInt();

    bool goodInput = false;

    if (on_lineEdit_insertName_editingFinished() == false)
    {
        goodInput = true;
    }


    if(goodInput)
    {
        computer c(name, year, type, built, descr);
        c.setComID(id);
        serviceObject.servUpdateSqlComputer(c);
        serviceObject.servReadSqlComputers();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Name is too short. Try again!");
    }

    addnewcomputer::close();
}

void addnewcomputer::on_buttonBox_editComputerFinished_rejected()
{
    qDebug () << "close button press ";
    addnewcomputer::close();
}

//bool addnewcomputer::on_lineEdit_enterYear_editingFinished()
//{
//    bool badyoc = false;
//    QString yoc = ui->lineEdit_enterYear->text();
//    int syoc = serviceObject.yearCorrection(yoc.toInt(), badyoc);
//    QString yocf = QString::number(syoc);

//    if (badyoc == true)
//    {
//        ui->errorInYear->setHidden(false);
//        ui->errorInYear->setText("<font color='Red'>Year not properly formatted.</font>");
//    }
//    else
//    {
//        ui->lineEdit_enterYear->setText(yocf);
//        ui->errorInYear->setHidden(true);
//        badyoc = false;
//    }

//    return badyoc;
//}

bool addnewcomputer::on_lineEdit_insertName_editingFinished()
{
    bool badName = true;
    if (ui->lineEdit_insertName->text().size() < 1)
    {
        ui->errorInName->setHidden(false);
        ui->errorInName->setText("<font color='Red'>Name is to short!</font>");
        badName = true;
    }
    else
    {
        ui->errorInName->setHidden(true);
        badName = false;
    }
    return badName;
}
