#include "helpui.h"
#include "ui_helpui.h"

HelpUI::HelpUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HelpUI)
{
    ui->setupUi(this);
}

HelpUI::~HelpUI()
{
    delete ui;
}
