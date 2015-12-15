#include "addnewscientist.h"
#include "ui_addnewscientist.h"
//#include "DataLayer/workingclass.h"
//#include "Services/scientistserviceclass.h"
//#include <QDateEdit>
//#include <sstream>
//#include <QDebug>
//FORCE UPDATE!

using namespace std;

addNewScientist::addNewScientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addNewScientist)
{
    ui->setupUi(this);
    //ui->buttonBox_editScientist->setHidden(true);
    ui->newOkCancel_Edit->setHidden(true);
    ui->labelSciid->setHidden(true);
    ui->labelCurrentAge->setHidden(true);
    ui->lineEdit_currentAge->setHidden(true);
    ui->labelAgeAtDeath->setHidden(true);
    ui->lineEdit_AgeAtDeath->setHidden(true);
    ui->labelRelations->setHidden(true);
    ui->textBrowser_relations->setHidden(true);
    ui->labelClickableLink->setHidden(true);
    ui->labelClickableUrlReal->setHidden(true);
    ui->errorInName->setHidden(true);
    ui->errorInYob->setHidden(true);
    ui->errorInYod->setHidden(true);
    //ui->checkBox_stillAlive->setHidden(true);
    //ui->lineEdit_yob->setHidden(true);
    //ui->lineEdit_yod->setHidden(true);
}

addNewScientist::~addNewScientist()
{
    delete ui;
}

//void addNewScientist::on_buttonBox_accepted()
//{

//    bool goodInput = false;

//    if ((on_lineEdit_name_editingFinished() == false)&&(on_dateEdit_yod_editingFinished() == false))
//    {
//        goodInput = true;
//    }

//    scientist sc;
//    sc.setName(ui->lineEdit_name->text().toStdString());
//    sc.setDescription(ui->textEdit_descr->toPlainText().toStdString());
//    sc.setLink(ui->lineEdit_link->text().toStdString());
//    //sc.setYearOfBirth(ui->lineEdit_yob->text().toInt());
//    //sc.setYearOfDeath(ui->lineEdit_yod->text().toInt());
//    sc.setYearOfBirth(ui->dateEdit_yob->date().year());

//    if (ui->checkBox_stillAlive->checkState() == 0)
//    {
//        sc.setYearOfDeath(ui->dateEdit_yod->date().year());
//    }

//    sc.setGender(ui->comboBox_gender->currentIndex());

//    if (goodInput)
//    {
//        serviceobject.servAddscientist(sc);
//        serviceobject.servReadSqlScientists();
//    }
//    else
//    {
//        QMessageBox::warning(this, "Error", "Name or year incorrectly entered!");
//    }

//    qDebug () << "ég er hér!!!";
//    //addNewScientist::close();
//}

//void addNewScientist::addScientistToDatabase(scientist &sc)
//{
//    serviceobject.servAddscientist(sc);
//}

//void addNewScientist::addScientistErrorCorrection(scientist &sc)
//{
//    bool badName = false;
//    bool errorInYOB = false;
//    bool errorInYOD = false;
//    sc.setName(serviceobject.nameCorrection(sc.getName(), badName));
//    sc.setYearOfBirth(serviceobject.yearCorrection(sc.getYearOfBirth(), errorInYOB));
//    sc.setYearOfDeath(serviceobject.yearCorrection(sc.getYearOfDeath(), errorInYOD));

//    if (badName||errorInYOB||errorInYOD)
//    {
//        qDebug () << "ERROR IN NAME!" ;

//        if (badName)
//        {
//            serviceobject.errorMessage("Name not correctly formatted. Please enter letters only.");
//        }
//        if (errorInYOB||errorInYOD)
//        {
//            serviceobject.errorMessage("Year not correctly formatted. Please enter valid years only.");
//        }
//    }
//    else
//    {
//        addScientistToDatabase(sc);
//        qDebug () << "NAME ADDED TO DATABASE!" ;
//        serviceobject.completeMessage("Name was successfully added to the Database!");
//        //FÆRA ÚR SERVICE CLASS.
//    }
//}

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
            //qDebug () << name;
        }
    }

    QDate dYob, dYod;
    dYob.setDate(yob.toInt(),1,1);
    dYod.setDate(yod.toInt(),1,1);

    ui->lineEdit_name->setText(name);
    ui->lineEdit_link->setText(link);
    ui->dateEdit_yob->setDate(dYob);
    ui->dateEdit_yod->setDate(dYod);
