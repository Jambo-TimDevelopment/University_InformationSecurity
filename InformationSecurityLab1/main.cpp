#include "mainwindowadmin.h"
#include <QApplication>
#include <QLabel>
#include "passphrase.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PassPhrase pp;
    pp.show();
    /*MainWindow w;
    w.show();*/
    return a.exec();
}
