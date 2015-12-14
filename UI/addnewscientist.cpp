#include "addnewscientist.h"
#include "ui_addnewscientist.h"
//#include "DataLayer/workingclass.h"
//#include "Services/scientistserviceclass.h"
//#include <QDateEdit>
//#include <sstream>
//#include <QDebug>

using namespace std;

addNewScientist::addNewScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNewScientist)
{
    ui->setupUi(this);
    ui->buttonBox_editScientist->setHidden(true);
    ui->labelSciid->setHidden(true);
    ui->labelCurrentAge->setHidden(true);
    ui->lineEdit_currentAge->setHidden(true);
    ui->labelAgeAtDeath->setHidden(true);
    ui->lineEdit_AgeAtDeath->setHidden(true);
    ui->labelRelations->setHidden(true);
    ui->textBrowser_relations->setHidden(true);
    ui->labelClickableLink->setHidden(true);
    ui->labelClickableUrlReal->setHidden(true);


}

addNewScientist::~addNewScientist()
{
    delete ui;
}

void addNewScientist::on_buttonBox_accepted()
{
    scientist sc;
    sc.setName(ui->lineEdit_name->text().toStdString());
    sc.setDescription(ui->textEdit_descr->toPlainText().toStdString());
    sc.setLink(ui->lineEdit_link->text().toStdString());
    sc.setYearOfBirth(ui->lineEdit_yob->text().toInt());
    sc.setYearOfDeath(ui->lineEdit_yod->text().toInt());
    sc.setGender(ui->comboBox_gender->currentIndex());
    serviceobject.servAddscientist(sc);
    serviceobject.servReadSqlScientists();
}

void addNewScientist::addScientistToDatabase(scientist &sc)
{

    serviceobject.servAddscientist(sc);
}

void addNewScientist::addScientistErrorCorrection(scientist &sc)
{
    bool badName = false;
    bool errorInYOB = false;
    bool errorInYOD = false;
    sc.setName(serviceobject.nameCorrection(sc.getName(), badName));
    sc.setYearOfBirth(serviceobject.yearCorrection(sc.getYearOfBirth(), errorInYOB));
    sc.setYearOfDeath(serviceobject.yearCorrection(sc.getYearOfDeath(), errorInYOD));

    if (badName||errorInYOB||errorInYOD)
    {
        qDebug () << "ERROR IN NAME!" ;

        if (badName)
        {
            serviceobject.errorMessage("Name not correctly formatted. Please enter letters only.");
        }
        if (errorInYOB||errorInYOD)
        {
            serviceobject.errorMessage("Year not correctly formatted. Please enter valid years only.");
        }
    }
    else
    {
        addScientistToDatabase(sc);
        qDebug () << "NAME ADDED TO DATABASE!" ;
        serviceobject.completeMessage("Name was successfully added to the Database!");
        //FÆRA ÚR SERVICE CLASS.
    }
}

