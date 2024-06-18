#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include "viewstrategy.h"

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
}

MainWindow &MainWindow::instance()
{
    static MainWindow inst;
    return inst;
}

void MainWindow::addViewStrategy(QString name, ViewStrategy *viewStrategy)
{
    int i = viewStrategyVector.size();
    viewStrategyVector.push_back(viewStrategy);

    auto action = ui->menuView->addAction(name, this, [=](){setViewStrategy(i);});
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

    auto action = ui->menuGroup->addAction(name, this, [=](){setGroupStrategy(i);});
    action->setCheckable(true);
    action->setChecked(false);

    if (i == 0) {
        setGroupStrategy(0);
    }
}

void MainWindow::setViewStrategy(ViewStrategy *viewStrategy)
{
    ui->rightSideClear->setVisible(false);
    if (viewStrategyCurrent != nullptr) {
        if (viewStrategyCurrent == viewStrategy) {
            return;
        }
        viewStrategyCurrent->unsetAsCurrent();
    }

    viewStrategyCurrent = viewStrategy;
    viewStrategyCurrent->setAsCurrent();
}

void MainWindow::setViewStrategy(int i)
{
    if (i >= viewStrategyVector.size()) {
        Q_ASSERT("MainWindow::setViewStrategy(int) - index OOB");
        return;
    }

    auto &strategyToSet = viewStrategyVector[i];

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
    }

    setGroupStrategy(strategyToSet);
}

void MainWindow::updateView()
{
    //qDebug() << ;
    //groupStrategyCurrent->use("C:/");
    //viewStrategyCurrent->update(groupStrategyCurrent->use("C:/"));
}

void MainWindow::changeRightSideFolder(const QModelIndex &index)
{
    if (viewStrategyCurrent != nullptr
        && groupStrategyCurrent != nullptr
        && leftViewModel.isDir(index))
    {
        QString path = leftViewModel.filePath(index);
        //leftViewModel.setRootPath(path);
        ui->pathLabel->setText(path + " loading");
        viewStrategyCurrent->update(groupStrategyCurrent->use(path));
        ui->pathLabel->setText(path);
        /*switch(rightSideStrategyCurrent->viewOrSeries()) {
        case RightSideStrategy::VIEW_OR_SERIES::SERIES:
            //ui->mainHLayout->addWidget(rightSideStrategy->series());
        break;
        case RightSideStrategy::VIEW_OR_SERIES::VIEW:
            rightSideStrategyCurrent->view()->setModel(&rightViewModel);
            rightSideStrategyCurrent->view()->setRootIndex(rightViewModel.index(path));

            ui->pathLabel->setText(path);
        break;
        }*/
    }
}
