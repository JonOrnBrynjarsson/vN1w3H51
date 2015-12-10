#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <iostream>
#include <string>

using namespace std;

class scientist
{
    public:

        /*
        ##  Constructors
        ##---------------------------------------------------------------------------------------##
        */
        scientist();
        // Precondition:    An instance of the class has been created.
        // Postcondition:   Initialises all string variablaes with a space, integer and boolean variables as 0.
        scientist(int sid, string sname, int sgender, int syoBirth,int syoDeath, string sdesc, string slink);
        // Precondition:    All variables have been set with leagal values.
        // Postcondition:   Initialises all variables according to parameters.
        scientist(string sname, int sgender, int syoBirth,int syoDeath, string sdesc, string slink);
        // Precondition:    All variables have been set with leagal values.
        // Postcondition:   Initialises all variables exept id according to parameters.

        /*
        ##  Get functions
        ##---------------------------------------------------------------------------------------##
        */
        int getID() const;
        // Precondition:    The class has been initialised with a legal id.
        // Postcondition:   Returns an integer with the id of the famous scientist.
        string getName() const;
        // Precondition:    The class has been initialised with a legal name.
        // Postcondition:   Returns a string with the name of the famous scientist.
        int getGender() const;
        // Precondition:    The class has been initialised with a legal gender.
        // Postcondition:   Returns 0 for female and 1 for male.
        int getYearOfBirth() const;
        // Precondition:    The class has been initialised with a legal year of birth.
        // Postcondition:   Returns a integer with the year of birth.
        int getYearOfDeath() const;
        // Precondition:    The class has been initialised with a legal year of death.
        // Postcondition:   Returns a integer with the year of death.
        string getDescription() const;
        // Precondition:    The class has been initialised with a legal description.
        // Postcondition:   Returns a string with the description.
        string getLink() const;
        // Precondition:    The class has been initialised with a legal link.
        // Postcondition:   Returns a string with a link.

        /*
        ##  Set functions
        ##---------------------------------------------------------------------------------------##
        */
        void setID(int inID);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The id has been set to the parameter inID.
        void setName(string inName);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The name has been set to the parameter name.
        void setGender(int sex);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The gender has been set to the parameter sex.
        void setYearOfBirth(int birthYear);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The YearOfBirth has been set to parameter birthYear.
        void setYearOfDeath(int deathYear);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The YearOfDeath has been set to parameter deathYear.
        void setDescription(string desc);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The description has been set to parameter desc.
        void setLink(string url);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The link has been set to parameter url.

    private:
        int id;
        string name;
        int gender; //0. is Male, 1. is Female, 2 is Bad INPUT.
        int yearOfBirth;
        int yearOfDeath;
        string description;
        string link;
};


#endif // SCIENTIST_H
