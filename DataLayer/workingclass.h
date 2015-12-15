#ifndef WORKINGCLASS_H
#define WORKINGCLASS_H

#include "Models/scientist.h"
#include "Models/computer.h"
#include "Models/computertype.h"

#include <QtSql/QtSql>
#include <qfile.h>
#include <string>
#include <sstream>
#include <vector>
#include <QDebug>

const string DBASE = "../vN1w3H51/database/Group51_verklegt_1.sqlite";  // Locaton of the database file
const int MAXNAMELENGTH = 44;

using namespace std;

struct relation{
    int scientistID;
    int computerID;
    string scientistName;
    string computerName;
};

class workingclass
{
public:
    workingclass();
    //  Default constructor for class.

    /*
    ##  Read functions
    ##---------------------------------------------------------------------------------------##
    */
    void readSqlScientists(string sorting = "name ASC");
    //  Precondition:   The database is open.
    //  Postcondition:  If data available, it is read into the private vector for scientist.
    void readSqlComputers(string sorting = "name ASC");
    //  Precondition:   The database is open.
    //  Postcondition:  If data available, it is read into the private vector for computers.
    void readSqlCompTypes();
    //  Precondition:   The database is open.
    //  Postcondition:  If data available, it is read into the private vector for computertypes.
    void readSqlRelations();
    //  Precondition:   The database is open.
    //  Postcondition:  If data available, it is read into the private vector for computertypes.

    /*
    ##  Add functions
    ##---------------------------------------------------------------------------------------##
    */
    bool addscientist(scientist& s);
    //  Precondition:   The parameter s is a new scientist.
    //  Postcondition:  The scientist s is now added to the database and
    //                  s has been updated with the correct id.
    bool addcomputer(computer& c);
    //  Precondition:   The parameter c is a new computer.
    //  Postcondition:  The computer c is now added the database and
    //                  c has been updated with the correct id.
    bool addcomputerType(computertype& ct);
    //  Precondition:   The parameter ct is a new computer type.
    //  Postcondition:  The computer type ct is now added to the database
    //                  and ct has been updated with the correct id.
    bool addRelationSciComp(int sciID, int compID);
    //  Precondition:   Takes in id's of both an existing scientist and an existing computer.
    //  Postcondition:  Creates a link between the scientist and the computer in the database.
    //                   Returns true if the operations goes through, false otherwise.

    /*
    ##  Update functions
    ##---------------------------------------------------------------------------------------##
    */
    void updateSqlScientist(scientist& s);
    //  Precondition:   The parameter s is a scientist that has changes to it.
    //  Postcondition:  The scientist s is now updated with new information.
    bool updateSqlComputer(computer& c);
    //  Precondition:   The parameter c is a computer that has changes to it.
    //  Postcondition:  The computer c is now updated with new information.
    bool updateSqlComputerType(computertype& ct);
    //  Precondition:   The parameter ct is a computer type that has changes to it.
    //  Postcondition:  The computer type ct is now updated with new information.

    /*
    ##  Delete functions
    ##---------------------------------------------------------------------------------------##
    */
    void deleteScientist(int sciID);
    //  Precondition:   The parameter sciID is the ID of a scientist to be deleted.
    //  Postcondition:  The scientist sciID has been deleted from the database.
    bool deleteComputer(int compID);
    //  Precondition:   The parameter compID is the ID of a computer to be deleted.
    //  Postcondition:  The computer compID has been deleted from the database.
    bool deleteComputerType(int computertypeID);
    //  Precondition:   The parameter computertypeID is the ID of a computer type to be deleted.
    //  Postcondition:  The computer type computertypeID has been deleted from the database.
    bool deleteRelationSciComp(int sciID, int compID);
    //  Precondition:   The parameters sciID and compID are the IDs of a scientist and a computer
    //                  which relation is about to be deleted.
    //  Postcondition:  The relation between the scientist and the computer has been deleted from the database.

    /*
    ##  Get vector functions
    ##---------------------------------------------------------------------------------------##
    */
    vector<scientist> getSciVector();
    //  Precondition:   The private scientists vector has been populated
    //  Postcondition:  Returns the private vector.
    vector<computer> getComVector();
    //  Precondition:   The private computers vector has been populated
    //  Postcondition:  Returns the private vector.
    vector<computertype> getCompTypeVector();
    //  Precondition:   The private computer types vector has been populated
    //  Postcondition:  Returns the private vector.
    vector<computer> getComputersLinkedToScientists(int sciID);
    //  Precondition:   A computer is selected and its ID sent in as compID.
    //  Postcondition:  Returns a vector of scientist related to the computer.
    vector<scientist> getScientistsLinkedToComputer(int compID);
    //  Precondition:   A scientist is selected and its ID sent in as sciID.
    //  Postcondition:  Returns a vector of computers related to the scientist.
    vector<relation> getRelationshipVector();
    //  Precondition:   A relationship exists between at least one scientist and one computer.
    //  Postcondition:  Returns a vector of relationships between scientists and computers.

    /*
    ##  Search functions
    ##---------------------------------------------------------------------------------------##
    */
    void searchScientistByName(string subName, bool& isFound);
    //  Precondition:   Takes in the parameter subName to be searched for and a boolean
    //                  variable to indicate if found.
    //  Postcondition:  Returns a vector of the scientist matching the criteria.
    void searchScientistByGender(int sex, bool& isFound);
    //  Precondition:   Takes in the parameter sex to be searched for and a boolean
    //                  variable to indicate if found.
    //  Postcondition:  Returns a vector of the scientist matching the criteria.
    void searchScientistByYear(int& yr, char bORd, bool& isFound);
    //  Precondition:   Takes in the parameter year to be searched for, a char indicating
    //                  whether to look for the year of birth or year of death and a boolean
    //                  variable to indicate if found.
    //  Postcondition:  Returns a vector of the scientist matching the criteria.
    void searchComputerByName(string subName, bool& isFound);
    //  Precondition:   Takes in the parameter subName to be searched for and a boolean variable
    //                  to indicate if found.
    //  Postcondition:  Fills the private computers vector if found.
    void searchComputerByType(string& type, bool& isFound);
    //  Precondition:   Takes in the parameter type to be searched for and a boolean variable
    //                  to indicate if found.
    //  Postcondition:  Fills the private computers vector if found.
    void searchComputerByYear(int& yr, bool& isFound);
    //  Precondition:   Takes in the parameter year to be searched for and a boolean variable
    //                  to indicate if found.
    //  Postcondition:  Fills the private computers vector if found.

    void searchRelations(int column, string searchstr, bool& isFound);
    //  Precondition:   Takes in the parameters column ( 0 for scientist name, 1 for computer name) to be searched
    //                  for and a boolean variable to indicate if found.
    //  Postcondition:  Fills the private relations vector if found.

    void searchComputerTypes(int column, string searchstr, bool& isFound);
    //  Precondition:   Takes in the parameters column ( 0 for name, 1 for description) to be searched
    //                  for and a boolean variable to indicate if found.
    //  Postcondition:  Fills the private computers vector if found.

    /*
    ##  Database functions
    ##---------------------------------------------------------------------------------------##
    */
    QSqlDatabase startDatabase();
    //  Precondition:   The database is present in the build directory of the program.
    //  Postconditinon: A link to the database has been established.


private:

    vector<scientist> scientistVector;
    vector<computer> computerVector;
    vector<computertype> compTypeVector;
    vector<relation> relationVector;

};

#endif // WORKINGCLASS_H

