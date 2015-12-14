#include "services/service.h"
#include <QDebug>

using namespace std;

/*
##  Constructors
##---------------------------------------------------------------------------------------##
*/
service::service()
{

}

/*
##  Correction functions
##---------------------------------------------------------------------------------------##
*/
string service::nameCorrection(string name, bool& badName)
{
    int spaceCount = 0;
    vector<int> spacePositions;
    badName = false;

    for (unsigned int i = 0; i < name.length(); i++)
    {
        name[i] = (tolower(name[i]));



        if ((i < MAXNAMELENGTH) && (i > 1))
        {
           spaceCount = (name.find(" ", i));
        }

        if (find(spacePositions.begin(), spacePositions.end(), spaceCount) ==
                spacePositions.end())
        {
            if (spaceCount != 0)
            {
                spacePositions.push_back(spaceCount);
            }
        }

        if (string::npos != name.find_first_of("0123456789"))
        {
            badName = true;
        }
        else
        {
            badName = false;
        }
    }

    for (unsigned int i = 0; i < spacePositions.size(); i++)
    {
        int spacePos = spacePositions.at(i) + 1;
        name[spacePos] = toupper(name[spacePos]);
    }

    if (name.size() > MAXNAMELENGTH)
    {
        badName = true;
        cout<<"\tName is too long! "<<endl;
    }

    return name;
}
int service::genderCorrection(string gender)
{

    for(unsigned int i = 0; i < gender.length(); ++i)
    {
        gender[i] = tolower(gender[i]);
    }

    string male[15] = {"m","karlmadur", "karlkyns", "karl", "kk", "male", "man", "guy", "bro",
                      "kall", "gaur", "dude", "sjomli", "strakur", "piltur"};

    vector<string> maleVector (male, male + sizeof(male) / sizeof(male[0]));

    string female[14] = {"f", "kona", "kvenmadur", "kvenkyns", "kvk", "stelpa", "female", "stulka",
                        "kerling", "kelling", "lady", "woman", "girl", "gal"};

    vector<string> femaleVector (female, female + sizeof(female) / sizeof(female[0]));

    bool isMale = find(maleVector.begin(), maleVector.end(), gender) != maleVector.end();
    bool isFemale = find(femaleVector.begin(), femaleVector.end(), gender) != femaleVector.end();

    if (isMale == true)
    {
        return 1;
    }

    else if (isFemale == true)
    {
        return 0;
    }
    else
    {
        return 2;
    }
}

int service::inputNumberToFunction(string input)
{
    unsigned int temp;
    unsigned int digitCounter = 0;

    for (unsigned int i = 0; i < input.size(); i++)
    {
        if (isdigit(input[i]))
        {
            digitCounter++;
        }
    }

    stringstream stringToInt (input);
    stringToInt >> temp;

    return temp;
}

void service::errorMessage(string errorMessage)
{
    QString qstr = QString::fromStdString(errorMessage);
    QMessageBox msgBox;
    msgBox.setWindowTitle("Warning");
    msgBox.setText(qstr);
//    msgBox.setStandardButtons(QMessageBox::Yes);
//    msgBox.addButton(QMessageBox::No);
//    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.exec();
}

void service::completeMessage(string completeMessage)
{
    QString qstr = QString::fromStdString(completeMessage);
     QMessageBox msgBox;
     msgBox.setWindowTitle("Success");
     msgBox.setText(qstr);
 //    msgBox.setStandardButtons(QMessageBox::Yes);
 //    msgBox.addButton(QMessageBox::No);
 //    msgBox.setDefaultButton(QMessageBox::No);
     msgBox.exec();

}
int service::yearCorrection(int year, bool &errorInYear)
{

    int tempYear = year;

    if ((tempYear >= 20) && (tempYear < 100))
    {
        tempYear += 1900;
    }
    else if ((tempYear >= 1) && (tempYear < 20))
    {
        tempYear += 2000;
    }

    if ((tempYear > 1) && (tempYear <= CURRENTYEAR))
    {
        errorInYear = false;
    }
    else
    {
        errorInYear = true;
    }

    return tempYear;
}

/*
##  Read functions
##---------------------------------------------------------------------------------------##
*/
void service::servReadSqlScientists(string sorting)
{
    workingObject.readSqlScientists(sorting);
}
void service::servReadSqlComputers(string sorting)
{
    workingObject.readSqlComputers(sorting);
}
void service::servReadSqlCompTypes()
{
    workingObject.readSqlCompTypes();
}

void service::servReadSqlRelations()
{
    workingObject.readSqlRelations();
}

/*
##  Add functions
##---------------------------------------------------------------------------------------##
*/
void service::servAddscientist(scientist& s)
{
    workingObject.addscientist(s);
}
void service::servAddcomputer(computer& c)
{
    workingObject.addcomputer(c);
}
void service::servAddcomputerType(computertype& ct)
{
    workingObject.addcomputerType(ct);
}
bool service::servAddRelationSciComp(int sciID, int compID)
{
    return workingObject.addRelationSciComp(sciID, compID);
}

