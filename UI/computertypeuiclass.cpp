#include "computertypeuiclass.h"

using namespace std;

computertypeuiclass::computertypeuiclass()
{

}

void computertypeuiclass::getComputerTypeData(string name, string desc)
{
    ct.setName(name);
    ct.setDesc(desc);

    addCompTypeErrCorr(ct);
}

void computertypeuiclass::addCompTypetoDB(computertype &ct)
{
    serviceObject.servStartDatabase();
    serviceObject.servAddcomputerType(ct);
}

void computertypeuiclass::addCompTypeErrCorr(computertype &ct)
{
    bool badName = false;

    ct.setName(serviceObject.nameCorrection(ct.getName(), badName));

    if(badName)
    {
        qDebug() << "ERROR IN NAME!";

        if(badName)
        {
            serviceObject.errorMessage("Name not correctly formated, please enter letters only.");
        }

    }
    else
    {
        addCompTypetoDB(ct);
        qDebug() << "NAME ADDED TO DATABASE!";
        serviceObject.completeMessage("Name was succesfully added to the Database!");
    }
}

