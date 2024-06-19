#include "viewstrategypieseries.h"

#include <QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

ViewStrategyPieSeries::ViewStrategyPieSeries()
{
    m_widget = new QtCharts::QChartView;
    m_chart = new QtCharts::QChart;

    reinterpret_cast<QtCharts::QChartView*>(m_widget)->setChart(m_chart);

    m_chart->legend()->setAlignment(Qt::AlignRight);
}

void ViewStrategyPieSeries::adaptAndApplyData(QStandardItemModel *model, GroupStrategyResult result)
{
    m_chart->removeAllSeries();
    m_series = new QtCharts::QPieSeries;

    for (int i = 0; i < result.itemCount(); i++) {
        QString strToInsert = result.names()[i] + "(" + percentageQString(result.sizes()[i], result.totalSize()) + ")";
        auto slice = new QtCharts::QPieSlice(strToInsert, result.sizes()[i]);
        m_series->append(slice);
    }
    m_chart->addSeries(m_series);
}
