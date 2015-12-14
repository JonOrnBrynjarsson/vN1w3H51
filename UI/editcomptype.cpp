#include "editcomptype.h"
#include "ui_editcomptype.h"
//FORCE UPDATE!

editcomptype::editcomptype(QWidget *parent) :QDialog(parent),ui(new Ui::editcomptype)
{
    ui->setupUi(this);
}

editcomptype::~editcomptype()
{
    delete ui;
}

void editcomptype::on_buttonBox_editCompTypeFinished_accepted()
{
       string name = ui->lineEdit_Name->text().toStdString();
       string descr = ui->textEdit_Descr->document()->toPlainText().toStdString();

       if(name != "")
       {
           computertype ct(name, descr);
           serviceObject.servAddcomputerType(ct);
           serviceObject.servReadSqlCompTypes();
       }
       else
       {
           QMessageBox::warning(this,"Error","You have to include a name for the computertype!");
       }
}
