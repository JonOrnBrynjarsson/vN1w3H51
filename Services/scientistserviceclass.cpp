#include "scientistserviceclass.h"
#include "UI/addnewscientist.h"
#include <iostream>


using namespace std;

scientistserviceclass::scientistserviceclass()
{

}

void scientistserviceclass::getScientistData(string name, string descr, string link, string yob, string yod, int gender)
{
    sc.setName(name);
    sc.setDescription(descr);
    sc.setLink(link);
    sc.setGender(gender);
    sc.setYearOfBirth(serviceobject.inputNumberToFunction(yob));
    sc.setYearOfDeath(serviceobject.inputNumberToFunction(yod));

    addScientistErrorCorrection(sc);

}

void scientistserviceclass::addScientistToDatabase(scientist &sc)
{
    workingclass worker;
    worker.startDatabase();
    serviceobject.servAddscientist(sc);
}

void scientistserviceclass::addScientistErrorCorrection(scientist &sc)
{
    bool badName = false;
    bool errorInYOB = false;
    bool errorInYOD = false;
    sc.setName(serviceobject.nameCorrection(sc.getName(), badName));
    sc.setYearOfBirth(serviceobject.yearCorrection(sc.getYearOfBirth(), errorInYOB));
    sc.setYearOfDeath(serviceobject.yearCorrection(sc.getYearOfDeath(), errorInYOD));

    if (badName||errorInYOB||errorInYOD)
    {
        qDebug () << "ERROR IN NAME!" ;
    }
    else
    {
        addScientistToDatabase(sc);
        qDebug () << "NAME ADDED TO DATABASE!" ;
    }

}

