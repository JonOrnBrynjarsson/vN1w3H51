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
    ~AboutCreators();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AboutCreators *ui;
};

#endif // ABOUTCREATORS_H
