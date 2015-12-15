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
    void neweditcomputer(QString id, bool edit);
    void neweditcomputerRelations(int currentID);
    ~addnewcomputer();

private slots:
    void on_buttonBox_addNewComputerFinished_accepted();
    void on_dateEdit_year_userDateChanged();//const QDate &date);

    void on_buttonBox_editComputerFinished_accepted();

    void on_buttonBox_editComputerFinished_rejected();

    //bool on_lineEdit_enterYear_editingFinished();

    bool on_lineEdit_insertName_editingFinished();

    void on_newOkCancel_New_accepted();

    void on_newOkCancel_New_rejected();

    void on_newOkCancel_Edit_accepted();

    void on_newOkCancel_Edit_rejected();

private:
    Ui::addnewcomputer *ui;
    service serviceObject;
};

#endif // ADDNEWCOMPUTER_H
