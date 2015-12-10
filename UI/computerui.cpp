#include "computerui.h"
#include "ui_computerui.h"

computerUI::computerUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::computerUI)
{
    ui->setupUi(this);
}

computerUI::~computerUI()
{
    delete ui;
}
