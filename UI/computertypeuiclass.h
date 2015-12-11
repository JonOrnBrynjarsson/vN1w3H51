#ifndef COMPUTERTYPEUICLASS_H
#define COMPUTERTYPEUICLASS_H

#include "UI/addnewcomputertype.h"
#include "ui_addnewcomputertype.h"
#include "models/computertype.h"
#include "Services/service.h"
#include <iostream>
#include <string>


class computertypeuiclass
{
public:
    computertypeuiclass();
    void getComputerTypeData(string name, string desc);
    void addCompTypetoDB(computertype &ct);
    void addCompTypeErrCorr(computertype &ct);

private:
    Ui::addnewcomputertype *ctUI;
    computertype ct;
    service serviceObject;


};

#endif // COMPUTERTYPEUICLASS_H
