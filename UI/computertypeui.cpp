#include "computertypeui.h"
#include "ui_computertypeui.h"

computertypeUI::computertypeUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::computertypeUI)
{
    ui->setupUi(this);
}

computertypeUI::~computertypeUI()
{
    delete ui;
}
