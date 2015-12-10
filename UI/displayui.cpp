#include "displayui.h"
#include "ui_displayui.h"

displayUI::displayUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::displayUI)
{
    ui->setupUi(this);
}

displayUI::~displayUI()
{
    delete ui;
}
