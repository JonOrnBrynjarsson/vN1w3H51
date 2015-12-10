#ifndef ADDRELATIONS_H
#define ADDRELATIONS_H

#include <QDialog>

namespace Ui {
class addrelations;
}

class addrelations : public QDialog
{
    Q_OBJECT

public:
    explicit addrelations(QWidget *parent = 0);
    ~addrelations();

private:
    Ui::addrelations *ui;
};

#endif // ADDRELATIONS_H
