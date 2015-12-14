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
    ~addrelations();

private slots:
    void on_actionDisplay_a_List_of_Computer_Scientists_triggered();
    void on_tableWidget_chooseScientist_cellClicked(int row, int column);
   // void on_actionDisplay_a_List_of_Computers_triggered();
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
