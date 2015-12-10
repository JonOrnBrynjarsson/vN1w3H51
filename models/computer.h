#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>

using namespace std;

class computer
{
    public:
        /*
        ##  Constructors
        ##---------------------------------------------------------------------------------------##
        */
        computer();
        //Precondition:     An instance of the class has been created.
        //Postcondition:    Initializes all string variables as empty,
        //                  integer and boolean variables as 0.
        computer( int cid, string cname, int cyear, int ctype, bool cbuilt, string cdescription);
        //Precondition:     An instance of the class has been created.
        //Postcondition:    Initializes the id as cid, name as cname, year as cyear,
        //                  type as ctype, built as cbuilt and description as cdescription.
        computer(string cName, int cYear, int cType, bool cBuilt, string cDescr);
        //Precondition:     An instance of the class has been created.
        //Postcondition:    Initializes the name as cName, year as cYear, type as cType, built as cBuilt
        //                  type as cType, built as cBuilt and description as cDescr. The ID is created
        //                  in the database.

        /*
        ##  Get functions
        ##---------------------------------------------------------------------------------------##
        */
        int getId() const;
        // Precondition:    The class has been initialised with a legal ID.
        // Postcondition:   Returns the ID of the computer.
        string getComName() const;
        // Precondition:    The class has been initialised with a legal name.
        // Postcondition:   Returns the name of the computer.
        int getComYear() const;
        // Precondition:    The class has been initialised with a legal year.
        // Postcondition:   Returns the year when the computer was built.
        int getComType() const;
        // Precondition:    The class has been initialised with a legal type.
        // Postcondition:   Returns the type of the computer.
        string getComDescription() const;
        // Precondition:    The class has been initialised with a legal description.
        // Postcondition:   Returns the computers description.
        bool getComBuilt() const;
        // Precondition:    The class has been initialised with a legal built variable.
        // Postcondition:   Returns true if the computer was built, otherwise false.

        /*
        ##  Set functions
        ##---------------------------------------------------------------------------------------##
        */
        void setComID(int coID);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The id has been set to the parameter coID.
        void setComName(string coName);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The name has been set to the parameter coName.
        void setComYear(int coYear);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The year has been set to the parameter coYear.
        void setComType(int coType);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The type has been set to the parameter coType.
        void setComDescription(string coDesc);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The description has been set to the parameter coDescription.
        void setComBuilt(bool coBuilt);
        // Precondition:    The parameter is of a legal type and value.
        // Postcondition:   The built has been set to the parameter coBuilt.

    private:
        int comId;
        string comName;
        int comYear;
        int comType;
        bool comBuilt;
        string comDescr;
};

#endif // COMPUTER_H
