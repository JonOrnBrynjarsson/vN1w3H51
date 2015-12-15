#ifndef ADDNEWCOMPUTERTYPE_H
#define ADDNEWCOMPUTERTYPE_H

#include <QDialog>
#include <string>
#include <QMessageBox>
#include <QTextStream>
#include "models/computertype.h"
#include "Services/service.h"
//#include "computertypeuiclass.h"

namespace Ui
{
    class addnewcomputertype;
}

class addnewcomputertype : public QDialog
{
    Q_OBJECT

public:
    explicit addnewcomputertype(QWidget *parent = 0);
    computertype ct;
    service serviceObject;
    int inputNumberToFunction(string input);
    void neweditcomputertype(QString id, bool edit);

    ~addnewcomputertype();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_Editcomtype_accepted();


    bool on_lineEdit_name_editingFinished();

    void on_buttonBox_Editcomtype_rejected();

private:
    Ui::addnewcomputertype *ui;
    void addCompTypetoDB(computertype &ct);
    void addCompTypeErrCorr(computertype &ct);
};

#endif // ADDNEWCOMPUTERTYPE_H
