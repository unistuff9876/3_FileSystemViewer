#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QAbstractItemView>
#include <QVector>
#include <QSharedPointer>
#include <QChartView>

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

    RightSideStrategy *rightSideStrategyCurrent = nullptr;
    QVector<RightSideStrategy*> rightSideStrategyVector;

    QtCharts::QChart *rightSideChart;
    QtCharts::QChartView *rightSideChartView;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addRightSideStrategy(QString name, RightSideStrategy *rightSideStrategy);

public slots:
    void setRightSideStrategy(RightSideStrategy *rightSideStrategy);
    void setRightSideStrategy(int i);

private slots:
    void changeRightSideFolder(const QModelIndex &index);
};

#endif // MAINWINDOW_H
