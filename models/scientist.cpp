#include "Models/scientist.h"

/*
##  Constructors
##---------------------------------------------------------------------------------------##
*/
scientist::scientist()
{
    name = "";
    gender = 0;
    yearOfBirth=0;
    yearOfDeath=0;
    description = "";
    link = "";
}
scientist::scientist(int sid, string sname, int sgender, int syoBirth,int syoDeath, string sdesc, string slink)
{
    id = sid;
    name = sname;
    gender = sgender;
    yearOfBirth = syoBirth;
    yearOfDeath = syoDeath;
    description = sdesc;
    link = slink;
}
scientist::scientist(string sname, int sgender, int syoBirth,int syoDeath, string sdesc, string slink)
{
    name = sname;
    gender = sgender;
    yearOfBirth = syoBirth;
    yearOfDeath = syoDeath;
    description = sdesc;
    link = slink;
}

/*
##  Get functions
##---------------------------------------------------------------------------------------##
*/
int scientist::getID() const
{
    return id;
}
string scientist::getName() const
{
    return name;
}
int scientist::getGender() const
{
    return gender;
}
int scientist::getYearOfBirth() const
{
    return yearOfBirth;
}
int scientist::getYearOfDeath() const
{
    return yearOfDeath;
}
string scientist::getDescription() const
{
    return description;
}
string scientist::getLink() const
{
    return link;
}

/*
##  Set functions
##---------------------------------------------------------------------------------------##
*/
void scientist::setID(int inID)
{
    id = inID;
}
void scientist::setName(string inName)
{
    name = inName;
}
void scientist::setGender(int sex)
{
    gender = sex;
}
void scientist::setYearOfBirth(int birthYear)
{
    yearOfBirth = birthYear;
}
void scientist::setYearOfDeath(int deathYear)
{
    yearOfDeath = deathYear;
}
void scientist::setDescription(string desc)
{
    description = desc;
}
void scientist::setLink(string url)
{
    link = url;
}
