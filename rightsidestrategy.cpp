#include "rightsidestrategy.h"

RightSideStrategy::~RightSideStrategy()
{
    delete m_series;
    delete m_view;
}
