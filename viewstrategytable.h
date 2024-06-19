#ifndef VIEWSTRATEGYTABLE_H
#define VIEWSTRATEGYTABLE_H

#include "viewstrategy.h"

class ViewStrategyTable : public ViewStrategy
{
public:
    ViewStrategyTable();

    void adaptAndApplyData(QStandardItemModel *model, GroupStrategyResult result) final;
};

#endif // VIEWSTRATEGYTABLE_H
