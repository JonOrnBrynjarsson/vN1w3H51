#include "removeui.h"
#include "ui_removeui.h"

removeUI::removeUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::removeUI)
{
    ui->setupUi(this);
}

removeUI::~removeUI()
{
    delete ui;
}