void addNewScientist::neweditscientist(QString id, bool edit)
{
    int n = id.toInt(0,10);
    serviceobject.servReadSqlScientists("NAME");
    serviceobject.servReadSqlComputers("NAME");
    serviceobject.servReadSqlCompTypes();

    int currentID = 0;

    //name  gender  year of birth  year of death  description  link
    QString name, descr, link, sciid, yob, yod;
    int gender;
    for (unsigned int i = 0; i  < serviceobject.servGetSciVector().size(); i++)
    {
        if(serviceobject.servGetSciVector().at(i).getID() == n)
        {
            name = QString::fromStdString(serviceobject.servGetSciVector().at(i).getName());
            descr = QString::fromStdString(serviceobject.servGetSciVector().at(i).getDescription());
            link = QString::fromStdString(serviceobject.servGetSciVector().at(i).getLink());
            sciid =  QString::number(serviceobject.servGetSciVector().at(i).getID());
            gender = serviceobject.servGetSciVector().at(i).getGender();
            yob = QString::number(serviceobject.servGetSciVector().at(i).getYearOfBirth());
            yod = QString::number(serviceobject.servGetSciVector().at(i).getYearOfDeath());
            currentID = serviceobject.servGetSciVector().at(i).getID();
            qDebug () << name;
        }
    }
    ui->lineEdit_name->setText(name);
    ui->lineEdit_link->setText(link);
    ui->lineEdit_yob->setText(yob);
    ui->lineEdit_yod->setText(yod);
    ui->comboBox_gender->setCurrentIndex(gender);
    ui->textEdit_descr->setText(descr);
    ui->labelSciid->setText(sciid);
    this->setWindowTitle("Edit Computer Scientist in the Database");
    ui->buttonBox->setHidden(true);
    ui->buttonBox_editScientist->setHidden(false);

    bool dead = true;
    if (yod.toInt() == 0)
    {
        dead = false;
    }

    if (edit == false)
    {
        this->setWindowTitle("More information about the Scientist");
        ui->buttonBox_editScientist->setHidden(true);

        ui->labelEntName->setText("Name: ");
        ui->lineEdit_name->setReadOnly(true);
        ui->labelEntBirth->setText("Year of Birth: ");
        ui->lineEdit_yob->setReadOnly(true);

        if (dead)
        {
            int ageAtDeath = yod.toInt() - yob.toInt();

            ui->lineEdit_AgeAtDeath->setHidden(false);
            ui->lineEdit_AgeAtDeath->setText(QString::number(ageAtDeath));
            ui->lineEdit_AgeAtDeath->setReadOnly(true);
            ui->labelAgeAtDeath->setHidden(false);
            ui->lineEdit_yod->setReadOnly(true);

        }
        else
        {
            QDate date;
            date.currentDate();
            int currentYear = 2015;
            int currentAge = currentYear - yob.toInt();

            ui->labelEntDeath->setText("Year of Death: ");
            ui->lineEdit_yod->setReadOnly(true);
            ui->lineEdit_currentAge->setHidden(false);
            ui->lineEdit_currentAge->setText(QString::number(currentAge));
            ui->lineEdit_currentAge->setReadOnly(true);
            ui->labelCurrentAge->setHidden(false);
            ui->labelEntDeath->setHidden(true);
            ui->lineEdit_yod->setHidden(true);
        }

        neweditscientistRelations(currentID);
        neweditscientistClickableLink(link);


        ui->labelEntDescr->setText("Description: ");
        ui->textEdit_descr->setReadOnly(true);
        ui->labelEntGender->setText("Gender: ");
        ui->comboBox_gender->setEnabled(false);
        ui->labelEntLink->setText("Link: ");
        ui->lineEdit_link->setReadOnly(true);




    }

    setModal(true);
    exec();

}

void addNewScientist::neweditscientistRelations(int currentID)
{
    vector<computer> sciLinkedToCom = serviceobject.servGetComputersLinkedToScientists(currentID);

    if (sciLinkedToCom.size() > 0)
    {
        ui->labelRelations->setHidden(false);
        ui->textBrowser_relations->setHidden(false);
        QString linkedComputers;
        string outoffunc;
        for (unsigned int x = 0; x < sciLinkedToCom.size(); x++)
        {
            string space = "\n";
            string temp;
            temp = sciLinkedToCom.at(x).getComName();

            if (sciLinkedToCom.size() > 1)
            {
                outoffunc += temp + space;
            }
            else
            {
                outoffunc = temp;
            }
        }

        linkedComputers = QString::fromStdString(outoffunc);
        ui->textBrowser_relations->setText(linkedComputers);
    }
}

void addNewScientist::neweditscientistClickableLink(QString link)
{
    ui->labelEntLink->setHidden(true);
    ui->lineEdit_link->setHidden(true);
    ui->labelClickableLink->setHidden(false);
    ui->labelClickableUrlReal->setHidden(false);

    QString finalurl;
    //QString myString = "Last Name:SomeName, Day:23";
    QStringList myLink = link.split("//");
    //qDebug() << "String list is:  "<< myLink.last();

    QString http = "http://";

    QString clickhere = "\">"+myLink.last()+"</a>";
    QString begin = "<a href=\"";
    //qDebug () << clickhere << " " << begin;
    finalurl = begin + (http + myLink.last()) + clickhere;

    //qDebug () << finalurl ;

    ui->labelClickableUrlReal->setText(finalurl);
    ui->labelClickableUrlReal->setTextFormat(Qt::RichText);
    ui->labelClickableUrlReal->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->labelClickableUrlReal->setOpenExternalLinks(true);
}

void addNewScientist::on_buttonBox_editScientist_accepted()
{
    qDebug () << "button edit pressed ";


    string name = ui->lineEdit_name->text().toStdString();
    int yob = ui->lineEdit_yob->text().toInt();
    int yod = ui->lineEdit_yod->text().toInt();
    string link = ui->lineEdit_link->text().toStdString();
    int gender = ui->comboBox_gender->currentIndex();
    string descr = ui->textEdit_descr->document()->toPlainText().toStdString();
    int sciid = ui->labelSciid->text().toInt();

    qDebug () << "id is : " << sciid ;

    if(name != "")
    {
        scientist sc(sciid, name, gender, yob, yod, descr, link);
        serviceobject.servUpdateSqlScientist(sc);
        serviceobject.servReadSqlScientists();
    }
    else
    {

        QMessageBox::warning(this, "Error", "You have to include a name for the Scientist!");
    }

    addNewScientist::close();

}

void addNewScientist::on_buttonBox_editScientist_rejected()
{

}
