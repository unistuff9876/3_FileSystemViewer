#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    ui->rightSideClear->setModel(&rightViewModel);/*
    ui->rightView->hideColumn(3);
    ui->rightView->hideColumn(2);
    ui->rightView->hideColumn(1);
    ui->rightView->setHeaderHidden(true);/**/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setRightSideStrategy(RightSideStrategy *rightSideStrategy)
{
    delete this->rightSideStrategy;
    this->rightSideStrategy = rightSideStrategy;

    ui->rightSideClear->setVisible(false);

    switch(rightSideStrategy->viewOrSeries()) {
    case RightSideStrategy::VIEW_OR_SERIES::SERIES:
        //ui->mainHLayout->addWidget(rightSideStrategy->series());
    break;
    case RightSideStrategy::VIEW_OR_SERIES::VIEW:
        ui->mainHLayout->addWidget(rightSideStrategy->view());
    break;

    default:
    break;
    }

}
