#include "UI/mainwindow.h"
#include <QApplication>
#include "Services/service.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
