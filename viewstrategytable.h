#ifndef VIEWSTRATEGYTABLE_H
#define VIEWSTRATEGYTABLE_H

#include "viewstrategy.h"

class ViewStrategyTable : public ViewStrategy
{
public:
    ViewStrategyTable();

    void setAsCurrent();
    void unsetAsCurrent();
    void update(GroupStrategyResult groupStrategyResult);
};

#endif // VIEWSTRATEGYTABLE_H
