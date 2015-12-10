#include "UI/infodisplay.h"

using namespace std;

/*
##  Constructors
##---------------------------------------------------------------------------------------##
*/
infoDisplay::infoDisplay()
{

}

/*
##  Main menu selection function.
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::selectAction()
{
    splashScreen();
    if(serviceObject.servCheckDatabaseExists())
    {
        serviceObject.servStartDatabase();
    }
    else
    {
        clearScreen();
        addEmptyLines(5);
        cout << "\tNo database available!\n" ;
        printLines(1,"thick");
        cout << "\tDo you want to create a new database? (Y/N): ";
        if(yesOrNo())
        {
            serviceObject.servCreateEmptyDatabase();
        }
        else
        {
            cout << "\tBefore the next program run could you";
            cout << "\tplease make sure the database is in the\n";
            cout << "\tprogram main folder before running the program\n";
            printLines(1,"thick");
            cout << "The program will now quit!\n";
            sleep(3);
        }
    }


    do
    {
        clearScreen();
        mainMenu();
        int sel = inputNumberToFunction();
        switch(sel)
            {
            case 1:     //  Working with scientists
                clearScreen();
                serviceObject.servEraseScientistVector();
                menuForScientists();
                break;
            case 2:     //  Working with computers
                clearScreen();
                serviceObject.servEraseComputerVector();
                menuForComputers();
                break;
            case 3:     //  Working with computer types
                clearScreen();
                serviceObject.servEraseCompTypeVector();
                menuForComputerTypes();
                break;
            case 4:
                displayComSciRelations();
                break;
            case 5:     //  Searching for scientist
                clearScreen();
                serviceObject.servEraseScientistVector();
                displaySearchScientist();
                break;
            case 6:     //  Searching for computers
                clearScreen();
                serviceObject.servEraseComputerVector();
                displaySearchComputer();
                break;
            case 7:     //  Displaying scientists
                clearScreen();
                serviceObject.servEraseScientistVector();
                displayScientistService();
                break;
            case 8:     //  Displaying computers
                clearScreen();
                serviceObject.servEraseComputerVector();
                displayComputerService();
                break;
            case 9:     //  Displaying computer types
                clearScreen();
                //serviceObject.servEraseCompTypeVector();
                displayComputerTypeService();
                break;


            default:
                clearScreen();
                addEmptyLines(10);
                quitProgram();
                addEmptyLines(10);
                break;
           }
        }
        while(true);

}

/*
##  Main menu
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::mainMenu()
{
    clearScreen();
    addEmptyLines(5);

    cout <<"\tToday is: ";
    cout <<getCurrentDate("day")<<"."<<getCurrentDate("month")<<"."<<getCurrentDate("year")<<endl;

    cout << "\tWelcome to the computers and scientists database! \n";
    printLines(1, "thin");
    cout << "\tWhat would you like to do? \n";
    cout << endl;
    cout << "\t1) Work on scientist information \n";
    cout << "\t2) Work on computer information \n";
    cout << "\t3) Work on computer types information \n";
    cout << "\t4) Add/Remove scientist to computer relations \n";
    cout << endl;
    cout << "\t5) Search for a computer scientist \n";
    cout << "\t6) Search for a famous computer \n";
    cout << endl;
    cout << "\t7) Display a list of computer scientists \n";
    cout << "\t8) Display a list of famous computers \n";
    cout << "\t9) Display a list of computer types \n";
    printLines(1, "thick");
    cout << "\tAll other digits exit the program: ";
}
void infoDisplay::splashScreen()
{
    opengreeting greet;

    greet.greetingPost();
}

/*
##  Scientist Information
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::menuForScientists()
{
    serviceObject.servReadSqlScientists();
    menuForScientistsDisplay();
    menuForScientistsSwitch();
}
void infoDisplay::menuForScientistsDisplay()
{
    clearScreen();
    addEmptyLines(5);
    cout << "\tMenu for work on scientist information " << endl;
    printLines(1, "thin");
    cout << "\t1) Add a new computer scientist \n";
    cout << "\t2) Delete existing scientist \n";
    cout << "\t3) Edit existing scientist \n";
    printLines(1, "thin");
    cout << "\tAll other digits for main menu \n";
    printLines(1, "thick");
    cout << "\tEnter your selection: ";
}
void infoDisplay::menuForScientistsSwitch()
{
    int i = inputNumberToFunction();

    switch (i)
    {
    case 1:     //  Add scientist
        addScientist();
        break;
    case 2:     //  Delete scientist
        displaySciList();
        dispSelectScientistToDelete();
        break;
    case 3:     //  Change scientist
        displayChangeScientist();
        break;
    default:
        commonPhrases("nothingsel");
    }
}
void infoDisplay::listheaderSci()
{
    clearScreen();
    addEmptyLines(5);
    cout.setf(ios::left);
    cout << "\tNr.";
    cout.width(30);
    cout << "\tName";
    cout << "Gender\tBorn" << endl;
    printLines(1,"thin");
}

/*
##  Scientist Information##INPUT
##---------------------------------------------------------------------------------------##
*/
bool infoDisplay::addScientistContinue()
{

    addEmptyLines(1);
    commonPhrases("continue");

    bool input = yesOrNo();
    return input;
}
void infoDisplay::addScientist()
{
    int selectedGender;
    bool wYLTContinue = true;

    scientist sO;

    while(wYLTContinue == true)
    {
        clearScreen();
        addEmptyLines(5);
        cout<<"\tCreating a new Scientist: "<<endl;
        printLines(1, "thick");
        string name = " ", gender = " ", descr = " ", link = " ";
        int yob = 0, yod = 0;

        name = (addScientistName());
        selectedGender = addScientistGender(gender);
        yob = (addScientistYearOfBirth());
        bool addEvenMore = true;
        while (addEvenMore == true)
        {
            addEvenMore = addScientistMore(yob, yod, descr, link);
        }
        bool changeInput = false;
        do
        {
            changeInput = addScientistCheck(name,selectedGender,yob,yod,descr,link);

            if (changeInput == false)
            {
                addScientistChange(name,gender,yob,yod,descr,link,selectedGender);
            }
        }
        while (changeInput == false);
        wYLTContinue = addScientistContinue();

        sO.setName(name);
        sO.setGender(selectedGender);

        sO.setYearOfBirth(yob);
        sO.setYearOfDeath(yod);
        sO.setDescription(descr);
        sO.setLink(link);

        serviceObject.servAddscientist(sO);
    };
}
string infoDisplay::addScientistName()
{
    cin.ignore();
    string name;
    bool badName = false;
    do
    {
        cout<<"\tEnter name: ";
        getline(cin, name);
        name = serviceObject.nameCorrection(name, badName);
        if (badName == true)
        {
            commonPhrases("badname");
        }
    }
    while(badName == true);
    return name;
}
int infoDisplay::addScientistGender(string &gender)
{
    int selectedGender;
    cout<<"\tEnter gender: ";
    cin>>gender;

    selectedGender = serviceObject.genderCorrection(gender);
    return selectedGender;
}
int infoDisplay::addScientistYearOfBirth()
{
    int temp;
    bool errorInYear = false;
    do
    {
        cout<<"\tEnter year of birth: ";

        temp = inputNumberToFunction();
        temp = serviceObject.yearCorrection(temp, errorInYear);

        if (errorInYear == true)
        {
            cout<<"\tIncorrect year format!"<<endl;
        }
    }
    while (errorInYear == true);

    return temp;
}
bool infoDisplay::addScientistMore(int yob, int &yod, string &descr, string &link)
{
    bool addAnother = true;
    int choice;

    addEmptyLines(5);
    cout<<"\t1. Add year of Death, 2. Description, "<<endl<<"\t3. Website link, \n";
    cout << "\tAny other digit continues: ";

    choice = inputNumberToFunction();

    switch(choice)
    {
        case 1:
        yod = addScientistYearOfDeath(yob);
        break;

        case 2:
        descr = addScientistDescription(descr);
        break;

        case 3:
        link = addScientistLink(link);
        break;

        default:
        commonPhrases("nothingsel");
        addAnother = false;
        sleep(1);
    }

    if (addAnother == true)
    {
        cout<<"\tAdd more fields? Y/N? ";
        addAnother = yesOrNo();
    }

    return addAnother;
}
int infoDisplay::addScientistYearOfDeath(int yob)
{
    bool errorInYear = false;
    int temp;

    do
    {
        cout<<"\tYear of Death: ";
        temp = inputNumberToFunction();

        temp = serviceObject.yearCorrection(temp, errorInYear);

        if (errorInYear == true)
        {
            cout<<"\tIncorrect year format!"<<endl;
        }

        if (temp < yob)
        {
            errorInYear = true;
            cout<<"\tYou can not die, before you have lived!"<<endl;
        }
    }
    while (errorInYear == true);
    return temp;
}
string infoDisplay::addScientistDescription(string &descr)
{
    cin.ignore();
    cout<<"\tDescription: ";
    getline(cin, descr);
    return descr;
}
string infoDisplay::addScientistLink(string &link)
{
    cin.ignore();
    cout<<"\tWebsite Link:";
    getline(cin, link);
    return link;
}
bool infoDisplay::addScientistCheck(string name, int gender, int yob, int yod, string desc, string link)
{
    clearScreen();
    addEmptyLines(5);
    cout<<"\tCurrent entry: "<<endl;
    printLines(1, "thick");
    cout<<"\tName: "<<name<<endl;
    if (gender == 1)
    {
        cout<<"\tGender: Male"<<endl;
    }
    else if (gender == 0)
    {
        cout<<"\tGender: Female"<<endl;
    }
    else
    {
        cout<<"\tGender: Unspecified"<<endl;
    }
    cout<<"\tYear of Birth: "<<yob<<endl;
    cout<<"\tYear of Death: "<<yod<<endl;

    if (desc.size() > 45)
    {
        cout<<"\tDescription: "<<desc.substr(0,45)<<"..."<<endl;
    }
    else
    {
        cout<<"\tDescription: "<<desc<<endl;
    }
    cout<<"\tLink: "<<link<<endl<<endl;

    cout<<"\tAre you happy with this input ? Y/N:";

    bool cont = yesOrNo();

    return cont;
}
void infoDisplay::addScientistChange(string &name, string gender, int &yob, int &yod, string &desc, string &link, int &selectedGender)
{

    int input = 0;
    int yOBirth = yob;

    addEmptyLines(1);
    commonPhrases("change");
    printLines(1,"thin");
    cout<<"\t1. Name, 2. Gender, 3. Year of Birth, 4. Year of Death \n\t5. Description, 6. Link, other digits cancel: ";
    input = inputNumberToFunction();

    switch (input)
    {
    case 1:
        name = addScientistName();
        break;
    case 2:
        selectedGender = addScientistGender(gender);
        break;
    case 3:
        yob = addScientistYearOfBirth();
        break;
    case 4:
        yod = addScientistYearOfDeath(yOBirth);
        break;
    case 5:
        desc = addScientistDescription(desc);
        break;
    case 6:
        link = addScientistLink(link);
        break;

    default:
        commonPhrases("nothingsel");
        break;
    }
}

