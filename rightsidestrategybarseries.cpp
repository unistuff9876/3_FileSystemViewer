#include "rightsidestrategybarseries.h"

#include <QBarSeries>
#include <QBarSet>

RightSideStrategyBarSeries::RightSideStrategyBarSeries()
{
    m_viewOrSeries = VIEW_OR_SERIES::SERIES;
    m_series = new QtCharts::QBarSeries;

    QtCharts::QBarSet *set0 = new QtCharts::QBarSet("Jane");
    QtCharts::QBarSet *set1 = new QtCharts::QBarSet("John");
    QtCharts::QBarSet *set2 = new QtCharts::QBarSet("Axel");
    QtCharts::QBarSet *set3 = new QtCharts::QBarSet("Mary");
    QtCharts::QBarSet *set4 = new QtCharts::QBarSet("Samantha");

    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    *set4 << 9 << 7 << 5 << 3 << 1 << 2;

    auto m_series_as_QBarSeries = reinterpret_cast<QtCharts::QBarSeries*>(m_series);
    m_series_as_QBarSeries->append(set0);
    m_series_as_QBarSeries->append(set1);
    m_series_as_QBarSeries->append(set2);
    m_series_as_QBarSeries->append(set3);
    m_series_as_QBarSeries->append(set4);
}
