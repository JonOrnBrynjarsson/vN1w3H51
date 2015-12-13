#include "addnewcomputer.h"
#include "ui_addnewcomputer.h"
#include <QDebug>
#include "mainwindow.h"

addnewcomputer::addnewcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addnewcomputer)
{
    int i, x;
    bool itt;
    QString name;

    ui->setupUi(this);
    ui->buttonBox_editComputerFinished->setHidden(true);
    ui->label_computerID->setHidden(true);


    service.servReadSqlCompTypes();

    for( unsigned int row = 0; row < service.servGetCompTypeVector().size(); row++)
    {
        ui->comboBox_type->insertItem(row+1, QString::fromStdString(
                                        service.servGetCompTypeVector().at(row).getName()), 0);
    }


}

void addnewcomputer::neweditcomputer(QString id, bool edit)
{
    int n = id.toInt(0,10);
    service.servReadSqlCompTypes();
    service.servReadSqlComputers("NAME");

    QString name, descr, comid;
    bool built;
    int yoc, type;
    for (unsigned int i = 0; i  < service.servGetComVector().size(); i++)
    {
        if(service.servGetComVector().at(i).getId() == n)
        {
            name = QString::fromStdString(service.servGetComVector().at(i).getComName());
            yoc = service.servGetComVector().at(i).getComYear();
            type = service.servGetComVector().at(i).getComType();
            built = service.servGetComVector().at(i).getComBuilt();
            descr = QString::fromStdString(service.servGetComVector().at(i).getComDescription());
            comid = QString::number(service.servGetComVector().at(i).getId());
            qDebug () << name;
        }
    }
    QDate qdat;
    qdat.setDate(yoc,1,1);
    ui->lineEdit_insertName->setText(name);
    ui->dateEdit_year->setDate(qdat);
    ui->comboBox_type->setCurrentIndex(type-1);
    ui->checkBox_built->setChecked(built);
    ui->textEdit_insertDescription->setText(descr);
    ui->label_computerID->setText(comid);
    this->setWindowTitle("Edit Computer in the Database");
    ui->buttonBox_editComputerFinished->setHidden(false);
    ui->buttonBox_addNewComputerFinished->setHidden(true);

    if (edit == false)
    {
        this->setWindowTitle("More information about the Computer");
        ui->buttonBox_editComputerFinished->setHidden(true);

        ui->label_enterName->setText("Name: ");
        ui->lineEdit_insertName->setReadOnly(true);
        ui->label_enterYear->setText("Year: ");
        ui->dateEdit_year->setReadOnly(true);
        ui->label_chooseType->setText("Type:");
        ui->comboBox_type->setEnabled(false);
        ui->label_chooseBuilt->setText("Built: ");
        ui->checkBox_built->setEnabled(false);
        ui->label_enterDescription->setText("Description:");
        ui->textEdit_insertDescription->setReadOnly(true);
    }

    setModal(true);
    exec();

}
addnewcomputer::~addnewcomputer()
{

}


void addnewcomputer::on_buttonBox_addNewComputerFinished_accepted()
{
    string name = ui->lineEdit_insertName->text().toStdString();
    int year = ui->dateEdit_year->text().toInt();
    int type = ui->comboBox_type->currentIndex();
    type = service.servGetCompTypeVector().at(type).getid();
    bool built = ui->checkBox_built->checkState();
    string descr = ui->textEdit_insertDescription->document()->toPlainText().toStdString();

    if(name != "")
    {
        computer c(name, year, type, built, descr);
        service.servAddcomputer(c);
        service.servReadSqlComputers();
    }
    else
    {

        QMessageBox::warning(this, "Error", "You have to include a name for the computer!");
    }
}


void addnewcomputer::on_dateEdit_year_userDateChanged(const QDate &date)
{
    int year = ui->dateEdit_year->date().year();
    qDebug () << ui->dateEdit_year->date();
    if (year > CURRENTYEAR)
    {

        QMessageBox::information(this,"Wrong year","It is not possible to enter a futuristic computer",0);

    }
}

void addnewcomputer::on_buttonBox_editComputerFinished_accepted()
{
    qDebug () << "button pressed ";
    string name = ui->lineEdit_insertName->text().toStdString();
    int year = ui->dateEdit_year->text().toInt();
    int type = ui->comboBox_type->currentIndex();
    type = service.servGetCompTypeVector().at(type).getid();
    bool built = ui->checkBox_built->checkState();
    string descr = ui->textEdit_insertDescription->document()->toPlainText().toStdString();
    int id = ui->label_computerID->text().toInt();

    qDebug () << "id is : " << id ;

    if(name != "")
    {
        computer c(name, year, type, built, descr);
        c.setComID(id);
        service.servUpdateSqlComputer(c);
        service.servReadSqlComputers();
    }
    else
    {

        QMessageBox::warning(this, "Error", "You have to include a name for the computer!");
    }

    addnewcomputer::close();
}

void addnewcomputer::on_buttonBox_editComputerFinished_rejected()
{
    qDebug () << "close button press ";
    addnewcomputer::close();
}
