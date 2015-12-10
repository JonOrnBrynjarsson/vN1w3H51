#include "addnewscientist.h"
#include "ui_addnewscientist.h"

addNewScientist::addNewScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNewScientist)
{
    ui->setupUi(this);
}

addNewScientist::~addNewScientist()
{
    delete ui;
}

void addNewScientist::on_buttonBox_accepted()
{

}
