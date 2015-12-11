#ifndef SCIENTISTUICLASS_H
#define SCIENTISTUICLASS_H

#include "UI/addnewscientist.h"
#include "ui_addnewscientist.h"
#include "models/scientist.h"
#include "Services/service.h"
#include <iostream>
#include <string>

class scientistuiclass
{
public:
    scientistuiclass();
    void getScientistData(string name, string descr, string link, string yob, string yod, int gender);
    void addScientistToDatabase(scientist &sc);
    void addScientistErrorCorrection(scientist &sc);

private:
    Ui::addNewScientist *sciUi;
    scientist sc;
    service serviceobject;
};

#endif // SCIENTISTUICLASS_H
