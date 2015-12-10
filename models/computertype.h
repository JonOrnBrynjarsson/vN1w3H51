#ifndef COMPUTERTYPE_H
#define COMPUTERTYPE_H

#include <string>

using namespace  std;


class computertype
{
    public:
        /*
        ##  Constructors
        ##---------------------------------------------------------------------------------------##
        */
        computertype();
        // Precondition:    An instance of the class has been created.
        // Postcondition:   Initialises all string variablaes with an empty string,
        //                  integer and boolean variables as 0.
        computertype(int ctId, string ctName, string ctDesc);
        // Precondition:    An instance of the class has been created.
        // Postcondition:   Initialises id as ctId, name as ctName and desc as ctDesc.
        computertype(string ctName, string ctDesc);
        // Precondition:    An instance of the class has been created.
        // Postcondition:   Initialises name as ctName and desc as ctDesc, iD is created in the database.

        /*
        ##  Get functions
        ##---------------------------------------------------------------------------------------##
        */
        int getid();
        // Precondition:    The class has been initialised with a legal id.
        // Postcondition:   Returns an integer with the id of the computer type.
        string getName();
        // Precondition:    The class has been initialised with a legal name.
        // Postcondition:   Returns a string with the name of the computer type.
        string getDesc();
        // Precondition:    The class has been initialised with a legal description.
        // Postcondition:   Returns a string with the description.

        /*
        ##  Set functions
        ##---------------------------------------------------------------------------------------##
        */
        void setID(int inID);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The id has been set to the parameter inID.
        void setName(string inName);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The name has been set to the parameter inName.
        void setDesc(string inDesc);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The desc has been set to the parameter inDesc.

    private:
        int id;
        string name;
        string desc;

};

#endif // COMPUTERTYPE_H
