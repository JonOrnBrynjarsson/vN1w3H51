#ifndef SCIENTISTSERVICECLASS_H
#define SCIENTISTSERVICECLASS_H

#include "UI/addnewscientist.h"
#include "ui_addnewscientist.h"
//#include <QDateEdit>
//#include <sstream>
//#include <QDebug>
#include "models/scientist.h"
#include "Services/service.h"


class scientistserviceclass
{
public:
    scientistserviceclass();
    void getScientistData(string name, string descr, string link, string yob, string yod, int gender);
    void addScientistToDatabase(scientist &sc);
    void addScientistErrorCorrection(scientist &sc);

private:
    Ui::addNewScientist *sciUi;
    scientist sc;
    service serviceobject;
};

#endif // SCIENTISTSERVICECLASS_H
