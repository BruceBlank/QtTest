#include <QtGui/QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include <iostream>

#include "qttest.h"

// main program creates application and main window
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // localize qt-strings
    QTranslator qtTranslator(0);
    qtTranslator.load(QString("qt_") + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    // localize application-strings (only german at the moment)
    QTranslator myTranslator(0);
    myTranslator.load(QString("qttest_") + QLocale::system().name(), "../QtTest");
    a.installTranslator(&myTranslator);

    MainWindow w;
    w.show();
    
    return a.exec();
}
