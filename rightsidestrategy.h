#ifndef RIGHTSIDESTRATEGY_H
#define RIGHTSIDESTRATEGY_H

#include <QString>
#include <QtCharts/QAbstractSeries>
#include <QAbstractItemView>

using namespace QtCharts;

class RightSideStrategy
{
public:
    enum VIEW_OR_SERIES {
        VIEW,
        SERIES
    };

protected:
    VIEW_OR_SERIES m_viewOrSeries;
    QAbstractSeries *m_series = nullptr;
    QAbstractItemView *m_view = nullptr;

public:

    VIEW_OR_SERIES viewOrSeries();
    QAbstractSeries* series();
    QAbstractItemView* view();

    RightSideStrategy() = default;
    ~RightSideStrategy();
};

#endif // RIGHTSIDESTRATEGY_H