//    ui->lineEdit_yob->setText(yob);
//    ui->lineEdit_yod->setText(yod);
    ui->comboBox_gender->setCurrentIndex(gender);
    ui->textEdit_descr->setText(descr);
    ui->labelSciid->setText(sciid);
    this->setWindowTitle("Edit Computer Scientist in the Database");
    //ui->buttonBox->setHidden(true);
    ui->newOkCancel_New->setHidden(true);
    //ui->buttonBox_editScientist->setHidden(false);
    ui->newOkCancel_Edit->setHidden(false);

    bool dead = true;
    if (yod.toInt() == 0)
    {
        dead = false;
        ui->checkBox_stillAlive->setChecked(true);
    }

    if (edit == false)
    {
        ui->checkBox_stillAlive->setHidden(true);
        this->setWindowTitle("More information about the Scientist");
        //ui->buttonBox_editScientist->setHidden(true);
        ui->newOkCancel_Edit->setHidden(true);

        ui->labelEntName->setText("Name: ");
        ui->lineEdit_name->setReadOnly(true);
        ui->labelEntBirth->setText("Year of Birth: ");
        //ui->lineEdit_yob->setReadOnly(true);
        ui->dateEdit_yob->setReadOnly(true);
        if (dead)
        {
            int ageAtDeath = yod.toInt() - yob.toInt();

            ui->lineEdit_AgeAtDeath->setHidden(false);
            ui->lineEdit_AgeAtDeath->setText(QString::number(ageAtDeath));
            ui->lineEdit_AgeAtDeath->setReadOnly(true);
            ui->labelAgeAtDeath->setHidden(false);
            //ui->lineEdit_yod->setReadOnly(true);
            ui->dateEdit_yod->setReadOnly(true);

        }
        else
        {
            QDate date;
            date.currentDate();
            int currentYear = 2015;
            int currentAge = currentYear - yob.toInt();

            ui->labelEntDeath->setText("Year of Death: ");
            //ui->lineEdit_yod->setReadOnly(true);
            ui->dateEdit_yod->setReadOnly(true);
            ui->lineEdit_currentAge->setHidden(false);
            ui->lineEdit_currentAge->setText(QString::number(currentAge));
            ui->lineEdit_currentAge->setReadOnly(true);
            ui->labelCurrentAge->setHidden(false);
            ui->labelEntDeath->setHidden(true);
            //ui->lineEdit_yod->setHidden(true);
            ui->dateEdit_yod->setHidden(true);
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
    if (link.size() > 3)
    {
        ui->labelEntLink->setHidden(true);
        ui->lineEdit_link->setHidden(true);
        ui->labelClickableLink->setHidden(false);
        ui->labelClickableUrlReal->setHidden(false);
    }
    else if (link.size() < 3)
    {
        ui->labelEntLink->setHidden(true);
        ui->lineEdit_link->setHidden(true);
        ui->labelClickableLink->setHidden(true);
        ui->labelClickableUrlReal->setHidden(true);
    }

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

//void addNewScientist::on_buttonBox_editScientist_accepted()
//{
//    qDebug () << "button edit pressed ";


//    string name = ui->lineEdit_name->text().toStdString();
//    //int yob = ui->lineEdit_yob->text().toInt();
//    //int yod = ui->lineEdit_yod->text().toInt();

//    int yob = ui->dateEdit_yob->date().year();
//    int yod = 0;

//    if (ui->checkBox_stillAlive->checkState() == 0)
//    {
//        yod = ui->dateEdit_yod->date().year();
//    }

//    string link = ui->lineEdit_link->text().toStdString();
//    int gender = ui->comboBox_gender->currentIndex();
//    string descr = ui->textEdit_descr->document()->toPlainText().toStdString();
//    int sciid = ui->labelSciid->text().toInt();

//    bool goodInput = false;

//    if ((on_lineEdit_name_editingFinished() == false)&&(on_dateEdit_yod_editingFinished() == false))
//    {
//        goodInput = true;
//    }

//    if(goodInput)
//    {
//        scientist sc(sciid, name, gender, yob, yod, descr, link);
//        serviceobject.servUpdateSqlScientist(sc);
//        serviceobject.servReadSqlScientists();
//    }
//    else
//    {
//        QMessageBox::warning(this, "Error", "Name or year not correctly entered!");
//    }

//    addNewScientist::close();

//}

//void addNewScientist::on_buttonBox_editScientist_rejected()
//{
////    ui->errorInName->setHidden(true);
////    addNewScientist::close();
//}
bool addNewScientist::on_lineEdit_name_editingFinished()
{
    bool badname = false;
    QString name = ui->lineEdit_name->text();
    string sname = serviceobject.nameCorrection(name.toStdString(),badname);
    name = QString::fromStdString(sname);

    if (name.length() < 2)
    {
        badname = true;
    }

    if (badname == true)
    {
        ui->errorInName->setHidden(false);
        ui->errorInName->setText("<font color='Red'>Name is incorrectly formatted.</font>");
    }
    else
    {
        ui->lineEdit_name->setText(name);
        ui->errorInName->setHidden(true);
        badname = false;
    }

    return badname;
}


//bool addNewScientist::on_lineEdit_yob_editingFinished()
//{
//    bool badyob = false;
//    QString yob = ui->lineEdit_yob->text();
//    int syob = serviceobject.yearCorrection(yob.toInt(), badyob);
//    QString yobf = QString::number(syob);

//    if (badyob == true)
//    {
//        ui->errorInYob->setHidden(false);
//        ui->errorInYob->setText("<font color='Red'>Year not properly formatted.</font>");
//    }
//    else
//    {
//        ui->lineEdit_yob->setText(yobf);
//        ui->errorInYob->setHidden(true);
//        badyob = false;
//    }

//    return badyob;
//}

//bool addNewScientist::on_lineEdit_yod_editingFinished()
//{
//    bool badyod = false;
//    QString yod = ui->lineEdit_yod->text();
//    ui->errorInYod->setHidden(true);

//    if (yod == "0")
//    {
//        badyod = false;
//        //ui->errorInYod->setHidden(true);
//    }

//    if ((yod.length() != 0)&&((yod != "0")))
//    {

//        int syod = serviceobject.yearCorrection(yod.toInt(), badyod);
//        yod = QString::number(syod);

//        int syob = ui->lineEdit_yob->text().toInt();
//        if (syod < syob)
//        {
//            badyod = true;
//        }

//        if (badyod == true)
//        {
//            ui->errorInYod->setHidden(false);
//            ui->errorInYod->setText("<font color='Red'>Year not properly formatted.</font>");
//        }
//        else
//        {
//            ui->lineEdit_yod->setText(yod);
//            ui->errorInYod->setHidden(true);
//            badyod = false;
//        }
//    }
//    return badyod;
//}


bool addNewScientist::on_dateEdit_yod_editingFinished()
{
    bool badYod;

    if (ui->checkBox_stillAlive->checkState() == 0) // dauður!
    {
        if (ui->dateEdit_yob->date().year() >= ui->dateEdit_yod->date().year())
        {
            ui->errorInYod->setHidden(false);
            ui->errorInYod->setText("<font color='Red'>A Scientist cannot die before he is born.</font>");
            badYod = true;
        }
        else if (ui->dateEdit_yod->date().year() > CURRENTYEAR)
        {
            ui->errorInYod->setHidden(false);
            ui->errorInYod->setText("<font color='Red'>A Scientist cannot die in the future.</font>");
            badYod = true;
        }
        else
        {
            ui->errorInYod->setHidden(true);
            badYod = false;
        }
    }
//    else
//    {
//        ui->errorInYod->setHidden(true);
//        badYod = false;
//        qDebug () << "YOD4";

//    }

    //qDebug () << "badyod is :" <<badYod;
    return badYod;
}

void addNewScientist::on_newOkCancel_New_accepted()
{

    bool goodInput = false;

    if ((on_lineEdit_name_editingFinished() == false)&&(on_dateEdit_yod_editingFinished() == false)
            &&(on_dateEdit_yob_editingFinished() == false))
    {
        goodInput = true;
    }

    //qDebug () << "yob check: "<<on_dateEdit_yob_editingFinished();

    scientist sc;
    sc.setName(ui->lineEdit_name->text().toStdString());
    sc.setDescription(ui->textEdit_descr->toPlainText().toStdString());
    sc.setLink(ui->lineEdit_link->text().toStdString());
    //sc.setYearOfBirth(ui->lineEdit_yob->text().toInt());
    //sc.setYearOfDeath(ui->lineEdit_yod->text().toInt());
    sc.setYearOfBirth(ui->dateEdit_yob->date().year());

    if (ui->checkBox_stillAlive->checkState() == 0)
    {
        sc.setYearOfDeath(ui->dateEdit_yod->date().year());
    }

    sc.setGender(ui->comboBox_gender->currentIndex());

    if (goodInput)
    {
        serviceobject.servAddscientist(sc);
        serviceobject.servReadSqlScientists();
        //qDebug () << "added to database!";
        addNewScientist::close();

    }
    else
    {
        QMessageBox::warning(this, "Error", "Name or year incorrectly entered!");
    }

}

void addNewScientist::on_newOkCancel_New_rejected()
{
    addNewScientist::close();
}

void addNewScientist::on_newOkCancel_Edit_accepted()
{
    //qDebug () << "button edit pressed ";

    string name = ui->lineEdit_name->text().toStdString();
    //int yob = ui->lineEdit_yob->text().toInt();
    //int yod = ui->lineEdit_yod->text().toInt();

    int yob = ui->dateEdit_yob->date().year();
    int yod = 0;

    if (ui->checkBox_stillAlive->checkState() == 0)
    {
        yod = ui->dateEdit_yod->date().year();
    }

    string link = ui->lineEdit_link->text().toStdString();
    int gender = ui->comboBox_gender->currentIndex();
    string descr = ui->textEdit_descr->document()->toPlainText().toStdString();
    int sciid = ui->labelSciid->text().toInt();

    bool goodInput = false;

    if ((on_lineEdit_name_editingFinished() == false)&&(on_dateEdit_yod_editingFinished() == false)
            &&(on_dateEdit_yob_editingFinished() == false))
    {
        goodInput = true;
    }

    if(goodInput)
    {
        scientist sc(sciid, name, gender, yob, yod, descr, link);
        serviceobject.servUpdateSqlScientist(sc);
        serviceobject.servReadSqlScientists();
        addNewScientist::close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Name or year not incorrectly entered!");
    }
}

void addNewScientist::on_newOkCancel_Edit_rejected()
{
    addNewScientist::close();
}

void addNewScientist::on_checkBox_stillAlive_toggled(bool checked)
{
    if (checked)
    {
        ui->dateEdit_yod->setDisabled(true);
        ui->errorInYod->setHidden(true);
    }
    else
    {
        ui->dateEdit_yod->setDisabled(false);
    }
}

bool addNewScientist::on_dateEdit_yob_editingFinished()
{
    bool badYob;

    if (ui->dateEdit_yob->date().year() > CURRENTYEAR)
    {
        ui->errorInYob->setHidden(false);
        ui->errorInYob->setText("<font color='Red'>Scientist can't be born in the future.</font>");
        badYob = true;
        //qDebug () << "Future man";
    }
    else
    {
        ui->errorInYob->setHidden(true);
        badYob = false;
        //qDebug () << "NOT Future man";
    }

    //qDebug () << "badyod is :" <<badYod;
    return badYob;
}
