#ifndef ADDNEWCOMPUTER_H
#define ADDNEWCOMPUTER_H

#include <QDialog>

namespace Ui {
class addnewcomputer;
}

class addnewcomputer : public QDialog
{
    Q_OBJECT

public:
    explicit addnewcomputer(QWidget *parent = 0);
    void editcomputer(int i, int x, bool &itt, QString name);
    ~addnewcomputer();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addnewcomputer *ui;
};

#endif // ADDNEWCOMPUTER_H
