#include "computeriu.h"
#include "ui_computeriu.h"

computerIU::computerIU(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::computerIU)
{
    ui->setupUi(this);
}

computerIU::~computerIU()
{
    delete ui;
}
