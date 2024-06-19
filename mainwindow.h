#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QAbstractItemView>
#include <QVector>
#include <QSharedPointer>
#include <QChartView>

#include "groupstrategy.h"

#include <QBoxLayout>
#include <QLabel>
#include <QMenuBar>
#include <QTreeView>
#include <QStandardItemModel>

class ViewStrategy;

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QWidget *centralWidget_;
    QMenuBar *menuBar;
    QVBoxLayout *mainVLayout;
    QLabel *pathLabel;
    QHBoxLayout *mainHLayout;
    QTreeView *leftSideTreeView;

    QMenu *menuGroup;
    QMenu *menuView;

    QFileSystemModel leftViewModel;
    QFileSystemModel rightViewModel;

    ViewStrategy *viewStrategyCurrent = nullptr;
    QVector<ViewStrategy*> viewStrategyVector;

    GroupStrategy *groupStrategyCurrent = nullptr;
    QVector<GroupStrategy*> groupStrategyVector;

    QtCharts::QChart *rightSideChart;
    QtCharts::QChartView *rightSideChartView;

    QStandardItemModel *rightSideItemModel;

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

private slots:
    void updateView(const QModelIndex &index);
};

#endif // MAINWINDOW_H
