#ifndef VIEWSTRATEGYPIESERIES_H
#define VIEWSTRATEGYPIESERIES_H

#include "viewstrategy.h"

#include <QtCharts/QPieSeries>

class ViewStrategyPieSeries : public ViewStrategy
{
private:
    QtCharts::QPieSeries *m_series;
    QtCharts::QChart *m_chart;

public:
    ViewStrategyPieSeries();

    void adaptAndApplyData(QStandardItemModel *model, GroupStrategyResult result) final;
};

#endif // VIEWSTRATEGYPIESERIES_H
