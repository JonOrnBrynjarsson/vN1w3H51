#ifndef EDITCOMPTYPE_H
#define EDITCOMPTYPE_H

#include <QDialog>
#include <qmessagebox.h>
#include "models/computer.h"
#include "Services/service.h"

namespace Ui {
class editcomptype;
}

class editcomptype : public QDialog
{
    Q_OBJECT

public:
    explicit editcomptype(QWidget *parent = 0);
    ~editcomptype();

private slots:
    void on_buttonBox_editCompTypeFinished_accepted();

private:
    service serviceObject;
    Ui::editcomptype *ui;
};

#endif // EDITCOMPTYPE_H
