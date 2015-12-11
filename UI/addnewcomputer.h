#ifndef ADDNEWCOMPUTER_H
#define ADDNEWCOMPUTER_H

#include <QDialog>
#include <QDebug>
#include <QVariant>
#include <Services/service.h>
#include <qmessagebox.h>

namespace Ui {
class addnewcomputer;
}

class addnewcomputer : public QDialog
{
    Q_OBJECT

public:
    explicit addnewcomputer(QWidget *parent = 0);
    ~addnewcomputer();

private slots:
    void on_buttonBox_addNewComputerFinished_accepted();
    void on_dateEdit_year_userDateChanged(const QDate &date);

private:

    service service;
    Ui::addnewcomputer *ui;
};

#endif // ADDNEWCOMPUTER_H
