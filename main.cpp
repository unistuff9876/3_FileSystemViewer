#include "mainwindow.h"

#include <QApplication>
#include <QFileSystemModel>
#include <QDir>

#include "rightsidestrategylistview.h"
#include "rightsidestrategybarseries.h"

#include "groupstrategyfileextensions.h"
#include "groupstrategyimmediatefolders.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setAttribute(Qt::AA_DontShowIconsInMenus);

    MainWindow mainWindow;

    mainWindow.addRightSideStrategy("Table", new RightSideStrategyListView);
    mainWindow.addRightSideStrategy("Bar Chart", new RightSideStrategyBarSeries);

    mainWindow.addGroupStrategy("File Extensions", new GroupStrategyFileExtensions);
    mainWindow.addGroupStrategy("Immediate Folders", new GroupStrategyImmediateFolders);

    mainWindow.show();

    return a.exec();
}
