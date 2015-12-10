#include "addrelations.h"
#include "ui_addrelations.h"

addrelations::addrelations(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addrelations)
{
    ui->setupUi(this);
}

addrelations::~addrelations()
{
    delete ui;
}
