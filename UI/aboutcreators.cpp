#include "aboutcreators.h"
#include "ui_aboutcreators.h"

AboutCreators::AboutCreators(QWidget *parent) :QDialog(parent),ui(new Ui::AboutCreators)
{
    ui->setupUi(this);
}

AboutCreators::~AboutCreators()
{
    delete ui;
}

void AboutCreators::on_pushButton_clicked()
{
    AboutCreators::close();
}
