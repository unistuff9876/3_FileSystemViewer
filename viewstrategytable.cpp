#include "viewstrategytable.h"

#include "mainwindow.h"

#include <QTableView>

ViewStrategyTable::ViewStrategyTable()
{
    m_widget = new QTableView;
}

void ViewStrategyTable::setAsCurrent()
{
    //auto mainWindow = MainWindow::instance();

    //mainWindow.ui->MainHLayout.addWidget(m_widget);
}

void ViewStrategyTable::unsetAsCurrent()
{

}

void ViewStrategyTable::update(GroupStrategyResult groupStrategyResult)
{

}
