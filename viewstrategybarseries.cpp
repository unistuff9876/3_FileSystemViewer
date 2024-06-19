#include "viewstrategybarseries.h"

#include <QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>

ViewStrategyBarSeries::ViewStrategyBarSeries()
{
    m_widget = new QtCharts::QChartView;
    m_chart = new QtCharts::QChart;

    reinterpret_cast<QtCharts::QChartView*>(m_widget)->setChart(m_chart);

    m_chart->legend()->setAlignment(Qt::AlignRight);
    //m_chart->setStyle()
}

void ViewStrategyBarSeries::adaptAndApplyData(QStandardItemModel *model, GroupStrategyResult result)
{
    m_chart->removeAllSeries();
    m_series = new QtCharts::QBarSeries;

    for (int i = 0; i < result.itemCount(); i++) {
        QString strToInsert = result.names()[i] + "(" + percentageQString(result.sizes()[i], result.totalSize()) + ")";
        auto set = new QtCharts::QBarSet(strToInsert);
        *set << result.sizes()[i];
        m_series->append(set);
    }
    m_chart->addSeries(m_series);
}
