#ifndef VIEWSTRATEGYBARSERIES_H
#define VIEWSTRATEGYBARSERIES_H

#include "viewstrategy.h"

#include <QBarSeries>

class ViewStrategyBarSeries : public ViewStrategy
{
private:
    QtCharts::QBarSeries *m_series;
    QtCharts::QChart *m_chart;

public:
    ViewStrategyBarSeries();

    void adaptAndApplyData(QStandardItemModel *model, GroupStrategyResult result) final;
};

#endif // VIEWSTRATEGYBARSERIES_H
