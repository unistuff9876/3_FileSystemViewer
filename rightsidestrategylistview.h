#ifndef RIGHTSIDESTRATEGYLISTVIEW_H
#define RIGHTSIDESTRATEGYLISTVIEW_H

#include "rightsidestrategy.h"

class RightSideStrategyListView : public RightSideStrategy
{
public:
    RightSideStrategyListView();

    void update(GroupStrategyResult groupStrategyResult) final;
};

#endif // RIGHTSIDESTRATEGYLISTVIEW_H
