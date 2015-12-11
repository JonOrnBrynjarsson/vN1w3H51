#include "addnewcomputertype.h"
#include "ui_addnewcomputertype.h"
#include "computertypeuiclass.h"
//#include "DataLayer/workingclass.h"
//#include <QDateEdit>
//#include <sstream>
//#include <QDebug>


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
    //computertypeuiclass ctc;

    //ctc.getComputerTypeData((ui->lineEdit_name->text().toStdString()),(ui->textBrowser_descr->toPlainText().toStdString()));
}
