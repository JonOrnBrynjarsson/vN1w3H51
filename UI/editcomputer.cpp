#include "editcomputer.h"
#include "ui_editcomputer.h"

editcomputer::editcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editcomputer)
{
    ui->setupUi(this);
}


editcomputer::~editcomputer()
{
    delete ui;
}

void editcomputer::on_buttonBox_editComputerFinished_clicked()
{
    string name = ui->lineEdit_Name->text().toStdString();
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
