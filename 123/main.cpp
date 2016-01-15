#include "mainwindow.h"
#include "dialog.h"
#include "data.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::addLibraryPath("./plugins");
    QApplication a(argc, argv);
    QApplication::addLibraryPath("./plugins");
    MainWindow w;
    w.show();

    return a.exec();
}
