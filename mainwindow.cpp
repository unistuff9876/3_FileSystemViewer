#include "mainwindow.h"

#include <QDebug>

#include "viewstrategy.h"

MainWindow &MainWindow::instance()
{
    static MainWindow inst;
    return inst;
}

void MainWindow::addViewStrategy(QString name, ViewStrategy *viewStrategy)
{
    int i = viewStrategyVector.size();
    viewStrategyVector.push_back(viewStrategy);

    auto action = menuView->addAction(name, this, [=](){setViewStrategy(i);});
    action->setCheckable(true);
    action->setChecked(false);

    if (i == 0) {
        setViewStrategy(0);
    }
}

void MainWindow::addGroupStrategy(QString name, GroupStrategy *groupStrategy)
{
    int i = groupStrategyVector.size();
    groupStrategyVector.push_back(groupStrategy);

    auto action = menuGroup->addAction(name, this, [=](){setGroupStrategy(i);});
    action->setCheckable(true);
    action->setChecked(false);

    if (i == 0) {
        setGroupStrategy(0);
    }
}

void MainWindow::setViewStrategy(ViewStrategy *viewStrategy)
{
    if (viewStrategyCurrent != nullptr) {
        if (viewStrategyCurrent == viewStrategy) {
            return;
        }
        //hide current strategy
        viewStrategyCurrent->widget()->hide();
        //mainHLayout->removeWidget(viewStrategyCurrent->widget());
    }

    viewStrategyCurrent = viewStrategy;
    //set the new strategy
    mainHLayout->addWidget(viewStrategyCurrent->widget());
    viewStrategyCurrent->widget()->show();
}

void MainWindow::setViewStrategy(int i)
{
    if (i >= viewStrategyVector.size()) {
        qDebug() << "MainWindow::setViewStrategy(int) - index OOB";
        return;
    }

    auto &strategyToSet = viewStrategyVector[i];

    //unset the previous dropdown menu icons
    //and set the new one
    auto actions = menuView->actions();
    for (int j = 0; j < actions.size(); j++) {
        if (j == i) {
            actions[j]->setChecked(true);
        }
        else {
            actions[j]->setChecked(false);
        }
    }

    setViewStrategy(strategyToSet);
}

void MainWindow::setGroupStrategy(GroupStrategy *groupStrategy)
{
    if (groupStrategyCurrent != nullptr) {
        if (groupStrategyCurrent == groupStrategy) {
            return;
        }
    }

    groupStrategyCurrent = groupStrategy;

    //updateView(leftSideTreeView)
}

void MainWindow::setGroupStrategy(int i)
{
    if (i >= groupStrategyVector.size()) {
        qDebug() << "MainWindow::setGroupStrategy(int) - index OOB";
        return;
    }

    auto &strategyToSet = groupStrategyVector[i];

    //unset the previous dropdown menu icons
    //and set the new one
    auto actions = menuGroup->actions();
    for (int j = 0; j < actions.size(); j++) {
        if (j == i) {
            actions[j]->setChecked(true);
        }
        else {
            actions[j]->setChecked(false);
        }
    }

    setGroupStrategy(strategyToSet);
    //updateView(leftViewModel)
}

void MainWindow::updateView(const QModelIndex &index)
{
    if (viewStrategyCurrent == nullptr) {
        qDebug() << "MainWindow::updateView : viewStrategyCurrent == nullptr";
        return;
    }

    if (groupStrategyCurrent == nullptr) {
        qDebug() << "MainWindow::updateView : groupStrategyCurrent == nullptr";
        return;
    }

    if (!leftViewModel.isDir(index)) {
        qDebug() << "MainWindow::updateView : leftViewModel.isDir(index) == false";
        return;
    }

    QString path = leftViewModel.filePath(index);
    viewStrategyCurrent->adaptAndApplyData(rightSideItemModel, groupStrategyCurrent->use(path));

    pathLabel->setText(path);
}
