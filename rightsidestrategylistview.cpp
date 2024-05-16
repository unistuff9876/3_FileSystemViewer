#include "rightsidestrategy.h"
#include "rightsidestrategylistview.h"

#include <QListView>

RightSideStrategyListView::RightSideStrategyListView()
{
    viewOrSeries = VIEW_OR_SERIES::view;
    m_view = new QListView;
}
