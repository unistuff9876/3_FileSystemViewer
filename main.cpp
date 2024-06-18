#include "mainwindow.h"

#include <QApplication>
#include <QFileSystemModel>
#include <QDir>

#include "groupstrategyfileextensions.h"
#include "groupstrategyimmediatefolders.h"

#include "viewstrategytable.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setAttribute(Qt::AA_DontShowIconsInMenus);

    MainWindow &mainWindow = MainWindow::instance();

    mainWindow.addViewStrategy("Table", new ViewStrategyTable);
    //mainWindow.addViewStrategy("Bar Chart", new RightSideStrategyBarSeries);

    mainWindow.addGroupStrategy("File Extensions", new GroupStrategyFileExtensions);
    mainWindow.addGroupStrategy("Immediate Folders", new GroupStrategyImmediateFolders);

    mainWindow.show();

    return a.exec();
}
