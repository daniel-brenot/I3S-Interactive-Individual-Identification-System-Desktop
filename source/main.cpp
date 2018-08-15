#include "startupselector.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartupSelector w;
    w.show();

    return a.exec();
}
