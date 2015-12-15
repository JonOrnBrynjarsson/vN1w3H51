#include "help.h"
#include "ui_help.h"

using namespace std;

help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
}

help::~help()
{
    delete ui;
}

void help::on_closeButton_clicked()
{
    help::close();
}

bool help::readme()
{
    QString fileName = "://nfo.txt";
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::warning(this, "Error", "File not found.");
            return false;
        }
        QTextStream in(&file);
        ui->infoBox->setText(in.readAll());
        file.close();
    }

    return true;
}

void help::run()
{
    if (readme())
    {
        exec();
    }
}
