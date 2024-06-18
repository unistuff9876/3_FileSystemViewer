#include "viewstrategy.h"

ViewStrategy::ViewStrategy()
{

}

ViewStrategy::~ViewStrategy()
{
    delete m_widget;
}

QWidget &ViewStrategy::widget()
{
    return m_widget;
}
