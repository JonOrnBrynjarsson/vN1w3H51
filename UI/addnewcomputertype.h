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

    ~addnewcomputertype();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addnewcomputertype *ui;
    void addCompTypetoDB(computertype &ct);
    void addCompTypeErrCorr(computertype &ct);
};

#endif // ADDNEWCOMPUTERTYPE_H
