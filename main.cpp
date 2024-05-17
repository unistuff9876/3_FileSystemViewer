#include "mainwindow.h"

#include <QApplication>
#include <QFileSystemModel>
#include <QDir>

#include "rightsidestrategylistview.h"
#include "rightsidestrategybarseries.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setAttribute(Qt::AA_DontShowIconsInMenus);

    MainWindow mainWindow;

    mainWindow.addRightSideStrategy("List", new RightSideStrategyListView);
    mainWindow.addRightSideStrategy("Bar Chart", new RightSideStrategyBarSeries);

    mainWindow.show();

    return a.exec();
}
