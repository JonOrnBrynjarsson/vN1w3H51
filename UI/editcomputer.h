#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>
#include <qmessagebox.h>
#include "models/computer.h"
#include "Services/service.h"

namespace Ui {
class editcomputer;
}

class editcomputer : public QDialog
{
    Q_OBJECT

public:
    explicit editcomputer(QWidget *parent = 0);
    ~editcomputer();

private slots:
    void on_buttonBox_editComputerFinished_clicked();

private:
    service service;
    Ui::editcomputer *ui;
};

#endif // EDITCOMPUTER_H
