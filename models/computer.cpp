#include "Models/computer.h"

/*
##  Constructors
##---------------------------------------------------------------------------------------##
*/
computer::computer()
{
    comName = "";
    comYear = 0;
    comType = 0;
    comBuilt = false;
    comDescr = "";
}
computer::computer(string cName, int cYear, int cType, bool cBuilt, string cDescr)
{
    comName = cName;
    comYear = cYear;
    comType = cType;
    comBuilt = cBuilt;
    comDescr = cDescr;
}
computer::computer(int cid, string cName, int cYear, int cType, bool cBuilt, string cDescr)
{
    comId = cid;
    comName = cName;
    comYear = cYear;
    comType = cType;
    comBuilt = cBuilt;
    comDescr = cDescr;
}

/*
##  Get functions
##---------------------------------------------------------------------------------------##
*/
int computer::getId() const
{
    return comId;
}
string computer::getComName() const
{
    return comName;
}
int computer::getComYear() const
{
    return comYear;
}
int computer::getComType() const
{
    return comType;
}
string computer::getComDescription() const
{
    return comDescr;
}
bool computer::getComBuilt() const
{
    return comBuilt;
}

/*
##  Set functions
##---------------------------------------------------------------------------------------##
*/
void computer::setComID(int coID)
{
    comId = coID;
}
void computer::setComName(string coName)
{
    comName = coName;
}
void computer::setComYear(int coYear)
{
    comYear = coYear;
}
void computer::setComType(int coType)
{
    comType = coType;
}
void computer::setComDescription(string coDesc)
{
    comDescr = coDesc;
}
void computer::setComBuilt(bool coBuilt)
{
    comBuilt = coBuilt;
}

