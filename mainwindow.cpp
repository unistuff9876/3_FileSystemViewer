#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    leftViewModel.setRootPath(QDir::currentPath());
    ui->leftView->setModel(&leftViewModel);
    ui->leftView->hideColumn(3);
    ui->leftView->hideColumn(2);
    ui->leftView->hideColumn(1);
    ui->leftView->setHeaderHidden(true);

    rightViewModel.setRootPath(QDir::currentPath());

    rightSideChart = new QtCharts::QChart;
    rightSideChartView = new QtCharts::QChartView(rightSideChart);
    ui->mainHLayout->addWidget(rightSideChartView);
    rightSideChartView->setVisible(false);

    ui->pathLabel->setText("");

    connect(ui->leftView, &QTreeView::pressed, this, &MainWindow::changeRightSideFolder);
}

MainWindow::~MainWindow()
{
    delete ui;

    for(auto &i: rightSideStrategyVector) {
        delete i;
    }
}

void MainWindow::addRightSideStrategy(QString name, RightSideStrategy *rightSideStrategy)
{
    int i = rightSideStrategyVector.size();
    rightSideStrategyVector.push_back(rightSideStrategy);

    auto action = ui->menuView->addAction(name, this, [=](){setRightSideStrategy(i);});
    action->setCheckable(true);
    action->setChecked(false);

    if (i == 0) {
        setRightSideStrategy(0);
    }
}

void MainWindow::addGroupStrategy(QString name, GroupStrategy *groupStrategy)
{
    int i = groupStrategyVector.size();
    groupStrategyVector.push_back(groupStrategy);

    auto action = ui->menuGroup->addAction(name, this, [=](){setGroupStrategy(i);});
    action->setCheckable(true);
    action->setChecked(false);

    if (i == 0) {
        setGroupStrategy(0);
    }
}

void MainWindow::setRightSideStrategy(RightSideStrategy *rightSideStrategy)
{
    ui->rightSideClear->setVisible(false);
    if (rightSideStrategyCurrent != nullptr) {
        if (rightSideStrategyCurrent == rightSideStrategy) {
            return;
        }

        switch(rightSideStrategyCurrent->viewOrSeries()) {
        case RightSideStrategy::VIEW_OR_SERIES::SERIES:
            rightSideChartView->setVisible(false);
            rightSideChart->removeSeries(rightSideStrategyCurrent->series());
        break;
        case RightSideStrategy::VIEW_OR_SERIES::VIEW:
            rightSideStrategyCurrent->view()->setVisible(false);
            ui->mainHLayout->removeWidget(rightSideStrategyCurrent->view());
        break;
        default:
            Q_ASSERT("MainWindow::setRightSideStrategy(RightSideStrategy *) - default reached (1)");
        break;
        }
    }

    rightSideStrategyCurrent = rightSideStrategy;

    switch(rightSideStrategy->viewOrSeries()) {
    case RightSideStrategy::VIEW_OR_SERIES::SERIES:
        //ui->rightSideChartView->setChart(rightSideStrategy->series());
        //ui->rightSideChartView->setVisible(true);
        //ui->mainHLayout->addWidget(rightSideStrategy->series());
        rightSideChart->addSeries(rightSideStrategy->series());
        rightSideChartView->setVisible(true);
    break;
    case RightSideStrategy::VIEW_OR_SERIES::VIEW:
        ui->mainHLayout->addWidget(rightSideStrategy->view());
        rightSideStrategy->view()->setVisible(true);
    break;
    default:
        Q_ASSERT("MainWindow::setRightSideStrategy(RightSideStrategy *) - default reached (2)");
    break;
    }
}

void MainWindow::setRightSideStrategy(int i)
{
    if (i >= rightSideStrategyVector.size()) {
        Q_ASSERT("MainWindow::setRightSideStrategy(int) - index OOB");
        return;
    }

    auto &strategyToSet = rightSideStrategyVector[i];

    //unset the previous dropdown menu icons
    //and set the new one
    auto actions = ui->menuView->actions();
    for (int j = 0; j < actions.size(); j++) {
        if (j == i) {
            actions[j]->setChecked(true);
        }
        else {
            actions[j]->setChecked(false);
        }
    }/**/

    setRightSideStrategy(strategyToSet);
}

void MainWindow::setGroupStrategy(GroupStrategy *groupStrategy)
{
    if (groupStrategyCurrent != nullptr) {
        if (groupStrategyCurrent == groupStrategy) {
            return;
        }
    }

    groupStrategyCurrent = groupStrategy;
}

void MainWindow::setGroupStrategy(int i)
{
    if (i >= groupStrategyVector.size()) {
        Q_ASSERT("MainWindow::setGroupStrategy(int) - index OOB");
        return;
    }

    auto &strategyToSet = groupStrategyVector[i];

    //unset the previous dropdown menu icons
    //and set the new one
    auto actions = ui->menuGroup->actions();
    for (int j = 0; j < actions.size(); j++) {
        if (j == i) {
            actions[j]->setChecked(true);
        }
        else {
            actions[j]->setChecked(false);
        }
    }/**/

    setGroupStrategy(strategyToSet);
}

void MainWindow::changeRightSideFolder(const QModelIndex &index)
{
    //qDebug() << leftViewModel.filePath(index) << "is a dir:" << leftViewModel.isDir(index);

    if (rightSideStrategyCurrent != nullptr
        && leftViewModel.isDir(index))
    {
        QString path = leftViewModel.filePath(index);
        leftViewModel.setRootPath(path);
        switch(rightSideStrategyCurrent->viewOrSeries()) {
        case RightSideStrategy::VIEW_OR_SERIES::SERIES:
            //ui->mainHLayout->addWidget(rightSideStrategy->series());
        break;
        case RightSideStrategy::VIEW_OR_SERIES::VIEW:
            rightSideStrategyCurrent->view()->setModel(&rightViewModel);
            rightSideStrategyCurrent->view()->setRootIndex(rightViewModel.index(path));

            ui->pathLabel->setText(path);
        break;/*
        default:
            Q_ASSERT("MainWindow::changeRightSideFolder(const QModelIndex &) - default reached");
        break;*/
        }
    }
}
