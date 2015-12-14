#include "scientistuiclass.h"

using namespace std;


scientistuiclass::scientistuiclass()
{

}

void scientistuiclass::getScientistData(string name, string descr, string link, string yob, string yod, int gender)
{
//    sc.setName(name);
//    sc.setDescription(descr);
//    sc.setLink(link);
//    sc.setGender(gender);
//    sc.setYearOfBirth(serviceobject.inputNumberToFunction(yob));
//    sc.setYearOfDeath(serviceobject.inputNumberToFunction(yod));

//    addScientistErrorCorrection(sc);
}

void scientistuiclass::addScientistToDatabase(scientist &sc)
{
//    serviceobject.servStartDatabase();
//    serviceobject.servAddscientist(sc);
}

void scientistuiclass::addScientistErrorCorrection(scientist &sc)
{
//    bool badName = false;
//    bool errorInYOB = false;
//    bool errorInYOD = false;
//    sc.setName(serviceobject.nameCorrection(sc.getName(), badName));
//    sc.setYearOfBirth(serviceobject.yearCorrection(sc.getYearOfBirth(), errorInYOB));
//    sc.setYearOfDeath(serviceobject.yearCorrection(sc.getYearOfDeath(), errorInYOD));

//    if (badName||errorInYOB||errorInYOD)
//    {
//        qDebug () << "ERROR IN NAME!" ;

//        if (badName)
//        {
//            serviceobject.errorMessage("Name not correctly formatted. Please enter letters only.");
//        }
//        if (errorInYOB||errorInYOD)
//        {
//            serviceobject.errorMessage("Year not correctly formatted. Please enter valid years only.");
//        }
//    }
//    else
//    {
//        addScientistToDatabase(sc);
//        qDebug () << "NAME ADDED TO DATABASE!" ;
//        serviceobject.completeMessage("Name was successfully added to the Database!");
//        //FÆRA ÚR SERVICE CLASS.
//    }
}

