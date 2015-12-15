#ifndef HELP_H
#define HELP_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

namespace Ui {
class help;
}

class help : public QDialog
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = 0);
    ~help();

private slots:
    void on_closeButton_clicked();
    void readme();

private:
    Ui::help *ui;
};

#endif // HELP_H
