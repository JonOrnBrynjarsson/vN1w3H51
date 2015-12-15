#ifndef ADDRELATIONS_H
#define ADDRELATIONS_H

#include <QDialog>
#include <vector>
#include "Services/service.h"
#include <QDebug>
#include <QMenu>
#include <QMouseEvent>
#include "DataLayer/workingclass.h"
#include "addnewscientist.h"
#include "addnewcomputer.h"
#include "addnewcomputertype.h"
#include "addrelations.h"
#include "editcomputer.h"

#include <QTableWidget>
#include <QActionGroup>

using namespace std;

namespace Ui {
class addrelations;
}

class addrelations : public QDialog
{
    Q_OBJECT

public:
    explicit addrelations(QWidget *parent = 0);
    QString getCurrentSciRowPos(QString &name);
    QString getCurrentComRowPos(QString &name);
    ~addrelations();

private slots:
   // void on_actionDisplay_a_List_of_Computers_triggered();
    void on_buttonBox_accepted();

    void on_lineEdit_filterScieentistAddRelation_textEdited(const QString &arg1);

    void on_lineEdit_filteComputersAddRelation_textEdited(const QString &arg1);

private:
    void displayAllScientists();
    void printScientists();//(std::vector<scientist> returnSciVector());
    void printComputers();
    Ui::addrelations *ui;
    service serviceobject;
    vector<scientist> returnSciVector();
    vector<computer> returnComVector();
};

#endif // ADDRELATIONS_H

