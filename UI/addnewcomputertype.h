#ifndef ADDNEWCOMPUTERTYPE_H
#define ADDNEWCOMPUTERTYPE_H

#include <QDialog>

namespace Ui {
class addnewcomputertype;
}

class addnewcomputertype : public QDialog
{
    Q_OBJECT

public:
    explicit addnewcomputertype(QWidget *parent = 0);
    ~addnewcomputertype();

private:
    Ui::addnewcomputertype *ui;
};

#endif // ADDNEWCOMPUTERTYPE_H
