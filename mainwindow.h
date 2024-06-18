#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QAbstractItemView>
#include <QVector>
#include <QSharedPointer>
#include <QChartView>

#include "groupstrategy.h"
#include "rightsidestrategy.h"

class ViewStrategy;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindow *ui;

    QFileSystemModel leftViewModel;
    QFileSystemModel rightViewModel;

    ViewStrategy *viewStrategyCurrent = nullptr;
    QVector<ViewStrategy*> viewStrategyVector;

    GroupStrategy *groupStrategyCurrent = nullptr;
    QVector<GroupStrategy*> groupStrategyVector;

    QtCharts::QChart *rightSideChart;
    QtCharts::QChartView *rightSideChartView;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    static MainWindow &instance();

    void addViewStrategy(QString name, ViewStrategy *viewStrategy);
    void addGroupStrategy(QString name, GroupStrategy *groupStrategy);

public slots:
    void setViewStrategy(ViewStrategy *viewStrategy);
    void setViewStrategy(int i);

    void setGroupStrategy(GroupStrategy *groupStrategy);
    void setGroupStrategy(int i);

    void updateView();

private slots:
    void changeRightSideFolder(const QModelIndex &index);
};

#endif // MAINWINDOW_H
