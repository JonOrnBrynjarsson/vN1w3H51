#ifndef SERVICE_H
#define SERVICE_H

#include "datalayer/workingclass.h"

//#include <string>
//#include <unistd.h>
//#include <sstream>

const int CURRENTYEAR = 2015;

using namespace std;

class service
{
    public:

        /*
        ##  Constructors
        ##---------------------------------------------------------------------------------------##
        */
        service();
        //  Default constructor for class.

        /*
        ##  Correction functions
        ##---------------------------------------------------------------------------------------##
        */
        int yearCorrection(int year, bool &errorInYear);
        //  Precondition:   Takes in an integer for the year correction process.
        //  Postcondition:  Returns a corrected year.
        string nameCorrection(string name, bool& badName);
        //  Precondition:   A name has been entered into the parameter name.
        //  Postcondition:  Returns the corrected string and the badName variable is false
        //                  if the name is ok, true otherwise.
        int genderCorrection(string gender);
        //  Precondition:   Takes in a string for the gender correction process.
        //  Postcondition:  Returns 0 if female, 1 if male, 2 otherwise.
        int inputNumberToFunction(QString input);
        //  Precondition:   Takes in a string for the number
        //  Postcondition:  Returns integer.

        /*
        ##  Read functions
        ##---------------------------------------------------------------------------------------##
        */
        void servReadSqlScientists(string sorting="name");
        //  Calls the readSqlScientists function in workingclass.
        void servReadSqlComputers(string sorting="name");
        //  Calls the readSqlComputers function in workingclass.
        void servReadSqlCompTypes();
        //  Calls the readSqlCompTypes function in workingclass.
        void servReadSqlRelations();
        //  Calls the readSqlCompTypes function in workingclass.


        /*
        ##  Add functions
        ##---------------------------------------------------------------------------------------##
        */
        void servAddscientist(scientist& s) ;
        //  Calls the addscientist function in workingclass.
        void servAddcomputer(computer& c) ;
        //  Calls the addcomputer function in workingclass.
        void servAddcomputerType(computertype& ct) ;
        //  Calls the addcomputerType function in workingclass.
        bool servAddRelationSciComp(int sciID, int compID);
        //  Calls the addRelationSciComp function in workingclass.

        /*
        ##  Update functions
        ##---------------------------------------------------------------------------------------##
        */
        bool servUpdateSqlComputer(computer& c);
        //  Calls the updateScientist function in workingclass.
        void servUpdateSqlScientist(scientist& s);
        //  Calls the updateComputer function in workingclass.
        bool servUpdateSqlComputerType(computertype& ct);
        //  Calls the updateComputerType function in workingclass.

        /*
        ##  Delete functions
        ##---------------------------------------------------------------------------------------##
        */
        bool servDeleteComputer(int compID);
        //  Calls the deleteComputer function in workingclass.
        void servDeleteScientist(int sciID);
        //  Calls the deleteScientist function in workingclass.
        bool servDeleteComputerType(int computertypeID);
        //  Calls the deleteComputerType function in workingclass.
        bool servDeleteRelationSciComp(int sciID, int compID);
        //  Calls the deleteRelationSciComp function in workingclass.

        /*
        ##  Get vector functions
        ##---------------------------------------------------------------------------------------##
        */
        vector<scientist> servGetSciVector();
        //  Calls the getVector function in workingclass.
        vector<computer> servGetComVector();
        //  Calls the getVector function in workingclass.
        vector<computertype> servGetCompTypeVector();
        //  Calls the getComTypeVector function in workingclass.
        vector<relation> servGetRelationshipVector();
        //  Calls the getRelationshipVector function in workingclass.
        vector<scientist> servGetScientistsLinkedToComputer(int compID);
        //  Calls the getScientistsLinkedToComputer function in workingclass.
        vector<computer> servGetComputersLinkedToScientists(int sciID);
        //  Calls the getComputersLinkedToScientists function in workingclass.

        /*
        ##  Sort functions
        ##---------------------------------------------------------------------------------------##
        */
        void servClearSciVector();
        //  Calls the clearSciVector function in workingclass.
        void servClearComVector();
        //  Calls the clearComVector function in workingclass.


        /*
        ##  Sort functions
        ##---------------------------------------------------------------------------------------##
        */
        void servSortScientists(int choice);
        //  Precondition:   Takes in an interger to select sorting.
        //  Postcondition:  Reads scientists from database if selection is legal,
        //                  returns to main menu otherwise.
        void servSortComputers(int choice);
        //  Precondition:   Takes in an interger to select sorting.
        //  Postcondition:  Reads computers from database if selection is legal,
        //                  returns to main menu otherwise.

        /*
        ##  Search functions
        ##---------------------------------------------------------------------------------------##
        */
        void servSearchScientistByName(string subName, bool& isFound);
        //  Calls the searchByName function in workingclass.
        void servSearchScientistByGender(int sex, bool& isFound);
        //  Calls the searchByGender function in workingclass.
        void servSearchScientistByYear(int& yr, char bORd, bool& isFound);
        //  Calls the searchByYear function in workingclass.
        void servSearchComputerByName(string subName, bool& isFound);
        //  Calls the searchComputerByName function in workingclass.
        void servSearchComputerByType(string& type, bool& isFound);
        //  Calls the searchComputerByName function in workingclass.
        void servSearchComputerByYear(int& yr, bool& isFound);
        //  Calls the searchComputerByYear function in workingclass.
        void servSearchRelations(int column, string searchstr, bool& isFound);
        //  Calls the searchRelations function in workingclass.
        void servSearchComputerTypes(int column, string searchstr, bool& isFound);
        //  Calls the searchComputerTypes function in workingclass.


        /*
        ##  Database functions
        ##---------------------------------------------------------------------------------------##
        */
        void servStartDatabase();

        workingclass workingObject;
        // A object of the data layer class.

};


#endif // SERVICE_H
