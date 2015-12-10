#include "Models/computertype.h"

/*
##  Constructors
##---------------------------------------------------------------------------------------##
*/

computertype::computertype()
{
    id = 0;
    name = "";
    desc = "";

}
computertype::computertype(int ctId, string ctName, string ctDesc)
{
    id = ctId;
    name = ctName;
    desc = ctDesc;
}
computertype::computertype(string ctName, string ctDesc)
{
    name = ctName;
    desc = ctDesc;
}

/*
##  Get functions
##---------------------------------------------------------------------------------------##
*/
int computertype::computertype::getid()
{
    return id;
}
string computertype::getName()
{
    return name;
}
string computertype::getDesc()
{
    return desc;
}

/*
##  Set functions
##---------------------------------------------------------------------------------------##
*/
void computertype::setID(int inID)
{
    id = inID;
}
void computertype::setName(string inName)
{
    name = inName;
}
void computertype::setDesc(string inDesc)
{
    desc = inDesc;
}