/*
##  Update functions
##---------------------------------------------------------------------------------------##
*/
void service::servUpdateSqlScientist(scientist& s)
{
    workingObject.updateSqlScientist(s);
}
bool service::servUpdateSqlComputer(computer& c)
{
    return workingObject.updateSqlComputer(c);
}
bool service::servUpdateSqlComputerType(computertype& ct)
{
    return workingObject.updateSqlComputerType(ct);
}

/*
##  Delete functions
##---------------------------------------------------------------------------------------##
*/
void service::servDeleteScientist(int sciID)
{
    workingObject.deleteScientist(sciID);
}
bool service::servDeleteComputer(int compID)
{
    return workingObject.deleteComputer(compID);
}
bool service::servDeleteComputerType(int computertypeID)
{
    return workingObject.deleteComputerType(computertypeID);
}
bool service::servDeleteRelationSciComp(int sciID, int compID)
{
    return workingObject.deleteRelationSciComp(sciID, compID);
}

/*
##  Get vector functions
##---------------------------------------------------------------------------------------##
*/
vector<scientist> service::servGetSciVector()
{
    return workingObject.getSciVector();
    qDebug () << "getting vector..";
}
vector<computer> service::servGetComVector()
{
    return workingObject.getComVector();
}
vector<computertype> service::servGetCompTypeVector()
{
    return workingObject.getCompTypeVector();
}

vector<relation> service::servGetRelationshipVector()
{
    return workingObject.getRelationshipVector();
}
vector<scientist> service::servGetScientistsLinkedToComputer(int compID)
{
    return workingObject.getScientistsLinkedToComputer(compID);
}
vector<computer> service::servGetComputersLinkedToScientists(int sciID)
{
    return workingObject.getComputersLinkedToScientists(sciID);
}

/*
##  Erase vector functions
##---------------------------------------------------------------------------------------##
*/
void service::servEraseScientistVector()
{
    workingObject.eraseScientistVector();
}
void service::servEraseComputerVector()
{
    workingObject.eraseComputerVector();
}
void service::servEraseCompTypeVector()
{
    workingObject.eraseCompTypeVector();
}

/*
##  Sort functions
##---------------------------------------------------------------------------------------##
*/
void service::servSortScientists(int choice)
{
    switch(choice)
    {
        case 1:
            workingObject.readSqlScientists("name ASC;");
            break;
        case 2:
            workingObject.readSqlScientists("name DESC;");
            break;
        case 3:
            workingObject.readSqlScientists("yob ASC;");
            break;
        case 4:
            workingObject.readSqlScientists("yob DESC;");
            break;
        default:
            break;
      }
}
void service::servSortComputers(int choice)
{
      switch(choice)
      {
            case 1:
                workingObject.readSqlComputers("name;");
                break;
            case 2:
                workingObject.readSqlComputers("name DESC;");
                break;
            case 3:
                workingObject.readSqlComputers("year;");
                break;
            case 4:
                workingObject.readSqlComputers("type, name;");
                break;
            default:
                break;
          cout<<"test4 "<<endl;

      }
}

/*
##  Search scientists functions
##---------------------------------------------------------------------------------------##
*/
void service::servSearchScientistByName(string subName, bool& isFound)
{
    workingObject.searchScientistByName(subName, isFound);
}
void service::servSearchScientistByGender(int sex, bool& isFound)
{
    workingObject.searchScientistByGender(sex, isFound);
}
void service::servSearchScientistByYear(int& yr, char bORd, bool& isFound)
{
    yr = yearCorrection(yr,isFound);
    workingObject.searchScientistByYear(yr, bORd, isFound);
}

/*
##  Search computers functions
##---------------------------------------------------------------------------------------##
*/
void service::servSearchComputerByName(string subName, bool& isFound)
{
    workingObject.searchComputerByName(subName, isFound);
}
void service::servSearchComputerByType(string& type, bool& isFound)
{
    workingObject.searchComputerByType(type, isFound);
}
void service::servSearchComputerByYear(int& yr, bool& isFound)
{
    yr = yearCorrection(yr,isFound);
    workingObject.searchComputerByYear(yr, isFound);
}

void service::servSearchRelations(int column, string searchstr, bool& isFound)
{
    workingObject.searchRelations(column, searchstr, isFound);
}

void service::servSearchComputerTypes(int column, string searchstr, bool& isFound)
{
    workingObject.searchComputerTypes(column, searchstr, isFound);
}

/*
##  Database functions
##---------------------------------------------------------------------------------------##
*/
void service::servStartDatabase()
{
    workingObject.startDatabase();
}
bool service::servCheckDatabaseExists()
{
    return workingObject.checkDatabaseExists();
}
void service::servCreateEmptyDatabase()
{
    workingObject.createEmptyDatabase();
}
void service::servCloseDatabase()
{
    workingObject.closeDatabase();
}