/*
##  Scientist Information##EDIT
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::displayChangeScientist()
{
    bool continueP = true;

    while(continueP == true)
    {
        clearScreen();
        editScientistDisplayService();

        unsigned int i = 0;
        string name;

        cout << "\tEnter the number of the scientist you would like to edit: ";
        i = inputNumberToFunction();

        if ((i < 1)||(i > (serviceObject.servGetSciVector().size())))
        {
            continueP = false;
            commonPhrases("nothingsel");
        }
        else
        {
            displayOneScientist(serviceObject.servGetSciVector().at(i-1));
            editScientistService(i);
            clearScreen();
            continueP = addScientistContinue();
        }

    }
}
void infoDisplay::editScientistDisplayService()
{
    serviceObject.servReadSqlScientists();
    displaySciList();
}
void infoDisplay::displayScientistService()
{
    bool continueF = false;
    int searchSelection = 0;
    unsigned int choice = 0;
    do
    {
        choice = 0;
        continueF = false;
        searchSelection = displaySortScientistOptions();
        if (searchSelection != 0)
        {
            displaySciList();
            choice = moreInfoOnScientist();
        }

        if(choice > 0 && choice <= serviceObject.servGetSciVector().size())
        {
            displayOneScientist(serviceObject.servGetSciVector().at(choice-1));
        }
        addEmptyLines(1);

        if (choice != 0)
        {
            commonPhrases("continue");
            continueF = yesOrNo();
        }

    }
    while(continueF == true);

}
void infoDisplay::editScientistService(unsigned int i)
{

    if (i > serviceObject.servGetSciVector().size()-1)
    {
        commonPhrases("nothingsel");
    }
    else
    {
        string name, gender, descr, link;
        int selectedGender, yob, yod, id;

        name = serviceObject.servGetSciVector().at(i).getName();
        selectedGender = serviceObject.servGetSciVector().at(i).getGender();
        descr = serviceObject.servGetSciVector().at(i).getDescription();
        link = serviceObject.servGetSciVector().at(i).getLink();
        yob = serviceObject.servGetSciVector().at(i).getYearOfBirth();
        yod = serviceObject.servGetSciVector().at(i).getYearOfDeath();
        id = serviceObject.servGetSciVector().at(i).getID();
        bool continueP = false;

        while (continueP == false)
        {
            addScientistChange(name,gender,yob,yod,descr,link,selectedGender);
            continueP = addScientistCheck(name,selectedGender,yob,yod,descr,link);
        }

        scientist s(id,name,selectedGender,yob,yod,descr,link);
        serviceObject.servUpdateSqlScientist(s);
    }
}

/*
##  Scientist Information##REMOVE
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::dispSelectScientistToDelete()
{
    unsigned int sel;

    cout << "\tWhich scientist would you like delete?" << endl;
    commonPhrases("choice");
    sel = inputNumberToFunction();
    if(sel > 0  && sel < serviceObject.servGetSciVector().size()+1)
    {
        displayOneScientist(serviceObject.servGetSciVector().at(sel-1));
        if(dispSureToRemove(serviceObject.servGetSciVector().at(sel-1).getGender()))
        {
            serviceObject.servDeleteScientist(serviceObject.servGetSciVector().at(sel-1).getID());
        }
    }
    else
    {
        commonPhrases("nothingsel");
    }
}
bool infoDisplay::dispSureToRemove(int gender)
{
    addEmptyLines(2);
    cout << "\tAre you sure you would like to delete";
    if(gender == 0)
    {
        cout << " her: " << endl;
    }
    else if(gender == 1)
    {
        cout << " him: " << endl;
    }
    else
    {
        cout << " it: " << endl;
    }
    addEmptyLines(1);
    cout << "\tEnter (Y/N):";
    return yesOrNo();
}

/*
##  Computers Information
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::menuForComputers()
{
    serviceObject.servReadSqlComputers();
    menuForComputersDisplay();
    menuForComputersSwitch();
}
void infoDisplay::menuForComputersDisplay()
{
    clearScreen();
    addEmptyLines(5);
    cout << "\tMenu for work on computer information " << endl;
    printLines(1, "thin");
    cout << "\t1) Add a new computer \n";
    cout << "\t2) Delete existing computer \n";
    cout << "\t3) Edit existing computer \n";
    printLines(1, "thin");
    cout << "\tAll other digits for main menu \n";
    printLines(1, "thick");
    cout << "\tEnter your selection: ";
    sleep(2);
}
void infoDisplay::menuForComputersSwitch()
{
    int i = inputNumberToFunction();
    switch (i)
    {
    case 1:     //  Add computer.
        addComputer();
        break;
    case 2:     //  Delete computer.
        dispSelectComputerToDelete();
        break;
    case 3:     //  Edit computer.
        displayChangeComputer();
        break;
    default:
        commonPhrases("nothingsel");
    }


}
void infoDisplay::displayComputerService()
{
    bool continueF = false;
    int searchSelection = 0;
    unsigned int choice = 0;
    do
    {
        choice = 0;
        continueF = false;
        searchSelection = displaySortComputersOptions();
        if (searchSelection != 0)
        {
            displayComList();
            choice = moreInfoOnComputer();

        }

        if(choice > 0 && choice <= serviceObject.servGetComVector().size())
        {
            displayOneComputer(serviceObject.servGetComVector().at(choice-1));
        }

        addEmptyLines(1);

        if (choice != 0)
        {
            commonPhrases("continue");
            continueF = yesOrNo();
        }

    }
    while(continueF == true);

}
void infoDisplay::listheaderCom()
{
    clearScreen();
    addEmptyLines(5);
    cout.setf(ios::left);
    cout << "\tNr.";
    cout.width(30);
    cout << "\tName";
    cout << "\tYear\tType" << endl;
    printLines(1,"thin");
}

/*
##  Computers Information##INPUT
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::addComputer()
{
    bool wYLTContinue = true;
    bool changeInput = false;

    while(wYLTContinue == true)
    {
        clearScreen();
        addEmptyLines(5);
        cout<<"\tCreating a new Computer: "<<endl;


        printLines(1, "thick");
        string compName = " ", compDescr = " ";
        int compYear = 0, compType = 0;
        bool compBuilt;

        compName = (addComputerName());
        compYear = (addComputerYear());
        compType = (addComputerType());
        compBuilt = (addComputerBuilt());
        compDescr = (addComputerDescr());

        do
        {
            changeInput = addComputerCheck(compName, compYear, compType, compBuilt, compDescr);

            if (changeInput == false)
            {
                addComputerChange(compName,compYear,compType,compBuilt,compDescr);
            }
        }
        while (changeInput == false);
        commonPhrases("continue");
        wYLTContinue = yesOrNo();

        computer c(compName, compYear, compType, compBuilt, compDescr);
        serviceObject.servAddcomputer(c);

    };
}
string infoDisplay::addComputerName()
{
    cin.ignore();
    string compName;

        cout<<"\tEnter name: ";
        getline(cin, compName);

    return compName;
}
int infoDisplay::addComputerYear()
{
    int temp;
    bool errorInYear = false;
    do
    {
        cout<<"\tEnter year of creation: ";

        temp = inputNumberToFunction();

        temp = serviceObject.yearCorrection(temp, errorInYear);

        if (errorInYear == true)
        {
            cout<<"\tIncorrect year format!"<<endl;
        }
    }
    while (errorInYear == true);

    return temp;
}
int infoDisplay::addComputerType()
{
    serviceObject.servReadSqlCompTypes();

    computertype ct;

    unsigned int selection = 0;
    bool continueF = false;
    serviceObject.servReadSqlCompTypes();
    cout<<"\tSelect computer type: "<<endl;
    cout<<"\t";
    for (unsigned int i = 0; i < serviceObject.servGetCompTypeVector().size(); i++)
    {
        cout<<i+1<<") ";
        cout<<serviceObject.servGetCompTypeVector().at(i).getName();
        cout<<endl<<"\t";
    }
    cout<<"Enter selection : ";


    do
    {
        continueF = false;

        selection = inputNumberToFunction();
        if ((selection < 1)||(selection > serviceObject.servGetCompTypeVector().size()))
        {
            cout<<"\tBad selection, try again: ";
            continueF = true;
        }
    }
    while(continueF == true);

    return (selection);

}
bool infoDisplay::addComputerBuilt()
{
    cout<<"\tWas the computer built? Y/N: ";
    bool built = yesOrNo();

    return built;
}
string infoDisplay::addComputerDescr()
{
    cin.ignore();
    string descr;
    cout<<"\tDescription: ";
    getline(cin, descr);
    return descr;
}
bool infoDisplay::addComputerCheck(string cName, int cYear, int cType, bool cBuilt, string cDescr)
{
    clearScreen();
    addEmptyLines(5);
    cout<<"\tCurrent entry: "<<endl;
    printLines(1, "thick");
    cout<<"\tName: "<<cName<<endl;
    cout<<"\tYear of Creation: "<<cYear<<endl;
    cout<<"\tComputer Type: "<<serviceObject.servGetCompTypeVector().at(cType - 1).getName()<<endl;
    cout<<"\tWas the Computer built?: ";
    if (cBuilt == true)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }

    if (cDescr.size() > 45)
    {
        cout<<"\tDescription: "<<cDescr.substr(0,45)<<"..."<<endl;
    }
    else
    {
        cout<<"\tDescription: "<<cDescr<<endl;
    }
    cout<<"\tAre you happy with this input ? Y/N:";

    bool cont = yesOrNo();

    return cont;
}
void infoDisplay::addComputerChange(string &cName, int &cYear, int &cType, bool &cBuilt, string &cDescr)
{
    int input = 0;
    addEmptyLines(1);
    commonPhrases("change");
    printLines(1,"thin");
    cout<<"\t1. Name, 2. Year of Creation, 3. Type, 4. Built, 5. Description \n";
    cout << "\tother digits cancel: ";
    input = inputNumberToFunction();

    switch (input)
    {
    case 1:
        cName = addComputerName();
        break;
    case 2:
        cYear = addComputerYear();
        break;
    case 3:
        cType = addComputerType();
        break;
    case 4:
        cBuilt = addComputerBuilt();
        break;
    case 5:
        cDescr = addComputerDescr();
        break;
    default:
        commonPhrases("nothingsel");
        break;
    }
}

/*
##  Computers Information##EDIT
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::displayChangeComputer()
{
    bool continueP = true;

    while(continueP == true)
    {
        clearScreen();
        editComputerDisplayService();

        unsigned int i = 0;
        string name;

        cout << "\tEnter the number of the computer you would like to edit: ";
        i = inputNumberToFunction() - 1;

        if ((i < 1)||(i > serviceObject.servGetComVector().size()))
        {
            continueP = false;
            commonPhrases("nothingsel");
        }
        else
        {
            displayOneComputer(serviceObject.servGetComVector().at(i-1));
            editComputerService(i);
            clearScreen();
            continueP = addScientistContinue();
        }
    }
}
void infoDisplay::editComputerDisplayService()
{
    serviceObject.servReadSqlComputers();
    displayComList();
}
void infoDisplay::editComputerService(unsigned int i)
{

    if (i > serviceObject.servGetComVector().size()-1)
    {
        commonPhrases("nothingsel");
    }
    else
    {
        string cname, cdescr;
        int cyear, ctype, cid;
        bool cbuilt;

        cname = serviceObject.servGetComVector().at(i).getComName();
        cdescr = serviceObject.servGetComVector().at(i).getComDescription();
        cyear = serviceObject.servGetComVector().at(i).getComYear();
        ctype = serviceObject.servGetComVector().at(i).getComType();
        cbuilt = serviceObject.servGetComVector().at(i).getComBuilt();
        cid = serviceObject.servGetComVector().at(i).getId();

        bool continueP = false;

        while (continueP == false)
        {
            addComputerChange(cname,cyear,ctype,cbuilt,cdescr);
            continueP = addComputerCheck(cname,cyear,ctype,cbuilt,cdescr);
        }

        computer c(cid, cname, cyear, ctype, cbuilt, cdescr);
        serviceObject.servUpdateSqlComputer(c);
    }
}

/*
##  Computers Information##REMOVE
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::dispSelectComputerToDelete()
{
    unsigned int sel;

    displayComList();

    cout << "\tWhat computer would you like delete?" << endl;
    commonPhrases("choice");
    sel = inputNumberToFunction();
    if(sel > 0  && sel < serviceObject.servGetComVector().size()+1)
    {
        displayOneComputer(serviceObject.servGetComVector().at(sel-1));
        if(dispSureToRemoveComp())
        {
            serviceObject.servDeleteComputer(serviceObject.servGetComVector().at(sel-1).getId());
        }
    }
    else
    {
        commonPhrases("nothingsel");
    }
}
bool infoDisplay::dispSureToRemoveComp()
{
    addEmptyLines(2);
    cout << "\tAre you sure you would like to delete it: " << endl;

    addEmptyLines(1);
    cout << "\tEnter (Y/N):";
    bool continueF = yesOrNo();

    return continueF;
}

/*
##  Computer Types
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::menuForComputerTypes()
{
    serviceObject.servReadSqlCompTypes();
    menuForComputersTypesDisplay();
    menuForComputersTypesSwitch();
}
void infoDisplay::menuForComputersTypesDisplay()
{
    clearScreen();
    addEmptyLines(5);
    cout << "\tMenu for work on computer types " << endl;
    printLines(1, "thin");
    cout << "\t1) Add a new computer type \n";
    cout << "\t2) Delete a computer type \n";
    cout << "\t3) Edit existing computer type \n";
    printLines(1, "thin");
    cout << "\tAll other digits for main menu \n";
    printLines(1, "thick");
    cout << "\tEnter your selection: ";
}
void infoDisplay::menuForComputersTypesSwitch()
{
    int i = inputNumberToFunction();
    switch (i)
    {
    case 1:
        addNewComputerType();
        break;
    case 2:
        dispSelectNewComputerTypeToDelete();
        break;
    case 3:
        displayChangeNewComputerType();
        break;
    default:
        commonPhrases("nothingsel");
    }
}
void infoDisplay::listheaderComType()
{
    clearScreen();
    addEmptyLines(5);
    cout.setf(ios::left);
    cout << "\tNr.";
    cout.width(15);
    cout << "\tComputer Type";
    cout << "\tDescription"<<endl;
    printLines(1,"thin");
}
void infoDisplay::displayComTypeList()
{
    serviceObject.servReadSqlCompTypes();
    unsigned int ctSize = serviceObject.servGetCompTypeVector().size();
    unsigned int scrollFactor;
    if (ctSize > HOLYSCROLL)
    {
         scrollFactor = HOLYSCROLL;
    }
    else
    {
        scrollFactor = ctSize;
    }
    unsigned int scrollBase = 0;
    bool continueF;

    do
    {
        listheaderComType();

        for(unsigned int i = scrollBase; i < scrollFactor; i++)
        {
            computertype ct = serviceObject.servGetCompTypeVector().at(i);
            cout.width(2);
            cout << "\t" << i+1 << ")\t";
            cout.width(16);
            cout << ct.getName();
            if (ct.getDesc().size() >= 34)
            {
                string newstring = ct.getDesc().substr(0,34) + "...";
                cout<<newstring;
            }
            else if ((ct.getDesc().size() > 1)&&(ct.getDesc().size() < 25))
            {
                cout << ct.getDesc();
            }
            else
            {
                cout<<"\t";
            }
            cout<<endl;

        }
        if (scrollNeeded("com") == true)
        {
            continueF = scrollFunction(ctSize, scrollBase, scrollFactor);
        }
        else
        {
            continueF = false;
        }
    }
    while (continueF == true);

    printLines(1, "thin");
}
void infoDisplay::displayComputerTypeService()
{
    bool continueF = false;

    do
    {
        continueF = false;
        displayComTypeList();

        unsigned int choice = moreInfoOnComputerTypes();
        if(choice > 0 && choice < serviceObject.servGetCompTypeVector().size())
        {
            displayOneComputerType(serviceObject.servGetCompTypeVector().at(choice-1));
        }

        addEmptyLines(1);
        if (choice == 0)
        {
            commonPhrases("nothingsel");
        }
        else
        {
            commonPhrases("continue");
            continueF = yesOrNo();
        }
    }
    while(continueF == true);


}

/*
 ##  Computer Types##INPUT
 ##---------------------------------------------------------------------------------------##
 */
