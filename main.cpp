#include "mainwindow.h"

#include <QApplication>
#include <QFileSystemModel>
#include <QDir>

#include "rightsidestrategylistview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow;

    mainWindow.show();
    mainWindow.setRightSideStrategy(new RightSideStrategyListView);

    return a.exec();
}
