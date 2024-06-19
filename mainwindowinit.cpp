#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
{
    this->setMinimumSize(640, 400);

    mainVLayout = new QVBoxLayout();
    pathLabel = new QLabel();
    mainHLayout = new QHBoxLayout();
    menuBar = new QMenuBar(this);
    leftSideTreeView = new QTreeView();

    mainVLayout->setMenuBar(menuBar);
    mainVLayout->addWidget(pathLabel);
    mainVLayout->addLayout(mainHLayout);
    mainHLayout->addWidget(leftSideTreeView);

    menuGroup = new QMenu("Group");
    menuView = new QMenu("View");
    menuBar->addMenu(menuGroup);
    menuBar->addMenu(menuView);

    centralWidget_ = new QWidget();
    this->setCentralWidget(centralWidget_);
    this->setMenuBar(menuBar);

    centralWidget_->setLayout(mainVLayout);

    leftViewModel.setRootPath(QDir::currentPath());
    leftSideTreeView->setModel(&leftViewModel);
    leftSideTreeView->hideColumn(3);
    leftSideTreeView->hideColumn(2);
    leftSideTreeView->hideColumn(1);
    leftSideTreeView->setHeaderHidden(true);

    rightSideItemModel = new QStandardItemModel();

    pathLabel->setText("");

    connect(leftSideTreeView, &QTreeView::pressed, this, &MainWindow::updateView);
}

MainWindow::~MainWindow()
{

}
