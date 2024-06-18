#include "rightsidestrategylistview.h"

#include <QListView>

RightSideStrategyListView::RightSideStrategyListView()
{
    m_viewOrSeries = VIEW_OR_SERIES::VIEW;
    m_view = new QListView;
}

void RightSideStrategyListView::update(GroupStrategyResult groupStrategyResult)
{

}
