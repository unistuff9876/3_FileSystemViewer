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
    //ui->rightSideClear->setModel(&rightViewModel);
    ui->rightSideClear->setVisible(true);

    ui->pathLabel->setText("");

    connect(ui->leftView, &QTreeView::pressed, this, &MainWindow::changeRightSideFolder);
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::setRightSideStrategy(RightSideStrategy *rightSideStrategy)
{
    ui->rightSideClear->setVisible(false);
    if (rightSideStrategyCurrent != nullptr) {
        ui->mainHLayout->removeWidget(rightSideStrategyCurrent->view());
    }

    rightSideStrategyCurrent = rightSideStrategy;

    switch(rightSideStrategy->viewOrSeries()) {
    case RightSideStrategy::VIEW_OR_SERIES::SERIES:
        //ui->mainHLayout->addWidget(rightSideStrategy->series());
    break;
    case RightSideStrategy::VIEW_OR_SERIES::VIEW:
        ui->mainHLayout->addWidget(rightSideStrategy->view());
    break;
    default:
        Q_ASSERT("MainWindow::setRightSideStrategy(RightSideStrategy *) - default reached");
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

void MainWindow::changeRightSideFolder(const QModelIndex &index)
{
    //qDebug() << leftViewModel.filePath(index) << "is a dir:" << leftViewModel.isDir(index);

    if (rightSideStrategyCurrent != nullptr
        && leftViewModel.isDir(index))
    {
        QString path = leftViewModel.filePath(index);
        leftViewModel.setRootPath(path);
        rightSideStrategyCurrent->view()->setModel(&rightViewModel);
        rightSideStrategyCurrent->view()->setRootIndex(rightViewModel.index(path));

        ui->pathLabel->setText(path);
    }
}
