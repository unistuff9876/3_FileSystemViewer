#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QAbstractItemView>

#include "rightsidestrategy.h"
#include "rightsidestrategylistview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindow *ui;

    QFileSystemModel leftViewModel;
    QFileSystemModel rightViewModel;

    RightSideStrategy *rightSideStrategy = new RightSideStrategyListView;

    //auto rightSide = ui->rightSideClear;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setRightSideStrategy(RightSideStrategy *rightSideStrategy);
};

#endif // MAINWINDOW_H
