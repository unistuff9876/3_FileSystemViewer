#include "mainwindow.h"

#include <QApplication>
#include <QFileSystemModel>
#include <QDir>

#include "rightsidestrategylistview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setAttribute(Qt::AA_DontShowIconsInMenus);

    MainWindow mainWindow;

    mainWindow.addRightSideStrategy("booti", new RightSideStrategyListView);

    mainWindow.show();

    //mainWindow.setRightSideStrategy(new RightSideStrategyListView);

    return a.exec();
}
