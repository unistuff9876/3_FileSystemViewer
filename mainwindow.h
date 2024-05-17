#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QAbstractItemView>
#include <QVector>
#include <QSharedPointer>

#include "rightsidestrategy.h"
#include "rightsidestrategyblank.h"
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

    RightSideStrategy *rightSideStrategyCurrent = new RightSideStrategyListView;
    QVector<RightSideStrategy*> rightSideStrategyVector;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addRightSideStrategy(QString name, RightSideStrategy *rightSideStrategy);

public slots:
    void setRightSideStrategy(RightSideStrategy *rightSideStrategy);
    void setRightSideStrategy(int i);
};

#endif // MAINWINDOW_H
