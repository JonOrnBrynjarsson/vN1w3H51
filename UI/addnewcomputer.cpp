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
    editcomputer(i,x,itt,name);

}

void addnewcomputer::editcomputer(int i, int x, bool &itt, QString name)
{
    qDebug () << "im here";
    ui->lineEdit_Name->setText("OLDNAMXXE");
    this->setWindowTitle("Remove");
}

addnewcomputer::~addnewcomputer()
{
    delete ui;
}

void addnewcomputer::on_buttonBox_accepted()
{
}
