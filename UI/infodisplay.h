#ifndef INFODISPLAY_H
#define INFODISPLAY_H
#include "services/service.h"
//#include "opengreeting.h"

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <time.h>
#include <unistd.h>

const unsigned int HOLYSCROLL = 15;


class infoDisplay
{
    public:
        /*
        ##  Constructors
        ##---------------------------------------------------------------------------------------##
        */
        infoDisplay();
        //Default constructor for class.

        /*
        ##  Main menu selection function.
        ##---------------------------------------------------------------------------------------##
        */
        void selectAction();
        //  Precondition:   The program is running.
        //  Postcondition:  Displays the main menu and takes in the selection from made.

    private:

        /*
        ##  Main menu
        ##---------------------------------------------------------------------------------------##
        */
        void mainMenu();
        //  Precondition:   None.
        //  Postcondition:  Displays the main menu on screen.
        void splashScreen();
        //  Precondition:   None.
        //  Postcondition:  Displays the startup greeting when program is started.

        /*
        ##  Scientist Information
        ##---------------------------------------------------------------------------------------##
        */
        void menuForScientists();
        //  Precondition:   On main menu working on scientist was selected.
        //  Postcondition:  Displays the menu to work on scientists on screen.
        void menuForScientistsDisplay();
        //  Postcondition:  Displays the menu text for scientist menu.
        void menuForScientistsSwitch();
        //  Postcondition:  Switches user between predermined selections for scientist menu.
        void listheaderSci();
        //  Precondition:   None.
        //  Postcondition:  Prints a header on the list of scientist.

        /*
        ##  Scientist Information##INPUT
        ##---------------------------------------------------------------------------------------##
        */
        bool addScientistContinue();
        //  Precondition:   A new scientist has been entered into the vector and the user is
        //                  asked if he wants to add more scientest.
        //  Postcondition:  Returns true if answered 'Y', false otherwise.
        void addScientist();
        //  Precondition:   The option to add scientist has been selected on the main mainu.
        //  Postcondition:  One or more scientists have been added to the sql database.
        string addScientistName();
        //  Precondition:   A name for a scientist is to be entered.
        //  Postcondition:  The name entered has been corrected or an error message has been
        //                  displayed on screen.
        int addScientistGender(string &gender);
        //  Precondition:   The gender for a scientist is to be entered.
        //  Postcondition:  The gender has been corrected or an error message has been
        //                  displayed on screen.
        int addScientistYearOfBirth();
        //  Precondition:   The year of birth for a scientist is to be entered.
        //  Postcondition:  The year of birth has been corrected or an error message has been
        //                  displayed on screen.
        bool addScientistMore(int yob, int &yod, string &descr, string &link);
        //  Precondition:   The necessary data for a new scientist is to be entered.
        //  Postcondition:  If required the new scientist has the field for year of death,
        //                  description and link have been populated.
        int addScientistYearOfDeath(int yob);
        //  Precondition:   The year of death for a scientist is to be entered.
        //  Postcondition:  The year of death has been corrected or an error message has been
        //                  displayed on screen.
        string addScientistDescription(string &descr);
        //  Precondition:   The description for a scientist is to be entered.
        //  Postcondition:  The description for a scientist has been entered.
        string addScientistLink(string &link);
        //  Precondition:   The link for a scientist is to be entered.
        //  Postcondition:  The link for a scientist has been entered.
        bool addScientistCheck(string name, int gender, int yob, int yod, string desc, string link);
        //  Precondition:   All data for a new scientist has been entered.
        //  Postcondition:  If approved scientist is added to private vector, else modified.
        void addScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender);
        //  Precondition:   Data for a new scientist have been entered. Asks if any of the
        //                  inserted data is to be changed.
        //  Postcondition:  Entered data for a new scientist has been corrected.

        /*
        ##  Scientist Information##EDIT
        ##---------------------------------------------------------------------------------------##
        */
