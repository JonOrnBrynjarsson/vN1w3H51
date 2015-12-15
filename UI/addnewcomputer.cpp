#include "addnewcomputer.h"
#include "ui_addnewcomputer.h"

addnewcomputer::addnewcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addnewcomputer)
{
    ui->setupUi(this);
    ui->newOkCancel_Edit->setHidden(true);
    ui->label_computerID->setHidden(true);
    ui->label_relations->setHidden(true);
    ui->textBrowser_relations->setHidden(true);
    ui->errorInName->setHidden(true);
    ui->errorInYear->setHidden(true);

    serviceObject.servReadSqlCompTypes();

    for( unsigned int row = 0; row < serviceObject.servGetCompTypeVector().size(); row++)
    {
        ui->comboBox_type->insertItem(row+1, QString::fromStdString(
                                        serviceObject.servGetCompTypeVector().at(row).getName()), 0);
    }
}

void addnewcomputer::neweditcomputer(QString id, bool edit)
{
    int n = id.toInt(0,10);
    serviceObject.servReadSqlCompTypes();
    serviceObject.servReadSqlComputers("NAME");
    int currentID = 0;
    QString name, descr, comid, yoc;
    bool built;
    int type;

    for (unsigned int i = 0; i  < serviceObject.servGetComVector().size(); i++)
    {
        if(serviceObject.servGetComVector().at(i).getId() == n)
        {
            name = QString::fromStdString(serviceObject.servGetComVector().at(i).getComName());
            yoc = QString::number(serviceObject.servGetComVector().at(i).getComYear());
            type = serviceObject.servGetComVector().at(i).getComType();
            built = serviceObject.servGetComVector().at(i).getComBuilt();
            descr = QString::fromStdString(serviceObject.servGetComVector().at(i).getComDescription());
            comid = QString::number(serviceObject.servGetComVector().at(i).getId());
            currentID = serviceObject.servGetComVector().at(i).getId();
        }
    }
    QDate dYoc;

    dYoc.setDate(yoc.toInt(),1,1);

    ui->lineEdit_insertName->setText(name);
    ui->dateEdit_yoc->setDate(dYoc);
    ui->comboBox_type->setCurrentIndex(type-1);
    ui->checkBox_built->setChecked(built);
    ui->textEdit_insertDescription->setText(descr);
    ui->label_computerID->setText(comid);

    this->setWindowTitle("Edit Computer in the Database");
    ui->newOkCancel_Edit->setHidden(false);
    ui->newOkCancel_New->setHidden(true);

    if (edit == false)
    {
        viewingMode(currentID);
    }

    setModal(true);
    exec();
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

void addnewcomputer::on_newOkCancel_New_accepted()
{
    string name = ui->lineEdit_insertName->text().toStdString();
    int year = ui->dateEdit_yoc->date().year();
    int type = ui->comboBox_type->currentIndex();
    type = serviceObject.servGetCompTypeVector().at(type).getid();
    bool built = ui->checkBox_built->checkState();
    string descr = ui->textEdit_insertDescription->document()->toPlainText().toStdString();

    bool goodInput = false;

    if (on_lineEdit_insertName_editingFinished() == false &&
            on_dateEdit_yoc_editingFinished() == false)
    {
        goodInput = true;
    }

    if(goodInput)
    {
        computer c(name, year, type, built, descr);
        serviceObject.servAddcomputer(c);
        serviceObject.servReadSqlComputers();
        addnewcomputer::close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Name or year incorrectly entered!");
    }
}

void addnewcomputer::on_newOkCancel_New_rejected()
{
    addnewcomputer::close();
}

void addnewcomputer::on_newOkCancel_Edit_accepted()
{
    string name = ui->lineEdit_insertName->text().toStdString();
    int year = ui->dateEdit_yoc->date().year();
    int type = ui->comboBox_type->currentIndex();
    type = serviceObject.servGetCompTypeVector().at(type).getid();
    bool built = ui->checkBox_built->checkState();
    string descr = ui->textEdit_insertDescription->document()->toPlainText().toStdString();
    int id = ui->label_computerID->text().toInt();

    bool goodInput = false;

    if (on_lineEdit_insertName_editingFinished() == false && on_dateEdit_yoc_editingFinished() == false)
    {
        goodInput = true;
    }

    if(goodInput)
    {
        computer c(name, year, type, built, descr);
        c.setComID(id);
        serviceObject.servUpdateSqlComputer(c);
        serviceObject.servReadSqlComputers();
        addnewcomputer::close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Name or year incorrectly entered!");
    }
}

void addnewcomputer::on_newOkCancel_Edit_rejected()
{
    addnewcomputer::close();
}

void addnewcomputer::viewingMode(int currentID)
{
    if (ui->textEdit_insertDescription->toPlainText().length() == 0)
    {
        ui->textEdit_insertDescription->setText(" ");
    }

    this->setWindowTitle("More information about the Computer");
    ui->newOkCancel_Edit->setHidden(true);

    ui->label_enterName->setText("Name: ");
    ui->lineEdit_insertName->setReadOnly(true);
    ui->label_enterYear->setText("Year: ");
    ui->dateEdit_yoc->setReadOnly(true);
    ui->label_chooseType->setText("Type:");
    ui->comboBox_type->setEnabled(false);
    ui->label_chooseBuilt->setText("Built: ");
    ui->checkBox_built->setEnabled(false);
    ui->label_enterDescription->setText("Description:");
    ui->textEdit_insertDescription->setReadOnly(true);

    neweditcomputerRelations(currentID);
}

bool addnewcomputer::on_dateEdit_yoc_editingFinished()
{
    bool badYoc;

    if (ui->dateEdit_yoc->date().year() > CURRENTYEAR)
    {
        ui->errorInYear->setHidden(false);
        ui->errorInYear->setText("<font color='Red'>Computer can't be built in the future.</font>");
        badYoc = true;
    }
    else
    {
        ui->errorInYear->setHidden(true);
        badYoc = false;
    }
    return badYoc;
}