void infoDisplay::addNewComputerType()
{
    bool wYLTContinue = true;
    bool changeInput = false;

    computertype ct;

    while(wYLTContinue == true)
    {
        clearScreen();
        int editCount = 0;
        addEmptyLines(5);
        cout<<"\tCreating a new Computer Type: "<<endl;

        printLines(1, "thick");
        string ctName, ctDescr;
        ctName = (addComputerTypeName());
        ctDescr = (addComputerTypeDescription(editCount));

        do
        {
            changeInput = addComputerTypeCheck(ctName, ctDescr);

            if (changeInput == false)
            {
                addComputerTypeChange(ctName, ctDescr);
            }
        }
        while (changeInput == false);

        commonPhrases("continue");
        wYLTContinue = yesOrNo();

        ct.setName(ctName);
        ct.setDesc(ctDescr);

        serviceObject.servAddcomputerType(ct);

    };
}
string infoDisplay::addComputerTypeName()
{
    string compTypeName;
    bool badName = false;

    do
    {
        cin.ignore();
        cout<<"\tEnter name: ";
        getline(cin, compTypeName);
        serviceObject.nameCorrection(compTypeName, badName);

        if(badName == true)
        {
            commonPhrases("badname");
        }
    }
    while (badName == true);


    return compTypeName;
}
string infoDisplay::addComputerTypeDescription(int &editCount)
{
    if (editCount > 0)
    {
        cin.ignore();
    }
    string cTDescr;
    cout<<"\tDescription: ";
    getline(cin, cTDescr);
    return cTDescr;
}
bool infoDisplay::addComputerTypeCheck(string ctName, string ctDescr)
{
    clearScreen();
    addEmptyLines(5);
    cout<<"\tCurrent entry: "<<endl;
    printLines(1, "thick");
    cout<<"\tComputer Type: "<<ctName<<endl;

    if (ctDescr.size() > 45)
    {
        cout<<"\tDescription: "<<ctDescr.substr(0,45)<<"..."<<endl;
    }
    else
    {
        cout<<"\tDescription: "<<ctDescr<<endl;
    }
    commonPhrases("happy");

    bool cont = yesOrNo();

    return cont;
}
void infoDisplay::addComputerTypeChange(string &ctName, string &ctDescr)
{
    int input = 0;
    addEmptyLines(1);
    commonPhrases("change");
    printLines(1,"thin");
    cout<<"\t1. Type name, 2. Description, other digits cancel: ";
    input = inputNumberToFunction();
    int editcount = 1;
    switch (input)
    {
    case 1:
        ctName = addComputerTypeName();
        break;
    case 2:
        ctDescr = addComputerTypeDescription(editcount);
        break;
    default:
        commonPhrases("nothingsel");
        break;
    }
}