//        void dispScientistToEdit(vector<scientist>& v);
        //  Precondition:   The vector v has been populated with scientist.
        //  Postcondition:  Selected scientist has is displayed on screen.
        void displayChangeScientist();
        //  Precondition:   A list of scientist has been displayed. Asks which scientist
        //                  to be edited.
        //  Postcondition:  The scientists to be changed have been edited.
        void editScientistDisplayService();
        //  Postcondition:  Intermediary between editing scientist.
        void displayScientistService();
        //  Postcondition:  Intermediary between editing computers.
        void editScientistService(unsigned int i);
        //  Precondition:   A scientist is about to be edited.
        //  Postcondition:  The scientist has been edited and sql database updated.

        /*
        ##  Scientist Information##REMOVE
        ##---------------------------------------------------------------------------------------##
        */
        void dispSelectScientistToDelete();
        //  Precondition:   The vector v has been populated with scientist.
        //  Postcondition:  Selected scientist has been removed from the sql database.
        bool dispSureToRemove(int gender);
        //  Precondition:   A scientist has been selected for deletion.  Takes the
        //                  gender as a parameter to select text to print.
        //  Postcondition:  If answered yes, the scientist is deleted. Else the action
        //                  is cancelled.

        /*
        ##  Computers Information
        ##---------------------------------------------------------------------------------------##
        */
        void menuForComputers();
        //  Precondition:   On main menu working on computers was selected.
        //  Postcondition:  Displays the menu to work on computers on screen.
        void menuForComputersDisplay();
        //  Postcondition:  Displays the menu text for computers menu.
        void menuForComputersSwitch();
        //  Postcondition:  Switches user between predermined selections for computers menu.
        void displayComputerService();
        //  Precondition:   List of computers is needed
        //  Postcondition:  Displays the list of computers.
        void listheaderCom();
        //  Precondition:   None.
        //  Postcondition:  Prints a header on the list of computers.

        /*
        ##  Computers Information##INPUT
        ##---------------------------------------------------------------------------------------##
        */
        void addComputer();
        //  Precondition:   The option to add a computer has been selected on the main menu.
        //  Postcondition:  One or more computers have been added to the sql database.
        string addComputerName();
        //  Precondition:   The computer name is to be selected.
        //  Postcondition:  a computer name has been selected.
        int addComputerYear();
        //  Precondition:   The computer year of creation is to be selected.
        //  Postcondition:  a computer year of creation has been selected.
        int addComputerType();
        //  Precondition:   The computer type is to be selected.
        //  Postcondition:  a computer type has been selected.
        bool addComputerBuilt();
        //  Precondition:   The computer built status is to be selected.
        //  Postcondition:  a build status has been selected.
        string addComputerDescr();
        //  Precondition:   The computer description is to be selected.
        //  Postcondition:  a description has been selected.
        bool addComputerCheck(string cName, int cYear, int cType, bool cBuilt, string cDescr);
        //  Precondition:   All data for a new computer has been entered.
        //  Postcondition:  User has been promted for change of input data.
        void addComputerChange(string &cName, int &cYear, int &cType, bool &cBuilt, string &cDescr);
        //  Precondition:   The option to change a computer has been selected on the main menu.
        //  Postcondition:  Intermediates to that goal.

        /*
        ##  Computers Information##EDIT
        ##---------------------------------------------------------------------------------------##
        */
        void displayChangeComputer();
        //  Precondition:   The computer to be changed is to be selected.
        //  Postcondition:  a computer has been selected.
        void editComputerDisplayService();
        //  Postcondition:  Intermediary between editing computer types.
        void editComputerService(unsigned int i);
        //  Precondition:   A computer is about to be edited.
        //  Postcondition:  The scientist has been edited and sql database updated.


        /*
        ##  Computers Information##REMOVE
        ##---------------------------------------------------------------------------------------##
        */
        void dispSelectComputerToDelete();
        //  Precondition:   The vector c has been populated with computers.
        //  Postcondition:  Selected computers has been removed from the sql database.
        bool dispSureToRemoveComp();
        //  Precondition:   A computer has been selected for deletion.
        //  Postcondition:  If answered yes, the computer is deleted. Else the action
        //                  is cancelled.

        /*
        ##  Computer Types
        ##---------------------------------------------------------------------------------------##
        */
        void menuForComputerTypes();
        //  Precondition:   On main menu working on computers was selected.
        //  Postcondition:  Displays the menu to work on computers on screen.
        void menuForComputersTypesDisplay();
        //  Postcondition:  Displays the menu text for computer types menu.
        void menuForComputersTypesSwitch();
        //  Postcondition:  Switches user between predermined selections for computer types menu.
        void listheaderComType();
        //  Postcondition:  prints header for computer type lists.
        void displayComTypeList();
        //  Postcondition:  prints header for computer lists.
        void displayComputerTypeService();
        //  Postcondition:  Intermediary between displaying computer types.

        /*
        ##  Computer Types##INPUT
        ##---------------------------------------------------------------------------------------##
        */
        void addNewComputerType();
        //  Precondition:   The option to add computer type has been selected on the main mainu.
        //  Postcondition:  One or more computers has been added.
        string addComputerTypeName();
        //  Precondition:   A name for a computer type is to be entered.
        //  Postcondition:  The name entered has been corrected and inserted to database.
        string addComputerTypeDescription(int &editCount);
        //  Precondition:   A description for a computer type is to be entered.
        //  Postcondition:  The name entered has been corrected and inserted to database.
        bool addComputerTypeCheck(string ctName, string ctDescr);
        //  Precondition:   All data for a new computer type has been entered.
        //  Postcondition:  User has been promted for change of input data.
        void addComputerTypeChange(string &ctName, string &ctDescr);
        //  Precondition:   All data for a new computer type has been entered.
        //  Postcondition:  If approved computer is added to sql database.

        /*
        ##  Computer Types##EDIT
        ##---------------------------------------------------------------------------------------##
        */
        void displayChangeNewComputerType();
        //  Precondition:   The option to change computer type has been selected on the main mainu.
        //  Postcondition:  Intermediates to that goal.
        void editComputerTypeDisplayService();
        //  Postcondition:  Intermediary between editing computer types.
        void editComputerTypeService(unsigned int i);
        //  Precondition:   All data for a new computer type can be changed.
        //  Postcondition:  User has been promted for change of input data.

        /*
        ##  Computer Types##REMOVE
        ##---------------------------------------------------------------------------------------##
        */
        void dispSelectNewComputerTypeToDelete();
        //  Precondition:   The option to remove computer type has been selected on the main mainu.
        //  Postcondition:  One or more computer types have been deleted


        /*
        ##  Computers and Scientists Relations
        ##---------------------------------------------------------------------------------------##
        */

        void displayComSciRelations();
        //  Precondition:   A scientist or computer have no relation.
        //  Postcondition:  A scientist or computer have a relation.
        void displayComSciRelationsMenu();
        //  Postcondition:  prints out selection for relations.
        void displayComSciRelationsSwitch();
        //  Postcondition:  Switches user between predermined selections for relations menu.
        void sciToComRelations(string sel);
        //  Precondition:   A scientist or computer have no relation.
        //  Postcondition:  A scientist or computer have a relation.

        /*
        ##  Search for Computer scientist
        ##---------------------------------------------------------------------------------------##
        */
        void displaySearchScientist();
        //  Precondition:   The vector of scientist is populated and ready to be
        //                  searched in.
        //  Postcondition:  Selected search option is carried out.
        void displaySearchScientistMenu();
        //  Postcondition:  prints out selection for search.
        void searchScientistSelection(int select);
        //  Precondition:   A specific search option has been selected. Takes in the
        //                  selection as an integer.
        //  Postcondition:  A vector of the correct scientist/s is displayed.

        /*
        ##  Search for Computers
        ##---------------------------------------------------------------------------------------##
        */
        void displaySearchComputer();
        //  Precondition:   The vector of computers is populated and ready to be
        //                  searched in.
        //  Postcondition:  Selected search option is carried out.
        void displaySearchComputersMenu();
        //  Postcondition:  prints out selection for search.
        void searchComputerSelection(int select);
        //  Precondition:   A specific search option has been selected. Takes in the
        //                  selection as an integer.
        //  Postcondition:  A vector of the correct computer/s is displayed.

        /*
        ##  List of computer scientists
        ##---------------------------------------------------------------------------------------##
        */
        void displaySciList();
        //  Precondition:   The scientist have been read from the database.
        //  Postcondition:  Displays all scientist according to condition on screen.
        void displayOneScientist(scientist& s);
        //  Precondition:   Takes in one scientist to display as a parameter.
        //  Postcondition:  Displays all information about the scientist on screen
        int moreInfoOnScientist();
        //  Precondition:   A list of scientist has been displayed.
        //  Postcondition:  Ask for which if any scientist to display fuller information on.
        //      Returns the selection.
        int displaySortScientistOptions();
        //  Precondition:   A list of scientist is to be displayed.
        //  Postcondition:  Displays the sorting options available and returns the selection.

        /*
        ##  List of computers
        ##---------------------------------------------------------------------------------------##
        */
        void displayOneComputer(computer& c);
        //  Precondition:   Takes in one computer to display as a parameter.
        //  Postcondition:  Displays all information about the computer on screen
        void displayComList();
        //  Precondition:   The computers have been read from the database.
        //  Postcondition:  Displays all computers according to condition on screen.
        int moreInfoOnComputer();
        //  Precondition:   A list of computers has been displayed.
        //  Postcondition:  Ask for which if any computer to display fuller information on.
        //      Returns the selection.
        int displaySortComputersOptions();
        //  Precondition:   A list of computers is to be displayed.
        //  Postcondition:  Displays the sorting options available and returns the selection.

        /*
        ##  List of computer types
        ##---------------------------------------------------------------------------------------##
        */
        void displayOneComputerType(computertype& ct);
        //  Precondition:   Takes in one computer type to display as a parameter.
        //  Postcondition:  Displays all information about the computer type on screen
        int moreInfoOnComputerTypes();
        //  Precondition:   A list of computer types has been displayed.
        //  Postcondition:  Ask for which if any computer types to display further information on.
        //      Returns the selection.


        /*
        ##  Miscellaneous
        ##---------------------------------------------------------------------------------------##
        */
        bool scrollNeeded(string comOrSci);
        //  Precondition:   checks if printed list is longer than HOLYSCROLL
        //  Postcondition:  returns true if scroll is nessacery.
        bool scrollFunction(unsigned int vSize, unsigned int &scrollBase, unsigned int &scrollFactor);
        //  Precondition:   list shows first HOLYSCROLL items.
        //  Postcondition:  scrolls list for user.
        void quitProgram();
        //  Precondition:   The program is about to be terminated.  User is asked if
        //                  he/she/it is sure.
        //  Postcondition:  The program has stopped running.
        void addEmptyLines(int numLines);
        //  Precondition:   None.
        //  Postcondition:  Adds empty lines to the screen output according to
        //                  the numLines parameter.
        int getCurrentDate (string date);
        //  Precondition:   A string with a date is sent as a parameter.
        //  Postcondition:  Returns the integer for the date sent in.
        int inputNumberToFunction();
        //  Precondition:   A number is about to be entered as an input
        //  Postcondition:  Returns a integer if correctly entered, or reiterate the input.
        char inputCharacterToFunction();
        //  Precondition:   A character is about to be entered as an input
        //  Postcondition:  Returns a character if correctly entered, or reiterate the input.
        void inputCharOrNumToFunction (int &num, char &letter, bool &type);
        //  Precondition:   A character or number is about to be entered as an input
        //  Postcondition:  Returns a character or number by refrence if correctly entered,
        //                  or reiterate the input.
        bool yesOrNo();
        //  Precondition:   A character is about to be entered to continue or quit.
        //  Postcondition:  Returns true if you should continue or false if not.
        void printLines(int lines, string thickness);
        //  prints lines
        void commonPhrases(string phrase);
        //  Precondition:   a string term is sent to function.
        //  Postcondition:  prints out common phrase, for easier scaling.
        void clearScreen();
        //  Precondition:   None.
        //  Postcondition:  Screen is blank.


        service serviceObject;
        // An object of the service layer class.
};

#endif // INFODISPLAY_H
