#include "DataLayer/workingclass.h"
#include <unistd.h>

/*
##  Constructors
##---------------------------------------------------------------------------------------##
*/
workingclass::workingclass()
{

}

/*
##  Read functions
##---------------------------------------------------------------------------------------##
*/
void workingclass::readSqlScientists(string sorting)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM scientists "
                  "WHERE deleted = 'FALSE' "
                  "ORDER BY " + QString::fromStdString(sorting));
    query.exec();

    scientistVector.clear();
    while(query.next())
    {
        int id = query.value("id").toUInt();
        string nam = query.value("name").toString().toStdString();
        int gen = query.value("gender").toUInt();
        int yob = query.value("yob").toUInt();
        int yod = query.value("yod").toUInt();
        string desc = query.value("description").toString().toStdString();
        string url = query.value("link").toString().toStdString();

        scientist s(id,nam,gen,yob,yod,desc,url);
        scientistVector.push_back(s);
    }
}
void workingclass::readSqlComputers(string sorting)
{
    computer c;
    QSqlQuery query;

    query.prepare("SELECT * FROM computers "
                  "WHERE deleted = 'FALSE' "
                  "ORDER BY " + QString::fromStdString(sorting));
    query.exec();
    computerVector.clear();
    while(query.next())
    {
        computer c;
        c.setComID(query.value("id").toUInt());
        c.setComName(query.value("name").toString().toStdString());
        c.setComYear(query.value("year").toUInt());
        c.setComType(query.value("type").toUInt());
        c.setComBuilt(query.value("built").toUInt());
        c.setComDescription(query.value("description").toString().toStdString());
        computerVector.push_back(c);
        }
}
void workingclass::readSqlCompTypes()
{
    QSqlQuery query;

    query.prepare("SELECT * FROM computer_types "
                  "WHERE deleted = 'FALSE' "
                  "ORDER BY id ASC");
    query.exec();
    compTypeVector.clear();
    while(query.next())
    {
        computertype ct;
        int tid = query.value("id").toUInt();
        ct.setID(tid);
        ct.setName(query.value("name").toString().toStdString());
        ct.setDesc(query.value("description").toString().toStdString());
        compTypeVector.push_back(ct);
    }
}

void workingclass::readSqlRelations()
{
    QSqlQuery query;

//    query.prepare(" SELECT DISTINCT s.id as sid, s.name as sname, c.id as cid, c.name as cname "
//                  " FROM scientists AS s, computers AS c "
//                  " JOIN scientists_and_computers AS sc "
//                  " ON sc.scientist_id = s.id AND sc.computer_id = c.id "
//                  " WHERE sc.deleted = 'FALSE';");

    query.prepare(" SELECT DISTINCT s.id as sid, s.name as sname, c.id as cid, c.name as cname "
                  " FROM scientists AS s, computers AS c "
                  " JOIN scientists_and_computers AS sc "
                  " ON sc.scientist_id = s.id AND sc.computer_id = c.id "
                  " WHERE sc.deleted = 'FALSE'AND "
                  " s.deleted = 'FALSE' AND c.deleted = 'FALSE' ;");

    query.exec();
    relationVector.clear();
    while(query.next())
    {
        relation r;
        r.scientistID = query.value("sid").toUInt();
        r.computerID = query.value("cid").toUInt();
        r.scientistName = query.value("sname").toString().toStdString();
        r.computerName = query.value("cname").toString().toStdString();
        relationVector.push_back(r);
    }
}


