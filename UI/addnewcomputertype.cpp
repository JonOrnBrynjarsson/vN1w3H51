#include "addnewcomputertype.h"
#include "ui_addnewcomputertype.h"


addnewcomputertype::addnewcomputertype(QWidget *parent) :QDialog(parent),ui(new Ui::addnewcomputertype)
{
    ui->setupUi(this);
}

addnewcomputertype::~addnewcomputertype()
{
    delete ui;
}

void addnewcomputertype::on_buttonBox_accepted()
{

}
