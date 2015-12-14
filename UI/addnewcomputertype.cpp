#include "addnewcomputertype.h"
#include "ui_addnewcomputertype.h"
//#include "DataLayer/workingclass.h"
//#include <QDateEdit>
//#include <sstream>
//#include <QDebug>


addnewcomputertype::addnewcomputertype(QWidget *parent) :QDialog(parent),ui(new Ui::addnewcomputertype)
{
    ui->setupUi(this);
    ui->buttonBox_Editcomtype->setHidden(true);
    ui->labelComTypeID->setHidden(true);
}

void addnewcomputertype::neweditcomputertype(QString id, bool edit)
{
    //qDebug () << "neweditcomputertype!" << "id is : " << id;
    int n = id.toInt();
    serviceObject.servReadSqlCompTypes();
    serviceObject.servReadSqlComputers("NAME");

    QString name, descr, comtypeid;
    for (unsigned int i = 0; i  < serviceObject.servGetCompTypeVector().size(); i++)
    {
        if(serviceObject.servGetCompTypeVector().at(i).getid() == n)
        {
            name = QString::fromStdString(serviceObject.servGetCompTypeVector().at(i).getName());
            descr = QString::fromStdString(serviceObject.servGetCompTypeVector().at(i).getDesc());
            comtypeid = QString::number(serviceObject.servGetCompTypeVector().at(i).getid());
            //qDebug () << name;
        }
    }
    ui->lineEdit_name->setText(name);
    ui->textEdit_descr->setText(descr);
    ui->labelComTypeID->setText(comtypeid);

    this->setWindowTitle("Edit Computer Type in the Database");
    ui->buttonBox->setHidden(true);
    ui->buttonBox_Editcomtype->setHidden(false);

    if (edit == false)
    {
        this->setWindowTitle("More information about the Computer Type");
        ui->buttonBox_Editcomtype->setHidden(true);

        ui->labelEntName->setText("Name: ");
        ui->lineEdit_name->setReadOnly(true);
        ui->labelEntDescr->setText("Description: ");
        ui->textEdit_descr->setReadOnly(true);
    }

    setModal(true);
    exec();

}

addnewcomputertype::~addnewcomputertype()
{
    delete ui;
}

void addnewcomputertype::on_buttonBox_accepted()
{
    ct.setName(ui->lineEdit_name->text().toStdString());
    ct.setDesc(ui->textEdit_descr->toPlainText().toStdString());
    serviceObject.servAddcomputerType(ct);
    serviceObject.servReadSqlCompTypes();

}

void addnewcomputertype::addCompTypetoDB(computertype &ct)
{
    serviceObject.servAddcomputerType(ct);
}


void addnewcomputertype::addCompTypeErrCorr(computertype &ct)
{
    bool badName = false;

    ct.setName(serviceObject.nameCorrection(ct.getName(), badName));

    if(badName)
    {
        qDebug() << "ERROR IN NAME!";

        if(badName)
        {
            serviceObject.errorMessage("Name not correctly formated, please enter letters only.");
        }
    }
    else
    {
        addCompTypetoDB(ct);
        qDebug() << "NAME ADDED TO DATABASE!";
        serviceObject.completeMessage("Name was succesfully added to the Database!");
    }
}



void addnewcomputertype::on_buttonBox_Editcomtype_accepted()
{

    //qDebug () << "on_buttonBox_Editcomtype_accepted()";


    string name = ui->lineEdit_name->text().toStdString();
    string descr = ui->textEdit_descr->document()->toPlainText().toStdString();
    int id = ui->labelComTypeID->text().toInt();

    QString debugname = QString::fromStdString(name);
    QString debugdescr = QString::fromStdString(descr);
    QString debugid = QString::number(id);

    if(name != "")
    {
        //computer c(name, year, type, built, descr);
        //qDebug () << "debugname is " << debugname << "debugdescr is " << debugdescr << "debugid is "  << debugid;
        computertype ct(id, name, descr);
        serviceObject.servUpdateSqlComputerType(ct);
        serviceObject.servReadSqlCompTypes();
    }
    else
    {

        QMessageBox::warning(this, "Error", "You have to include a name for the computertype!");
    }

    addnewcomputertype::close();
}