/*
##  Add functions
##---------------------------------------------------------------------------------------##
*/
bool workingclass::addscientist(scientist& s)
{
    //QDebug << "adding scientist in workingclass";



    QSqlQuery query;

    query.prepare("INSERT INTO scientists (name, gender, yob, yod, description, link) "
                  "VALUES (:name, :sex, :yob, :yod, :desc, :link); ");

    query.bindValue(":name", QString::fromStdString(s.getName()));
    query.bindValue(":sex", s.getGender());
    query.bindValue(":yob", s.getYearOfBirth());
    query.bindValue(":yod", s.getYearOfDeath());
    query.bindValue(":desc", QString::fromStdString(s.getDescription()));
    query.bindValue(":link", QString::fromStdString(s.getLink()));
    query.exec();
    s.setID(query.lastInsertId().toUInt());
    return 1;
}
bool workingclass::addcomputer(computer& c)
{
    QSqlQuery query;
    query.prepare("INSERT INTO computers (name, year, type, built, description) "
                  "VALUES (:name, :year, :type, :built, :desc);");
    query.bindValue(":name", QString::fromStdString(c.getComName()));
    query.bindValue(":year", c.getComYear());
    query.bindValue(":type", c.getComType());
    query.bindValue(":built", c.getComBuilt());
    query.bindValue(":desc", QString::fromStdString(c.getComDescription()));
    query.exec();
    if(!query.lastError().isValid())
    {
        c.setComID(query.lastInsertId().toUInt());
        return true;
    }
    return false;
}
bool workingclass::addcomputerType(computertype & ct)
{
    QSqlQuery query;
    query.prepare("INSERT INTO computer_types (name, description) "
                  "VALUES (:name, :desc);");
    query.bindValue(":name", QString::fromStdString(ct.getName()));
    query.bindValue(":desc", QString::fromStdString(ct.getDesc()));
    query.exec();
    if(!query.lastError().isValid())
    {
        return true;
    }
    return false;
}
bool workingclass::addRelationSciComp(int sciID, int compID)
{
    QSqlQuery query;
    query.prepare(" INSERT INTO scientists_and_computers "
                  " (scientist_id, computer_id) "
                  " VALUES (:sID, :cID); ");
    query.bindValue(":sID", sciID);
    query.bindValue(":cID", compID);
    query.exec();
    if(!query.lastError().isValid())
    {
        return true;
    }
    return false;
}

/*
##  Update functions
##---------------------------------------------------------------------------------------##
*/
bool workingclass::updateSqlComputer(computer& c)
{
    QSqlQuery query;

    query.prepare("UPDATE computers "
                  "SET name = :name, year = :year, type = :type, built = :built, "
                  "description = :desc "
                  "WHERE id = :id; ");
    query.bindValue(":id", c.getId());
    query.bindValue(":name", QString::fromStdString(c.getComName()));
    query.bindValue(":year", c.getComYear());
    query.bindValue(":type", c.getComType());
    query.bindValue(":built", c.getComBuilt());
    query.bindValue(":desc", QString::fromStdString(c.getComDescription()));
    query.exec();
    if(!query.lastError().isValid())
    {
        return true;
    }
    return false;

}
void workingclass::updateSqlScientist(scientist& s)
{
    QSqlQuery query;

    query.prepare("UPDATE scientists "
                  "SET name = :name, gender = :gender, yob = :yob, yod = :yod,"
                  "description = :desc, link = :link " "WHERE id = :id; ");
    query.bindValue(":id", s.getID());
    query.bindValue(":name", QString::fromStdString(s.getName()));
    query.bindValue(":gender", s.getGender());
    query.bindValue(":yob", s.getYearOfBirth());
    query.bindValue(":yod", s.getYearOfDeath());
    query.bindValue(":desc", QString::fromStdString(s.getDescription()));
    query.bindValue(":link", QString::fromStdString(s.getLink()));
    query.exec();
}
bool workingclass::updateSqlComputerType(computertype& ct)
{
    QSqlQuery query;
    query.prepare(" UPDATE computer_types "
                  " SET name = :ctName, "
                  " description = :ctDesc "
                  " WHERE id = :ctId; ");
    query.bindValue(":ctId", ct.getid());
    query.bindValue(":ctName", QString::fromStdString(ct.getName()));
    query.bindValue(":ctDesc", QString::fromStdString(ct.getDesc()));
    query.exec();
    if(!query.lastError().isValid())
    {
        return true;
    }
    return false;

}

