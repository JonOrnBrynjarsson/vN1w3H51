#ifndef HELP_H
#define HELP_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QMessageBox>


namespace Ui {
class help;
}

class help : public QDialog
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = 0);
    void run();
    //  Precondition:   User is about to view help file
    //  Postcondition:  if file is present then text is shown, otherwise cancel.

    ~help();

private slots:
    void on_closeButton_clicked();
    //  Precondition:   User is viewing help file
    //  Postcondition:  modal is closed.
    bool readme();
    //  Precondition:   User is about to view help file
    //  Postcondition:  help file is read from resource, and printed on screen.

private:
    Ui::help *ui;
};

#endif // HELP_H
