#include "mainwindow.h"

#include <QApplication>
#include <QFileSystemModel>
#include <QDir>
//#include <QTreeView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow;

    mainWindow.show();

    return a.exec();
}