/*
##  Delete functions
##---------------------------------------------------------------------------------------##
*/
void workingclass::deleteScientist(int sciID)
{
    qDebug() << sciID;
    QSqlQuery query;

    query.prepare("UPDATE scientists "
                  "SET deleted = 'TRUE' "
                  "WHERE id = :id;");
    query.bindValue(":id", sciID);
    query.exec();
}
bool workingclass::deleteComputer(int compID)
{
    QSqlQuery query;

    query.prepare("UPDATE computers "
                  "SET deleted = 'TRUE' "
                  "WHERE id = :id; ");
    query.bindValue(":id", compID);
    query.exec();
    if(!query.lastError().isValid())
    {
        return true;
    }
    return false;
}
bool workingclass::deleteComputerType(int computertypeID)
{
    QSqlQuery query;

    query.prepare("UPDATE computer_types "
                  "SET deleted = 'TRUE' "
                  "WHERE id = :id;");
    query.bindValue(":id", computertypeID);
    query.exec();
    if(!query.lastError().isValid())
    {
        return true;
    }
    return false;
}
bool workingclass::deleteRelationSciComp(int sciID, int compID)
{
    QSqlQuery query;
    query.prepare(" UPDATE scientists_and_computers SET deleted = 'TRUE' "
                  " WHERE scientist_id = :sid AND computer_id = :cid ");
    query.bindValue(":sid", sciID);
    query.bindValue(":cid", compID);
    query.exec();
    if(!query.lastError().isValid())
    {
        return true;
    }
    return false;
}

/*
##  Get vector functions
##---------------------------------------------------------------------------------------##
*/
vector<scientist> workingclass::getSciVector()
{
    return scientistVector;
}
vector<computer> workingclass::getComVector()
{
    return computerVector;
}
vector<computertype> workingclass::getCompTypeVector()
{
    return compTypeVector;
}
vector<computer> workingclass::getComputersLinkedToScientists(int sciID)
{
    QSqlQuery query;

    query.prepare("SELECT c.* FROM computers c "
                  "INNER JOIN scientists_and_computers sc "
                  "ON  c.id = sc.computer_id "
                  "WHERE sc.scientist_id = :sid AND "
                  "sc.deleted ='FALSE';");
    query.bindValue(":sid", sciID );
    query.exec();

    vector<computer> tempvector;
    while(query.next())
    {
        computer c;
        c.setComID(query.value("id").toUInt());
        c.setComName(query.value("name").toString().toStdString());
        c.setComYear(query.value("year").toUInt());
        c.setComType(query.value("type").toUInt());
        c.setComBuilt(query.value("built").toUInt());
        c.setComDescription(query.value("description").toString().toStdString());
        tempvector.push_back(c);
    }

    return tempvector;
}
vector<scientist> workingclass::getScientistsLinkedToComputer(int compID)
{
    QSqlQuery query;

    query.prepare("SELECT s.* FROM scientists s "
                  "INNER JOIN scientists_and_computers sc "
                  "ON  s.id = sc.scientist_id "
                  "WHERE sc.computer_id = :cid AND "
                  "sc.deleted = 'FALSE';");
    query.bindValue(":cid", compID );
    query.exec();

    vector<scientist> tempvector;
    while(query.next())
    {
        scientist s;
        s.setID(query.value("id").toUInt());
        s.setName(query.value("name").toString().toStdString());
        s.setGender(query.value("gender").toUInt());
        s.setYearOfBirth(query.value("yob").toUInt());
        s.setYearOfDeath(query.value("yod").toUInt());
        s.setDescription(query.value("description").toString().toStdString());
        s.setLink(query.value("link").toString().toStdString());
        tempvector.push_back(s);
    }

    return tempvector;
}

vector<relation> workingclass::getRelationshipVector()
{
    return relationVector;
}




/*
##  Erase vector functions
##---------------------------------------------------------------------------------------##
*/
void workingclass::eraseScientistVector()
{
    scientistVector.clear();
}
void workingclass::eraseComputerVector()
{
    computerVector.clear();
}
void workingclass::eraseCompTypeVector()
{
    compTypeVector.clear();
}

