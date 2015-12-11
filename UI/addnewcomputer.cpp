#include "addnewcomputer.h"
#include "ui_addnewcomputer.h"

addnewcomputer::addnewcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addnewcomputer)
{
    ui->setupUi(this);
    service.servReadSqlCompTypes();

    for( unsigned int row = 0; row < service.servGetCompTypeVector().size(); row++)
    {
        ui->comboBox_type->insertItem(row+1, QString::fromStdString(
                                        service.servGetCompTypeVector().at(row).getName()), 0);
        qDebug () << QString::fromStdString(
                         service.servGetCompTypeVector().at(row).getName());
        //ui->buttonBox_addNewComputerFinished->
    }
}

addnewcomputer::~addnewcomputer()
{
    delete ui;
}


void addnewcomputer::on_buttonBox_addNewComputerFinished_accepted()
{
    string name = ui->lineEdit_insertName->text().toStdString();
    int year = ui->dateEdit_year->text().toInt();
    int type = ui->comboBox_type->currentIndex();
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
        //QMessageBox::warning(this, "Wrong year", "It is not possible to enter a futuristic computer");

    }
}
