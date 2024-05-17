#include "rightsidestrategybarseries.h"

#include <QBarSeries>

RightSideStrategyBarSeries::RightSideStrategyBarSeries()
{
    m_viewOrSeries = VIEW_OR_SERIES::SERIES;
    m_series = new QtCharts::QBarSeries;
}
