#include "addnewcomputer.h"
#include "ui_addnewcomputer.h"
#include <QDebug>

addnewcomputer::addnewcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addnewcomputer)
{

    ui->setupUi(this);

}

void addnewcomputer::editcomputer(int i, int x, bool &itt, QString name)
{
    qDebug () << "im here";
    ui->lineEdit_Name->setText("OLDNAME");

}

addnewcomputer::~addnewcomputer()
{
    delete ui;
}

void addnewcomputer::on_buttonBox_accepted()
{
}
