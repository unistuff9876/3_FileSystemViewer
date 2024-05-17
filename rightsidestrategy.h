#ifndef RIGHTSIDESTRATEGY_H
#define RIGHTSIDESTRATEGY_H

#include <QString>
#include <QtCharts/QAbstractSeries>
#include <QAbstractItemView>
#include <QMainWindow>

class RightSideStrategy
{
public:
    enum VIEW_OR_SERIES {
        VIEW,
        SERIES
    };

protected:
    VIEW_OR_SERIES m_viewOrSeries;
    QtCharts::QAbstractSeries *m_series = nullptr;
    QAbstractItemView *m_view = nullptr;

public:
    VIEW_OR_SERIES viewOrSeries();
    QtCharts::QAbstractSeries* series();
    QAbstractItemView* view();

    RightSideStrategy() = default;
    ~RightSideStrategy();
};

#endif // RIGHTSIDESTRATEGY_H
