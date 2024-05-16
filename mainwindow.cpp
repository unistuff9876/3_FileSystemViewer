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
    ui->rightView->setModel(&rightViewModel);/*
    ui->rightView->hideColumn(3);
    ui->rightView->hideColumn(2);
    ui->rightView->hideColumn(1);
    ui->rightView->setHeaderHidden(true);/**/
}

MainWindow::~MainWindow()
{
    delete ui;
}