/*
##  Search scientist functions
##---------------------------------------------------------------------------------------##
*/
void workingclass::searchScientistByName(string subName, bool& isFound)
{
    vector<scientist> returnVector;
    //scientist s;
	QSqlQuery query;
    stringstream ss;
    isFound = false;
    
	ss << "SELECT * FROM scientists as s WHERE s.name LIKE '%" 
	   << subName << "%' AND deleted = 'FALSE'";
    qDebug() << QString::fromStdString(ss.str());

    query.exec(QString::fromStdString(ss.str()));

    while(query.next())
    {
        int id = query.value("id").toUInt();
        string nam = query.value("name").toString().toStdString();
        int gen = query.value("gender").toUInt();
        int yob = query.value("yob").toUInt();
        int yod = query.value("yod").toUInt();
        string desc = query.value("description").toString().toStdString();
        string url = query.value("link").toString().toStdString();

        scientist s(id,nam,gen,yob,yod,desc,url);
        returnVector.push_back(s);
        isFound = true;
    }
    if( returnVector.size() > 0)
    {
        scientistVector = returnVector;
    }
	else
    {
        readSqlScientists();
    }
}
void workingclass::searchScientistByGender(int sex, bool& isFound)
{
    vector<scientist> returnVector;
    scientist s;
	stringstream ss;
    QSqlQuery query;
	
    isFound = false;
    ss << "SELECT * FROM scientists as s WHERE s.gender = " <<  sex << " AND deleted = 'FALSE'";
    query.exec(QString::fromStdString(ss.str()));
	scientistVector.clear();
	
	while(query.next())
    {
        int id = query.value("id").toUInt();
        string nam = query.value("name").toString().toStdString();
        int gen = query.value("gender").toUInt();
        int yob = query.value("yob").toUInt();
        int yod = query.value("yod").toUInt();
        string desc = query.value("description").toString().toStdString();
        string url = query.value("link").toString().toStdString();

        scientist s(id,nam,gen,yob,yod,desc,url);
        returnVector.push_back(s);
        isFound = true;
    }
    if(isFound)
    {
        scientistVector = returnVector;
    }
	else
    {
        readSqlScientists();
    }
}

// {
    // vector<scientist> returnVector;
    // scientist s;

    // for(unsigned int i = 0; i < scientistVector.size(); i++)
    // {
        // if(scientistVector.at(i).getGender() == sex)
       // {
            // s = scientistVector.at(i);
            // returnVector.push_back(s);
            // isFound = true;
       // }
    // }
    // scientistVector.clear();
    // scientistVector = returnVector;
// }

void workingclass::searchScientistByYear(int& yr, char bORd, bool& isFound)
{

    vector<scientist> returnVector;
    scientist s;
    string col;
    QSqlQuery query;
    stringstream ss;
	
	if(bORd == 'b')
	{
         col = "yob";
	}
	else if(bORd == 'd')
	{
         col = "yod";
	}
	else
	{
        isFound = false;
		return;
	}
	

    ss << "SELECT * FROM scientists as s WHERE s." <<  col
	   <<" LIKE '%"  << yr << "%' AND deleted = 'FALSE'";

    query.exec(QString::fromStdString(ss.str()));
	scientistVector.clear();
	
	while(query.next())
    {
        int id = query.value("id").toUInt();
        string nam = query.value("name").toString().toStdString();
        int gen = query.value("gender").toUInt();
        int yob = query.value("yob").toUInt();
        int yod = query.value("yod").toUInt();
        string desc = query.value("description").toString().toStdString();
        string url = query.value("link").toString().toStdString();

        scientist s(id,nam,gen,yob,yod,desc,url);
        returnVector.push_back(s);
        isFound = true;
    }
    if( returnVector.size() > 0)
    {
        scientistVector = returnVector;
    }
	else
    {
        readSqlScientists();
    }
}