/*
##  Computer Types##EDIT
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::displayChangeNewComputerType()
{
    bool continueP = true;

    while(continueP == true)
    {
        clearScreen();
        editComputerTypeDisplayService();

        unsigned int i = 0;
        string name;

        cout << "\tEnter the number of the computer type you would like to edit: ";
        i = inputNumberToFunction()-1;

        if ( i+1 > 0 && i < serviceObject.servGetCompTypeVector().size())
        {
            displayOneComputerType(serviceObject.servGetCompTypeVector().at(i));
            editComputerTypeService(i);
            clearScreen();
            continueP = addScientistContinue();
        }
        else
        {
            continueP = false;
            commonPhrases("nothingsel");
        }
    }
}
void infoDisplay::editComputerTypeDisplayService()
{
    serviceObject.servReadSqlComputers();
    displayComTypeList();
}
void infoDisplay::editComputerTypeService(unsigned int i)
{
        string ctName, ctDesc;
        int ctId;

        ctId = serviceObject.servGetCompTypeVector().at(i).getid();
        ctName = serviceObject.servGetCompTypeVector().at(i).getName();
        ctDesc = serviceObject.servGetCompTypeVector().at(i).getDesc();
        bool continueP = false;

        while (continueP == false)
        {
            addComputerTypeChange(ctName, ctDesc);
            continueP = addComputerTypeCheck(ctName,ctDesc);
        }
        computertype ct(ctId, ctName, ctDesc);
        serviceObject.servUpdateSqlComputerType(ct);
}

/*
##  Computer Types##REMOVE
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::dispSelectNewComputerTypeToDelete()
{
    unsigned int sel;

    displayComTypeList();

    bool deleted;

    cout << "\tWhat computer Type would you like delete?" << endl;
    commonPhrases("choice");
    sel = inputNumberToFunction();
    if(sel > 0  && sel < serviceObject.servGetCompTypeVector().size()+1)
    {
        displayOneComputerType(serviceObject.servGetCompTypeVector().at(sel-1));
        if(dispSureToRemoveComp())
        {
            deleted = serviceObject.servDeleteComputerType(serviceObject.servGetCompTypeVector().at(sel-1).getid());

            if (deleted == true)
            {
                printLines(1,"thick");
                cout<<"\tDelete was successfull."<<endl;
                sleep(3);
            }
            else
            {
                printLines(1,"thick");
                cout<<"\tDelete failed. Check if Computer Type is \n\tlinked to a Computer and try again."<<endl;
                sleep(3);
            }

        }
    }
    else
    {
        commonPhrases("nothingsel");
    }
}

/*
##  Computers and Scientists Relations
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::displayComSciRelations()
{
    serviceObject.servReadSqlComputers();
    serviceObject.servReadSqlScientists();
    displayComSciRelationsMenu();
    displayComSciRelationsSwitch();
}
void infoDisplay::displayComSciRelationsMenu()
{
    clearScreen();
    addEmptyLines(5);
    cout << "\tMenu for work on a relation between a scientist and a computer" << endl;
    printLines(1, "thin");
    cout << "\t1) Connect a Scientist and a computer \n";
    cout << "\t2) Remove connection between a scientist and a computer \n";
    printLines(1, "thin");
    cout << "\tAll other digits for main menu \n";
    printLines(1, "thick");
    cout << "\tEnter your selection: ";
}
void infoDisplay::displayComSciRelationsSwitch()
{
    int input = inputNumberToFunction();
    switch (input)
    {
    case 1:
        sciToComRelations("add");
        break;
    case 2:
        sciToComRelations("remove");
        break;

    default:
        commonPhrases("nothingsel");
        break;
    }
}
void infoDisplay::sciToComRelations(string sel)
{
    string placeholder = " ";
    if (sel == "add")
    {
        placeholder = "add";
    }
    else if (sel == "remove")
    {
        placeholder = "remove";
    }
    clearScreen();
    addEmptyLines(5);
    cout<<"\tSelect the scientist you want to "<<placeholder<<" Relations to";
    for (int i = 0; i < 3; i++)
    {
        cout<<".";
        sleep(1);
    }

    displaySciList();

    int sciID = 0;
    int comID = 0;

    cout<<"\tInput selection: ";
    unsigned int choiceSc = inputNumberToFunction();

    if(choiceSc > 0 && choiceSc < serviceObject.servGetSciVector().size())
    {
        sciID = serviceObject.servGetSciVector().at(choiceSc-1).getID();
    }

    clearScreen();
    addEmptyLines(5);
    cout<<"\tNow select the computer";
    for (int i = 0; i < 3; i++)
    {
        cout<<".";
        sleep(1);
    }
    displayComList();

    cout<<"\tInput selection: ";
    unsigned int choiceC = inputNumberToFunction();

    if(choiceC > 0 && choiceC < serviceObject.servGetComVector().size())
    {
        comID = serviceObject.servGetComVector().at(choiceC-1).getId();
    }

    bool error = false;

    if (sel == "add")
    {
        error = serviceObject.servAddRelationSciComp(sciID, comID);
    }
    else if (sel == "remove")
    {
        error = serviceObject.servDeleteRelationSciComp(sciID, comID);
    }

    if (error == true)
    {
        clearScreen();
        addEmptyLines(5);
        cout<<"\tOperation succeeded!";
        sleep(2);
    }
    else
    {
        clearScreen();
        addEmptyLines(5);
        cout<<"\tOperation failed!";
        sleep(2);
    }
    addEmptyLines(1);

}

/*
##  Search for Computer scientist
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::displaySearchScientist()
{
    int sel;
    serviceObject.servReadSqlScientists();
    displaySearchScientistMenu();
    sel = inputNumberToFunction();
    searchScientistSelection(sel);
}
void infoDisplay::displaySearchScientistMenu()
{
    addEmptyLines(5);
    cout << "\tMenu for a scientist search " << endl;
    printLines(1, "thin");
    cout << "\t1) Search by name or part of a name" << endl;
    cout << "\t2) Search by gender." << endl;
    cout << "\t3) Search by year of birth" << endl;
    cout << "\t4) Search by year of death" << endl;
    printLines(1, "thin");
    cout << "\tAll other digits for main menu \n";
    printLines(1, "thick");
    cout << "\tEnter your selection: ";
}
void infoDisplay::searchScientistSelection(int select)
{
    serviceObject.servReadSqlScientists();
    bool continueF = false;
    switch (select)
    {
    case 1:     //  Search by name

        do
        {
            string tempName;
            bool found = false;

            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter a part of the name you would like to find: ";
            cin >> tempName;
            serviceObject.servSearchScientistByName(tempName, found);
            if(found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displaySciList();
                    sel = moreInfoOnScientist();
                    if(sel > 0 && sel <= serviceObject.servGetSciVector().size())
                    {
                        displayOneScientist(serviceObject.servGetSciVector().at(sel-1));
                    }
                    else
                    {
                        break;
                    }
                }
                while(sel > 0 && sel < serviceObject.servGetSciVector().size());
                continueF = false;
            }
            else
            {
                commonPhrases("nothingfound");
                continueF = yesOrNo();
            }
        }
        while(continueF == true);
        break;
    case 2:     //  Search by gender
        do
        {
            string tempGender;
            bool found = false;
            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter the gender you would like to see: ";
            cin >> tempGender;
            serviceObject.servSearchScientistByGender(serviceObject.genderCorrection(tempGender), found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displaySciList();
                    sel = moreInfoOnScientist();
                    if(sel > 0 && sel <= serviceObject.servGetSciVector().size())
                    {
                        displayOneScientist(serviceObject.servGetSciVector().at(sel-1));
                    }
                    else
                    {
                        break;
                    }
                }
                while(sel > 0 && sel < serviceObject.servGetSciVector().size());
                continueF = false;
            }
            else
            {
                commonPhrases("nothingfound");
                continueF = yesOrNo();
            }
        }
        while(continueF == true);
        break;
    case 3:     //  Search by year of birth
        do
        {
            int yr;
            bool found = false;

            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter the year you would like to search for: ";
            yr = inputNumberToFunction();
            serviceObject.servSearchScientistByYear(yr, 'b', found);

            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displaySciList();
                    sel = moreInfoOnScientist();
                    if(sel > 0 && sel <= serviceObject.servGetSciVector().size())
                    {
                        displayOneScientist(serviceObject.servGetSciVector().at(sel-1));
                    }
                    else
                    {
                        break;
                    }
                }
                while(sel > 0 && sel <= serviceObject.servGetSciVector().size());
                continueF = false;
            }
            else
            {
                commonPhrases("nothingfound");
                continueF = yesOrNo();
            }

        }
        while(continueF == true);
        break;
    case 4:     //  Search by year of death
        do
        {
            int yr;
            bool found = false;

            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter the year you would like to search for: ";
            cin >> yr;
            serviceObject.servSearchScientistByYear(yr, 'd', found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displaySciList();
                    sel = moreInfoOnScientist();
                    if(sel > 0 && sel < serviceObject.servGetSciVector().size())
                    {
                        displayOneScientist(serviceObject.servGetSciVector().at(sel-1));
                    }
                    else
                    {
                        break;
                    }
                }
                while(sel > 0 && sel < serviceObject.servGetSciVector().size());
                continueF = false;

            }
            else
            {
                commonPhrases("nothingfound");
                continueF = yesOrNo();
            }

        }
        while(continueF == true);
        break;
    default:
        commonPhrases("nothingsel");
        break;
    }
}

/*
##  Search for Computers
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::displaySearchComputer()
{

    int sel;
    serviceObject.servReadSqlComputers();
    displaySearchComputersMenu();
    sel = inputNumberToFunction();
    searchComputerSelection(sel);
}
void infoDisplay::displaySearchComputersMenu()
{
    addEmptyLines(5);
    cout << "\tMenu for a computer search " << endl;
    printLines(1, "thin");
    cout << "\t1) Search by name or part of a name" << endl;
    cout << "\t2) Search by computer type" << endl;
    cout << "\t3) Search by the building year" << endl;
    printLines(1, "thin");
    cout << "\tAll other digits for main menu \n";
    printLines(1, "thick");
    cout << "\tEnter your selection: ";
}
void infoDisplay::searchComputerSelection(int select)
{
    serviceObject.servReadSqlComputers();
    bool continueF = false;

    switch (select)
    {
    case 1:     //  Search by name
    {
        string tempName;
        bool found = false;

        clearScreen();
        addEmptyLines(5);
        cout << "\tPlease enter a part of the name you would like to find: ";
        cin >> tempName;
        serviceObject.servSearchComputerByName(tempName, found);
        if(found == true)
        {
            unsigned int sel;
            clearScreen();

            displayComList();

            sel = moreInfoOnComputer();

            if((sel > 0) && (sel <= serviceObject.servGetComVector().size()))
            {
                displayOneComputer(serviceObject.servGetComVector().at(sel-1));
            }

        }
        else
        {
            commonPhrases("nothingfound");
            continueF = yesOrNo();
        }

        break;
    }
    case 2:     //  Search by type
        do
        {
            string tempType;
            bool found = false;
            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter a part of the type you would like to see: ";
            cin >> tempType;
            serviceObject.servSearchComputerByType(tempType, found);
            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displayComList();
                    sel = moreInfoOnComputer();
                    if(sel > 0 && sel <= serviceObject.servGetComVector().size())
                    {
                        displayOneComputer(serviceObject.servGetComVector().at(sel-1));
                    }
                }
                while(sel > 0 && sel < serviceObject.servGetComVector().size());
                continueF = false;

            }
            else
            {
                commonPhrases("nothingfound");
                continueF = yesOrNo();
            }
        }
        while(continueF == true);

        break;
    case 3:     //  Search by year
        do
        {
            int yr;
            bool found = false;

            clearScreen();
            addEmptyLines(5);
            cout << "\tPlease enter the year you would like to search for: ";
            yr = inputNumberToFunction();
            serviceObject.servSearchComputerByYear(yr, found);

            if( found == true)
            {
                unsigned int sel;
                do
                {
                    clearScreen();
                    displayComList();
                    sel = moreInfoOnComputer();
                    if(sel > 0 && sel <= serviceObject.servGetComVector().size())
                    {
                        displayOneComputer(serviceObject.servGetComVector().at(sel-1));
                    }

                }
                while(sel > 0 && sel <= serviceObject.servGetComVector().size());
                continueF = false;

            }
            else
            {
                commonPhrases("nothingfound");
                continueF = yesOrNo();
            }

        }
        while(continueF == true);
        break;

    default:
        commonPhrases("nothingsel");
        break;
    }
}

/*
##  List of computer scientists
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::displaySciList()
{
    unsigned int vSize = serviceObject.servGetSciVector().size();
    unsigned int scrollFactor;
    if (vSize > HOLYSCROLL)
    {
         scrollFactor = HOLYSCROLL;
    }
    else
    {
        scrollFactor = vSize;
    }
    unsigned int scrollBase = 0;
    bool continueF;

    do
    {
        listheaderSci();
        for(unsigned int i = scrollBase; i < scrollFactor; i++)
        {
            scientist s = serviceObject.servGetSciVector().at(i);
            cout.width(2);
            cout << "\t" << i+1 << ")\t";
            cout.width(30);

            string newstring;

            if (s.getName().size() > 26)
            {
                newstring = s.getName().substr(0,26) + "...";
                cout<<newstring;
            }
            else
            {
                cout << s.getName();
            }

            if(s.getGender() == 0)
            {
                cout << "female";
            }
            else
            {
                cout << "male";
            }
            cout << "\t" << s.getYearOfBirth()<< "\t" << endl;
        }

        if (scrollNeeded("sci"))
        {
            continueF = scrollFunction(vSize, scrollBase, scrollFactor);
        }
        else
        {
            continueF = false;
        }
    }
    while (continueF == true);
    printLines(1, "thin");
}
void infoDisplay::displayOneScientist(scientist& s)
{
    clearScreen();
    addEmptyLines(5);
    cout << "\tName: " << s.getName() << endl;
    cout << "\tGender: ";
    if(s.getGender()== 0)
    {
        cout << "Female" << endl;
    }
    else if (s.getGender()== 1)
    {
        cout << "male" << endl;
    }
    else
    {
        cout << "Unspecified" <<endl;
    }
    cout << "\tDate of birth: " << s.getYearOfBirth() << endl;

    if (s.getYearOfDeath() != 0)
    {
        cout << "\tDate of death: " << s.getYearOfDeath() << endl;
        int ageAtDeath = s.getYearOfDeath() - s.getYearOfBirth();
        cout << "\tAge at death: "<<ageAtDeath<<endl;
    }
    else
    {
        cout<<"\tCurrent age: ";

        int today = (getCurrentDate("year") * 365) + getCurrentDate("day");

        int sciAge = today - (s.getYearOfBirth() * 365);

        sciAge = sciAge / 365;

        cout<<sciAge<<endl;

    }

    if(s.getDescription().size() > 48)
    {
        int jumpLength = 53;
        int firstLine = 48;
        string less;
        less = s.getDescription().substr(0,firstLine);
        cout << "\tDescription: " << less << endl;
        for(unsigned int i = 0; i * jumpLength + firstLine < s.getDescription().size(); i++)
        {
            less = s.getDescription().substr(firstLine + i * jumpLength,jumpLength);
            cout << "\t\t" << less << endl;
        }
    }
    else if ((s.getDescription().size() > 1)&&(s.getDescription().size() < 48))
    {
        cout << "\tDescription: " << s.getDescription() << endl;
    }

    if (s.getLink().size() > 1)
    {
        cout << "\tLink: " << s.getLink() << endl;
    }
    vector<computer> v;
    v = serviceObject.servGetComputersLinkedToScientists(s.getID());
    if(v.size() > 0)
    {
        addEmptyLines(1);
        cout << "\tHe worked on the following computer/s:" << endl;
        printLines(1,"thin");
        for(unsigned i = 0; i < v.size(); i++)
        {
            cout << "\t" << v.at(i).getComName() << endl;
        }
        printLines(1,"thick");
    }
}
int infoDisplay::moreInfoOnScientist()
{
    unsigned int sel;
    if(serviceObject.servGetSciVector().size() > 0)
    {
        cout << "\tWould you like more info on any of the scientist?" << endl;
        commonPhrases("choice");

        sel = inputNumberToFunction();
    }
    return sel;

}
int infoDisplay::displaySortScientistOptions()
{
    int choice = 1;
    clearScreen();
    addEmptyLines(5);
    cout << "\tHow would you like the list to be sorted? \n";
    printLines(1, "thin");
    cout << "\t1) In alphabetical order \n";
    cout << "\t2) In reverse alphabetical order \n";
    cout << "\t3) By year of birth ascending \n";
    cout << "\t4) By year of birth descending \n";
    printLines(1, "thin");
    cout << "\tAll other digits for main menu \n";
    printLines(1, "thick");
    cout << "\tInput choice here: ";
    choice = inputNumberToFunction();

    if ((choice < 1)||(choice > 4))
    {
        commonPhrases("nothingsel");
    }
    else
    {

        serviceObject.servSortScientists(choice);
    }

    return choice;

}

/*
##  List of computers
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::displayOneComputer(computer& c)
{
    unsigned int jumpLength = 53;
    unsigned int firstLine = 48;
    clearScreen();
    addEmptyLines(5);
    printLines(1, "thin");
    cout << "\tName: " << c.getComName() << endl;
    cout << "\tType: ";
    cout << serviceObject.servGetCompTypeVector().at(c.getComType()-1).getName() << endl;
    cout << "\tProduction year: " <<  c.getComYear() << endl;

    if(c.getComDescription().size() > firstLine)
    {
        string less;
        less = c.getComDescription().substr(0,firstLine);
        cout << "\tDescription: " << less << endl;
        for(unsigned int i = 0; i * jumpLength + firstLine < c.getComDescription().size(); i++)
        {
            less = c.getComDescription().substr(firstLine + i * jumpLength,jumpLength);
            cout << "\t\t" << less << endl;
        }
    }
    else if ((c.getComDescription().size() > 1)&&(c.getComDescription().size() < 48))
    {
        cout << "\tDescription: " << c.getComDescription() << endl;
    }
    vector<scientist> v;
    v = serviceObject.servGetScientistsLinkedToComputer(c.getId());
    if(v.size() > 0)
    {
        addEmptyLines(1);
        cout << "\tThe following scientist/s worked on this computer:" << endl;
        printLines(1,"thin");
        for(unsigned i = 0; i < v.size(); i++)
        {
            cout << "\t" << v.at(i).getName() << endl;
        }
        printLines(1,"thick");
    }
}
void infoDisplay::displayComList()
{
    unsigned int cSize = serviceObject.servGetComVector().size();
    unsigned int scrollFactor;
    if (cSize > HOLYSCROLL)
    {
         scrollFactor = HOLYSCROLL;
    }
    else
    {
        scrollFactor = cSize;
    }
    unsigned int scrollBase = 0;
    bool continueF;

    do
    {
        listheaderCom();
        for(unsigned int i = scrollBase; i < scrollFactor; i++)
        {
            serviceObject.servReadSqlCompTypes();
            computer c = serviceObject.servGetComVector().at(i);
            unsigned int comtype = (serviceObject.servGetComVector().at(i).getComType()) - 1;
            cout.width(2);
            cout << "\t" << i+1 << ")\t";
            cout.width(30);
            cout << c.getComName();
            cout << "\t" << c.getComYear()<< "\t";
            if (comtype >= (serviceObject.servGetCompTypeVector().size()))
            {
                cout<<"\t\n";
            }
            else
            {
                cout<<serviceObject.servGetCompTypeVector().at(comtype).getName()<<endl;
            }

        }
        if (scrollNeeded("com") == true)
        {
            continueF = scrollFunction(cSize, scrollBase, scrollFactor);
        }
        else
        {
            continueF = false;
        }
    }
    while (continueF == true);

    printLines(1, "thin");
}
int infoDisplay::moreInfoOnComputer()
{
    unsigned int sel;
    if(serviceObject.servGetComVector().size() > 0)
    {
        cout << "\tWould you like more info on any of the computers?" << endl;
        commonPhrases("choice");
        sel = inputNumberToFunction();
    }
    return sel;

}
int infoDisplay::displaySortComputersOptions()
{
    int choice = 1;
    clearScreen();
    addEmptyLines(5);
    cout << "\tHow would you like the list to be sorted? \n";
    printLines(1, "thin");
    cout << "\t1) In alphabetical order \n";
    cout << "\t2) In reverse alphabetical order \n";
    cout << "\t3) By the building year \n";
    cout << "\t4) By type and name \n";
    printLines(1, "thin");
    cout << "\tAll other digits for main menu \n";
    printLines(1, "thick");
    cout << "\tInput choice here: ";
    choice = inputNumberToFunction();

    if ((choice < 1)||(choice > 4))
    {
        commonPhrases("nothingsel");
    }
    else
    {
        serviceObject.servSortComputers(choice);
    }

    return choice;

}

/*
##  List of computer types
##---------------------------------------------------------------------------------------##
*/
void infoDisplay::displayOneComputerType(computertype& ct)
{
    unsigned int jumpLength = 53;
    unsigned int firstLine = 48;
    clearScreen();
    addEmptyLines(5);
    printLines(1, "thin");
    cout << "\tName: " << ct.getName() << endl;

    if(ct.getDesc().size() > firstLine)
    {
        string less;
        less = ct.getDesc().substr(0,firstLine);
        cout << "\tDescription: " << less << endl;
        for(unsigned int i = 0; i * jumpLength + firstLine < ct.getDesc().size(); i++)
        {
            less = ct.getDesc().substr(firstLine + i * jumpLength,jumpLength);
            cout << "\t\t" << less << endl;
        }
    }
    else if ((ct.getDesc().size() > 1)&&(ct.getDesc().size() < 48))
    {
        cout << "\tDescription: " << ct.getDesc() << endl;
    }
    printLines(1,"thick");
}
int infoDisplay::moreInfoOnComputerTypes()
{
    unsigned int sel;
    if(serviceObject.servGetCompTypeVector().size() > 0)
    {
        cout << "\tWould you like more info on any of the computers types?" << endl;
        commonPhrases("choice");
        sel = inputNumberToFunction();
    }
    return sel;

}

