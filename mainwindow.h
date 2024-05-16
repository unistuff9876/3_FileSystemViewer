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

    QFileSystemModel leftViewModel;
    QFileSystemModel rightViewModel;

    RightSideStrategy *rightSideStrategy = new RightSideStrategyListView();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
