#ifndef ABOUTCREATORS_H
#define ABOUTCREATORS_H

#include <QDialog>

namespace Ui {
class AboutCreators;
}

class AboutCreators : public QDialog
{
    Q_OBJECT

public:
    explicit AboutCreators(QWidget *parent = 0);
    //constructor
    ~AboutCreators();

private slots:
    void on_pushButton_clicked();
    //  Precondition:   User is viewing about section
    //  Postcondition:  modal is closed.

private:
    Ui::AboutCreators *ui;
    //ui pointer
};

#endif // ABOUTCREATORS_H