/*
##  Search computer functions
##---------------------------------------------------------------------------------------##
*/
void workingclass::searchComputerByName(string subName, bool& isFound)
{
    computer c;
    vector<computer> returnVector;
    stringstream ss;
    ss << "SELECT * FROM computers as c WHERE c.name LIKE '%" << subName << "%' AND deleted = 'FALSE'";

    string s = ss.str() ;

    QSqlQuery query;

    query.exec(QString::fromStdString(ss.str()));
    while(query.next())
    {
        computer c;
        c.setComID(query.value("id").toUInt());
        c.setComName(query.value("name").toString().toStdString());
        c.setComYear(query.value("year").toUInt());
        c.setComType(query.value("type").toUInt());
        c.setComBuilt(query.value("built").toUInt());
        c.setComDescription(query.value("description").toString().toStdString());
        returnVector.push_back(c);
        isFound = true;
    }
    if( returnVector.size() > 0)
    {
        computerVector.clear();
        computerVector = returnVector;
    }
}
void workingclass::searchComputerByType(string& type, bool& isFound)
{

    vector<computer> returnVector;
    computer c;
    QSqlQuery query;
    stringstream ss;

    ss << "SELECT ct.id FROM computer_types as ct WHERE ct.name LIKE '%" << type << "%' AND deleted = 'FALSE'";
    query.exec(QString::fromStdString(ss.str()));

    readSqlComputers();
    while(query.next())  // Hleyp í gegnum comptype sem fundust.
    {
        for(unsigned int item = 0; item < computerVector.size(); item++)
        {
            if(computerVector.at(item).getComType() == query.value("id").toUInt())
            {
                c = computerVector.at(item);
                returnVector.push_back(c);
                isFound    = true;
            }
        }
    }
    if( returnVector.size() > 0)
    {
        computerVector.clear();
        computerVector = returnVector;
    }
}
void workingclass::searchComputerByYear(int& yr, bool& isFound)
{
    vector<computer> returnVector;
    QSqlQuery query;
    stringstream ss;

    ss << "SELECT * FROM computers as c WHERE c.year LIKE '%" << yr << "%' AND deleted = 'FALSE'";
    query.exec(QString::fromStdString(ss.str()));
    computerVector.clear();
    while(query.next())
    {
        int i = 1;
        computer c;
        c.setComID(query.value("id").toUInt());
        c.setComName(query.value("name").toString().toStdString());
        c.setComYear(query.value("year").toUInt());
        c.setComType(query.value("type").toUInt());
        c.setComBuilt(query.value("built").toUInt());
        c.setComDescription(query.value("description").toString().toStdString());
        returnVector.push_back(c);

        isFound = true;
        qDebug() << i << " " << QString::fromStdString(c.getComName());
        i++;

    }
    if( returnVector.size() > 0)
    {
        //computerVector.clear();
        computerVector = returnVector;
    }
    else
    {
        readSqlComputers();
    }
}

void workingclass::searchRelations(int column, string searchstr, bool& isFound)
{
    QSqlQuery query;
    vector<relation> returnVector;
    string col;
    if(column == 0)
    {
        col = "s.name";
    }
    else
    {
        col = "c.name";
    }
    stringstream ss;
    ss << " SELECT DISTINCT s.id as sid, s.name as sname, c.id as cid, c.name as cname "
       << " FROM scientists AS s, computers AS c JOIN scientists_and_computers AS sc "
       << " ON sc.scientist_id = s.id AND sc.computer_id = c.id "
       << " WHERE " << col << " LIKE '%" << searchstr << "%' AND sc.deleted = 'FALSE';";

    qDebug() << QString::fromStdString(ss.str());
    query.exec(QString::fromStdString(ss.str()));
    returnVector.clear();
    while(query.next())
    {
        relation r;
        r.scientistID = query.value("sid").toUInt();
        r.computerID = query.value("cid").toUInt();
        r.scientistName = query.value("sname").toString().toStdString();
        r.computerName = query.value("cname").toString().toStdString();
        returnVector.push_back(r);
        qDebug() << r.scientistID << " - "<< r.computerID;
        isFound = true;
    }
    qDebug() << returnVector.size();
    if( returnVector.size() > 0)
    {
        relationVector = returnVector;
    }
    else
    {
        readSqlRelations();
        isFound = false;
    }
}