/*
##  Miscellaneous
##---------------------------------------------------------------------------------------##
*/
bool infoDisplay::scrollNeeded(string comOrSci)
{
    bool returntype = false;

    if(comOrSci == "sci")
    {
        unsigned int cSize = serviceObject.servGetSciVector().size();
        if (cSize > HOLYSCROLL)
        {
            returntype = true;
        }
        else
        {
            returntype = false;
        }
    }
    else if(comOrSci == "com")
    {
        unsigned int vSize = serviceObject.servGetComVector().size();
        if (vSize > HOLYSCROLL)
        {
            returntype = true;
        }
        else
        {
            returntype = false;
        }
    }
    else if(comOrSci == "comtype")
    {
        unsigned int vSize = serviceObject.servGetCompTypeVector().size();
        if (vSize > HOLYSCROLL)
        {
            returntype = true;
        }
        else
        {
            returntype = false;
        }
    }

    return returntype;
}
bool infoDisplay::scrollFunction(unsigned int vSize, unsigned int &scrollBase, unsigned int &scrollFactor)
{

    bool scroll = false;
    char input;
    int scrollCount = 1;

        if (vSize > HOLYSCROLL)
        {
            if (scrollFactor >= vSize)
            {
                addEmptyLines(1);
                cout<<"\tAny character continues.";
            }
            else
            {
                addEmptyLines(1);
                cout<<"\tPress D to scroll down, any other character continues.";
            }

            input = inputCharacterToFunction();

            if (input == 'D')
            {
                scroll = true;

                ++scrollCount;

                scrollBase = scrollFactor;
                if (scrollBase >= vSize)
                {
                    scrollBase = vSize - HOLYSCROLL;
                }
                scrollFactor = scrollBase + HOLYSCROLL;
                if (scrollFactor >= vSize)
                {
                    scrollFactor = vSize;
                }
            }
            else
            {
                scroll = false;
            }

        }
    return scroll;
}
void infoDisplay::quitProgram()
{
    bool sel;
    cout << "\tAre you sure you want to quit?  (Y/N): ";
    sel = yesOrNo();
    if (sel == true)
    {
        cout << "\tThank you, please come again!" << endl;
        serviceObject.servCloseDatabase();  // To close the database before quitting.
        exit(0);
    }
    else
    {
        clearScreen();
    }

}
void infoDisplay::addEmptyLines(int numLines)
{
    do
    {
        cout << endl;
        numLines--;
    }while(numLines>0);
}
int infoDisplay::getCurrentDate (string date)
{

    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int day = aTime->tm_mday;
    int month = aTime->tm_mon + 1;
    int year = aTime->tm_year + 1900;

    if (date == "day")
    {
        return day;
    }
    else if (date == "year")
    {
        return year;
    }
    else if (date == "month")
    {
        return month;
    }
    else
    {
        return 0;
    }

}
int infoDisplay::inputNumberToFunction()
{
    string input;
    bool badInput = false;
    unsigned int temp;
    unsigned int digitCounter = 0;
    do
    {
        cin>>input;

        for (unsigned int i = 0; i < input.size(); i++)
        {
            if (isdigit(input[i]))
            {
                digitCounter++;
            }
        }

        stringstream stringToInt (input);
        stringToInt >> temp;
        if (digitCounter < input.size())
        {
            cout<<endl;
            cout<<"\tBad input, please try again: ";
            badInput = true;
        }
        else
        {
            badInput = false;
        }
    }
    while (badInput == true);

    return temp;
}
char infoDisplay::inputCharacterToFunction()
{
    char input;
    bool badInput = false;
    char returnInput;
    do
    {
        cin>>input;

        if (isdigit(input))
        {
            cout<<endl;
            cout<<"\tBad input, please try again: ";
            badInput = true;
        }
        else
        {
            badInput = false;
            returnInput = toupper(input);
        }
    }
    while(badInput == true);

    return returnInput;
}
void infoDisplay::inputCharOrNumToFunction (int &num, char &letter, bool &type)
{
    string input;

    bool badInput = false;

    do
    {
        int digitCounter = 0;
        int charCounter = 0;

        cin>>input;
        for (unsigned int i = 0; i < input.size(); i++)
        {
            if (isdigit(input.at(i)))
            {
                digitCounter++;
            }
            else
            {
                charCounter++;
            }
        }

        if ((digitCounter > 0)&&(charCounter == 0))
        {
            badInput = false;
            type = 0;
            stringstream stringToInt (input);
            stringToInt >> num;
        }
        if ((digitCounter == 0)&&(charCounter == 1))
        {
            badInput = false;
            type = 1;
            letter = input.at(0);
            letter = toupper(letter);
        }
        if ((digitCounter == 0)&&(charCounter > 1))
        {
            cout<<"\tToo many characters!"<<endl;
            badInput = true;
        }
        if ((digitCounter > 0)&&(charCounter > 0))
        {
            cout<<"\tInput number or one character";
            badInput = true;
        }
    }
    while (badInput == true);
}
bool infoDisplay::yesOrNo()
{
    bool repeatF = false;
    bool sendBack = false;

    do
    {
        repeatF = false;
        char input = inputCharacterToFunction();

        if (input == 'Y')
        {
            sendBack = true;
        }
        else if (input == 'N')
        {
            sendBack = false;
        }
        else
        {
            cout<<"\tBad input, please try again: " << endl;
            repeatF = true;
        }
    }
    while(repeatF == true);

    return sendBack;
}
void infoDisplay::printLines(int lines, string thickness)
{

    if (thickness == "thick")
    {
        for (int i = 0; i < lines; i++)
        {
            cout<<"\t============================================================="<<endl;
        }
    }
    else if (thickness == "thin")
    {
        for (int i = 0; i < lines; i++)
        {
            cout<<"\t-------------------------------------------------------------"<<endl;

        }
    }
    else
    {
        cout<<"\tError in printLines..."<<endl;
    }

}
void infoDisplay::commonPhrases(string phrase)
{
    if (phrase == "nothingsel")
    {
        cout<<"\tNothing selected..."<<endl;
        sleep(1);
    }
    else if (phrase == "choice")
    {
        cout << "\tPlease enter your choice, or 0 (zero) to go back: ";
    }
    else if (phrase == "nothingfound")
    {
        cout << "\tNothing found! - Do you want to try again? (Y/N): ";
    }
    else if (phrase == "continue")
    {
        cout<<"\tWould you like to continue? Y/N: ";
    }
    else if (phrase == "badname")
    {
        cout<<"\tIncorrect name format, please try again. "<<endl;
    }
    else if (phrase == "happy")
    {
        cout<<"\tAre you happy with this input ? Y/N:";
    }
    else if (phrase == "anycharacter")
    {
        cout << "\tEnter any character to continue ";
    }
    else if (phrase == "change")
    {
        cout<<"\tWhat would you like to change? Choose: "<<endl;
    }

    else
    {
        cout<<"ERROR IN COMMON PHRASES"<<endl;
    }
}
void infoDisplay::clearScreen()
{
    system("cls");
}







