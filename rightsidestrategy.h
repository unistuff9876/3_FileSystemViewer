#ifndef RIGHTSIDESTRATEGY_H
#define RIGHTSIDESTRATEGY_H

#include <QString>
#include <QtCharts/QAbstractSeries>
#include <QAbstractItemView>

using namespace QtCharts;

class RightSideStrategy
{
protected:
    enum VIEW_OR_SERIES {
        view,
        series
    };

    VIEW_OR_SERIES viewOrSeries;
    QAbstractSeries *m_series = nullptr;
    QAbstractItemView *m_view = nullptr;

public:
    RightSideStrategy() = default;
    ~RightSideStrategy();
};

#endif // RIGHTSIDESTRATEGY_H