void workingclass::searchComputerTypes(int column, string searchstr, bool& isFound)
{
    QSqlQuery query;
    vector<computertype> returnVector;
    string col;

    if(column == 0)
    {
        col = "name";
    }
    else
    {
        col = "description";
    }

    stringstream ss;
    ss << " SELECT DISTINCT * "
       << " FROM computer_types AS ct "
       << " WHERE " << col << " LIKE '%" << searchstr << "%' AND ct.deleted = 'FALSE';";

    query.exec(QString::fromStdString(ss.str()));
    returnVector.clear();
    while(query.next())
    {
        computertype ct;
        int tid = query.value("id").toUInt();
        ct.setID(tid);
        ct.setName(query.value("name").toString().toStdString());
        ct.setDesc(query.value("description").toString().toStdString());
        returnVector.push_back(ct);
        isFound = true;
    }
    qDebug() << returnVector.size();
    if( returnVector.size() > 0)
    {
        compTypeVector= returnVector;
    }
    else
    {
        readSqlCompTypes();
        isFound = false;
    }
}

/*
##  Database functions
##---------------------------------------------------------------------------------------##
*/
QSqlDatabase workingclass::startDatabase()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = QString::fromStdString(DBASE);
    db.setDatabaseName(dbName);
    db.open();
    return db;
}
bool workingclass::checkDatabaseExists()
{
    QFile db;
    return db.exists(QString::fromStdString(DBASE)) ;
}
void workingclass::closeDatabase()
{
    QSqlDatabase db;
    db.close();
}
void workingclass::createEmptyDatabase()
{
    startDatabase();
    createTableComputerTypes();
    createTableScientists();
    createTableComputers();
    createTableScientistsAndComputers();
}

/*
##  Private functions
##---------------------------------------------------------------------------------------##
*/
void workingclass::createTableScientistsAndComputers()
{
    QSqlQuery query;
    query.exec(" CREATE TABLE scientists_and_computers "
               " (scientist_id INTEGER NOT NULL, "
               " computer_id INTEGER NOT NULL, "
               " deleted BOOLEAN DEFAULT 'FALSE', "
               " FOREIGN KEY (scientist_id) REFERENCES scientists(id), "
               " FOREIGN KEY (computer_id) REFERENCES computers(id) "
               " PRIMARY KEY (scientist_id,computer_id));");
}
void workingclass::createTableComputers()
{
    QSqlQuery query;
    query.exec("CREATE TABLE computers "
               "(id INTEGER PRIMARY KEY  AUTOINCREMENT NOT NULL UNIQUE, "
               " name TEXT NOT NULL, "
               " year INTEGER, "
               " type INTEGER NOT NULL, "
               " built BOOL NOT NULL DEFAULT 'FALSE', "
               " description TEXT, "
               " deleted DEFAULT 'FALSE',"
               " FOREIGN KEY(type) REFERENCES computer_types(id));");
}
void workingclass::createTableScientists()
{
    QSqlQuery query;
    query.exec("CREATE TABLE scientists "
               "(id INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE, "
               " name TEXT NOT NULL, "
               " gender INTEGER NOT NULL  DEFAULT 2, "
               " yob INTEGER NOT NULL, "
               " yod INTEGER, "
               " description TEXT, "
               " link TEXT, "
               " deleted DEFAULT 'FALSE');");
}
void workingclass::createTableComputerTypes()
{
    QSqlQuery query;
    query.exec("CREATE TABLE computer_types "
               "(id INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE, "
               " name TEXT NOT NULL, "
               " description TEXT, "
               " deleted DEFAULT 'FALSE');");
}

