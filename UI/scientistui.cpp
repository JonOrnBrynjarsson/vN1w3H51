#include "scientistui.h"
#include "ui_scientistui.h"

scientistUI::scientistUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::scientistUI)
{
    ui->setupUi(this);
}

scientistUI::~scientistUI()
{
    delete ui;
}
