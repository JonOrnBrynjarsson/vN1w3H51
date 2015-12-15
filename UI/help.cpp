#include "help.h"
#include "ui_help.h"

using namespace std;

help::help(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
    //ui->infoBox->setText();
    readme();
}

help::~help()
{
    delete ui;
}

void help::on_closeButton_clicked()
{
    help::close();
}

void help::readme()
{
    //RESOURCES += groupphotos.qrc;

    QString fileName = "://nfo.txt";
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            //qDebug()<<"Error. File not found";
            return;
        }
        QTextStream in(&file);
        //ui->TextArea->setText(in.readAll());
        ui->infoBox->setText(in.readAll());
        //ui->infoBox->setText("hello");
        file.close();
    }
}
