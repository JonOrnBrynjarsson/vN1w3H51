#include "addnewscientist.h"
#include "ui_addnewscientist.h"
//#include "DataLayer/workingclass.h"
//#include "Services/scientistserviceclass.h"
//#include <QDateEdit>
//#include <sstream>
//#include <QDebug>

using namespace std;

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
    scientistuiclass ssc;

    ssc.getScientistData((ui->lineEdit_name->text().toStdString()),(ui->textEdit_descr->toPlainText().toStdString()),
                         (ui->lineEdit_link->text().toStdString()), (ui->lineEdit_yob->text().toStdString()),
                        (ui->lineEdit_yod->text().toStdString()), (ui->comboBox_gender->currentIndex()));
}
