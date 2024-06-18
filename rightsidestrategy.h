#ifndef RIGHTSIDESTRATEGY_H
#define RIGHTSIDESTRATEGY_H

#include <QString>
#include <QtCharts/QAbstractSeries>
#include <QAbstractItemView>
#include <QMainWindow>

#include "groupstrategyresult.h"

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

    virtual void update(GroupStrategyResult groupStrategyResult) = 0;

    RightSideStrategy() = default;
    ~RightSideStrategy();
};

#endif // RIGHTSIDESTRATEGY_H
