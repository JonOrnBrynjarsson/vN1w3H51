#include "addnewcomputer.h"
#include "ui_addnewcomputer.h"

addnewcomputer::addnewcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addnewcomputer)
{
    ui->setupUi(this);
}

addnewcomputer::~addnewcomputer()
{
    delete ui;
}

void addnewcomputer::on_buttonBox_accepted()
{

}
