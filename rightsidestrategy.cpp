#include "rightsidestrategy.h"

RightSideStrategy::VIEW_OR_SERIES RightSideStrategy::viewOrSeries()
{
    return m_viewOrSeries;
}

QtCharts::QAbstractSeries *RightSideStrategy::series()
{
    return m_series;
}

QAbstractItemView *RightSideStrategy::view()
{
    return m_view;
}

RightSideStrategy::~RightSideStrategy()
{
    delete m_series;
    delete m_view;
}
