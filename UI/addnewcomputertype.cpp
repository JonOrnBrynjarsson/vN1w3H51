#include "addnewcomputertype.h"
#include "ui_addnewcomputertype.h"


//FORCE UPDATE!

addnewcomputertype::addnewcomputertype(QWidget *parent) :QDialog(parent),ui(new Ui::addnewcomputertype)
{
    ui->setupUi(this);
    //ui->buttonBox_Editcomtype->setHidden(true);
    ui->newOkCancel_Edit->setHidden(true);
    ui->labelComTypeID->setHidden(true);
    ui->errorInName->setHidden(true);
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
    //ui->buttonBox->setHidden(true);
    ui->newOkCancel_New->setHidden(true);
    //ui->buttonBox_Editcomtype->setHidden(false);
    ui->newOkCancel_Edit->setHidden(false);

    if (edit == false)
    {
        viewingMode();
    }

    setModal(true);
    exec();

}

addnewcomputertype::~addnewcomputertype()
{
    delete ui;
}

bool addnewcomputertype::on_lineEdit_name_editingFinished()
{
    bool badName = true;
    if (ui->lineEdit_name->text().length() < 2)
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

//void addnewcomputertype::on_buttonBox_Editcomtype_rejected()
//{
//    addnewcomputertype::close();
//}

void addnewcomputertype::on_newOkCancel_New_accepted()
{
    if(on_lineEdit_name_editingFinished() == false)
    {
        ct.setName(ui->lineEdit_name->text().toStdString());
        ct.setDesc(ui->textEdit_descr->toPlainText().toStdString());
        serviceObject.servAddcomputerType(ct);
        serviceObject.servReadSqlCompTypes();
        addnewcomputertype::close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Name is too short. Try again!");
    }
}

void addnewcomputertype::on_newOkCancel_New_rejected()
{
    addnewcomputertype::close();
}

void addnewcomputertype::on_newOkCancel_Edit_accepted()
{
    string name = ui->lineEdit_name->text().toStdString();
    string descr = ui->textEdit_descr->document()->toPlainText().toStdString();
    int id = ui->labelComTypeID->text().toInt();

    QString debugname = QString::fromStdString(name);
    QString debugdescr = QString::fromStdString(descr);
    QString debugid = QString::number(id);

    if(on_lineEdit_name_editingFinished() == false)
    {
        //computer c(name, year, type, built, descr);
        //qDebug () << "debugname is " << debugname << "debugdescr is " << debugdescr << "debugid is "  << debugid;
        computertype ct(id, name, descr);
        serviceObject.servUpdateSqlComputerType(ct);
        serviceObject.servReadSqlCompTypes();
        addnewcomputertype::close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Name is too short. Try again!");
    }
}

void addnewcomputertype::on_newOkCancel_Edit_rejected()
{
    addnewcomputertype::close();
}

void addnewcomputertype::viewingMode()
{
    if (ui->textEdit_descr->toPlainText().length() == 0)
    {
        ui->textEdit_descr->setText(" ");
    }

    this->setWindowTitle("More information about the Computer Type");
    ui->newOkCancel_Edit->setHidden(true);

    ui->labelEntName->setText("Name: ");
    ui->lineEdit_name->setReadOnly(true);
    ui->labelEntDescr->setText("Description: ");
    ui->textEdit_descr->setReadOnly(true);
}
